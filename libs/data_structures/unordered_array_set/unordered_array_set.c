#include "unordered_array_set.h"
#include "C:\Users\dikij\CLionProjects\lab15\libs\algorithms\array\array.h"

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void unordered_array_set_delete(unordered_array_set set) {
    free(set.data);
}

static void unordered_array_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

void unordered_array_isAbleAppend(unordered_array_set *set) {
    assert(set->size < set->capacity);
}

size_t unordered_array_set_in(unordered_array_set set, int value) {
    return linearSearch_(set.data, set.size, value);
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {malloc(sizeof(int) * capacity),
                                  0,
                                  capacity
    };
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(*set, value) == set->size) {
        unordered_array_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}


unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    return set;
}


bool unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}


bool unordered_array_set_isSubset(unordered_array_set subset, unordered_array_set set) {
    int count = 0; // заводим счетчик повторений
    for (int i = 0; i < subset.size; ++i) {
        for (int j = 0; j < set.size; ++j) {
            if (subset.data[i] == set.data[j]) // если элемент найден - прибавляем счетчик
                count++;
        }
    }
    if (count == subset.size) // сравниваем счетчик с количеством элементов в А
        return true;
    else
        return false;
}


// удаляет элемент value из множества set
void unordered_array_set_deleteElement(unordered_array_set *set, int value) {
    size_t pos = linearSearch_(set->data, set->size, value);
    if (pos != set->size) {
        set->data[pos] = set->data[set->size - 1];
        (set->size)--;
    }
    unordered_array_shrinkToFit(set);
}

// возвращает объединение множеств set1 и set2
unordered_array_set unordered_array_set_union(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set c = unordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; ++i) // копируем массив А полностью
        unordered_array_set_insert(&c, set1.data[i]);
    for (int i = 0; i < set2.size; ++i) { // копируем В без повторений
        for (int j = 0; j < set1.size; ++j) {
            if (set2.data[i] == set1.data[j]) // равные числа отсекаем
                break;
            else if (j == set1.size - 1)
                unordered_array_set_insert(&c, set2.data[i]);
        }
    }
    unordered_array_shrinkToFit(&c);
    return c;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set c = unordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; ++i) {
        for (int j = 0; j < set2.size; ++j) {
            if (set1.data[i] == set2.data[j]) { // если есть совпадающие элементы - добавляем в С
                unordered_array_set_insert(&c, set1.data[i]);
            }
        }
    }
    unordered_array_shrinkToFit(&c);
    return c;
}

// возвращает разность множеств set1 и set2
unordered_array_set unordered_array_set_difference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set c = unordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; ++i) {
        for (int j = 0; j < set2.size; ++j) {
            if (set1.data[i] == set2.data[j]) {
                break;
            } else if (j == set2.size - 1) { // если счетчик дошел до последнего элемента и числа не равны
                unordered_array_set_insert(&c, set1.data[i]);
            }
        }
    }
    unordered_array_shrinkToFit(&c);
    return c;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set unordered_array_set_symmetricDifference(unordered_array_set set1, unordered_array_set set2) {
    unordered_array_set c = unordered_array_set_create(set1.size + set2.size);
    for (int i = 0; i < set1.size; ++i) { //обрабатываем массив А
        for (int j = 0; j < set2.size; ++j) {
            if (set1.data[i] == set2.data[j]) {
                break;
            } else if (j == set1.size - 1) { //если счетчик дошел до последнего элемента и числа не равны
                unordered_array_set_insert(&c, set1.data[i]);
            }
        }
    }
    for (int i = 0; i < set2.size; ++i) { //обрабатываем массив В
        for (int j = 0; j < set1.size; ++j) {
            if (set2.data[i] == set1.data[j]) {
                break;
            } else if (j == set1.size - 1) { //если счетчик дошел до последнего элемента и числа не равны
                unordered_array_set_insert(&c, set2.data[i]);
            }
        }
    }
    unordered_array_shrinkToFit(&c);
    return c;
}

// возвращает дополнение до универсума множества set
unordered_array_set unordered_array_set_complement(unordered_array_set set, unordered_array_set universumSet) {
    unordered_array_set c = unordered_array_set_create(set.capacity);
    for (int i = 0; i < universumSet.size; ++i) {
        if (unordered_array_set_in(set, universumSet.data[i]) == set.size)
            unordered_array_set_insert(&c, universumSet.data[i]);
    }
    unordered_array_shrinkToFit(&c);
    return c;
}

// вывод множества set
void unordered_array_set_print(unordered_array_set set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i < set.size; ++i) {
        printf("%d, ", set.data[i]);
        isEmpty = 0;
    }

    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}

