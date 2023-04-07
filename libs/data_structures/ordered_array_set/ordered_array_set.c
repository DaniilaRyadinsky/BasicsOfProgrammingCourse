#include "ordered_array_set.h"
#include "..\..\algorithms\array\array.h"

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {malloc(sizeof(int) * capacity),
                                0,
                                capacity
    };
}

static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

// возвращает множество, состоящее из элементов массива a размера size
ordered_array_set ordered_array_set_create_from_array(const int *a, size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);
    return set;
}

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t ordered_array_set_in(ordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’24
bool ordered_array_set_isEqual(ordered_array_set set1, ordered_array_set set2) {
    if (set1.size == set2.size) {
        for (int i = 0; i < set1.size; ++i)
            if (set1.data[i] != set2.data[i])
                return false;
        return true;
    }
    return false;
}

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’25
bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    int j = 0; //индексы массива а
    for (int i = 0; i < set.size; ++i) {
        if (set.data[i] == subset.data[j])
            j++;
    }
    if (j == subset.size)
        return true;
    return false;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert (set->size < set->capacity);
}

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_array_set *set, int value) {
    if (ordered_array_set_in(set, value) == set->size) {
        ordered_array_set_isAbleAppend(set);
        int pos = binarySearchMoreOrEqual_(set->data, set->size, value);
        if (pos == set->size)
            append_(set->data, &set->size, value);
        else {
            insert_(set->data, &set->size, pos, value);
        }
    }
}

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t pos = ordered_array_set_in(set, value);
    if (pos != set->size)
        deleteByPosSaveOrder_(set->data, &set->size, pos);
}

// возвращает объединение множеств set1 и set2
ordered_array_set ordered_array_set_union(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set c = ordered_array_set_create(set1.size + set2.size);
    int i = 0;
    int j = 0;
    while (i < set1.size || j < set2.size) {
        if (i == set1.size) {
            ordered_array_set_insert(&c, set2.data[j]);
            j++;
        }
        else if (j == set2.size) {
            ordered_array_set_insert(&c, set1.data[i]);
            i++;
        }
        else if (set1.data[i] < set2.data[j]) {
            ordered_array_set_insert(&c, set1.data[i]);
            i++;
        }
        else if (set1.data[i] == set2.data[j]) {
            ordered_array_set_insert(&c, set1.data[i]);
            i++;
            j++;
        }
        else {
            ordered_array_set_insert(&c, set2.data[j]);
            j++;
        }
    }
    ordered_array_set_shrinkToFit(&c);
    return c;
}

// возвращает пересечение множеств set1 и set2
ordered_array_set ordered_array_set_intersection(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set c = ordered_array_set_create(set1.size + set2.size);
    size_t i = 0; // индексы массива А
    size_t j = 0; // индексы массива В
    while (i < set1.size || j < set2.size) {
        if (i == set1.size) {
            j++;
        } else if (j == set2.size) {
            i++;
        } else if (set1.data[i] < set2.data[j]) {
            i++;
        } else if (set1.data[i] == set2.data[j]) {
            ordered_array_set_insert(&c, set1.data[i]);
            i++;
            j++;
        } else {
            j++;
        }
    }
    ordered_array_set_shrinkToFit(&c);
    return c;
}

// возвращает разность множеств set1 и set2
ordered_array_set ordered_array_set_difference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set c = ordered_array_set_create(set1.size + set2.size);
    size_t i = 0; // индексы массива А
    size_t j = 0; // индексы массива В
    while (i < set1.size && j < set2.size) {
        if (set1.data[i] < set2.data[j] || j == set2.size) { // если элемент из А меньше
            ordered_array_set_insert(&c, set1.data[i]);
            i++; // прибавляем индекс
        } else if (set1.data[i] == set2.data[j]) {
            i++; // прибавляем индекс
            j++;
        } else {
            j++; // прибавляем индекс
        }
    }
    ordered_array_set_shrinkToFit(&c);
    return c;
}

// возвращает симметрическую разность множеств set1 и set2
ordered_array_set ordered_array_set_symmetricDifference(ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set c = ordered_array_set_create(set1.size + set2.size);
    size_t i = 0; // индексы массива А
    size_t j = 0; // индексы массива В
    while (i < set1.size || j < set2.size) {
        if (i == set1.size) { // если список А будет рассмотрен быстрее, будет добавляться только список В
            ordered_array_set_insert(&c, set2.data[j]);
            j++;
        } else if (j == set2.size) { // если список В будет рассмотрен быстрее, будет добавляться только список А
            ordered_array_set_insert(&c, set1.data[i]);
            i++;
        } else if (set1.data[i] < set2.data[j]) { // если элемент из А меньше
            ordered_array_set_insert(&c, set1.data[i]);
            i++; // прибавляем индекс
        } else if (set1.data[i] == set2.data[j]) {
            i++; // прибавляем индекс
            j++;
        } else {
            ordered_array_set_insert(&c, set2.data[j]);
            j++; // прибавляем индекс
        }
    }
    ordered_array_set_shrinkToFit(&c);
    return c;
}

// возвращает дополнение до универсума universumSet множества set
ordered_array_set ordered_array_set_complement(ordered_array_set set, ordered_array_set universumSet) {
    ordered_array_set c = ordered_array_set_create(set.capacity);
    for (int i = 0; i < universumSet.size; ++i) {
        if (ordered_array_set_in(&set, universumSet.data[i]) == set.size)
            ordered_array_set_insert(&c, universumSet.data[i]);
    }
    ordered_array_set_shrinkToFit(&c);
    return c;
}

// вывод множества set
void ordered_array_set_print(ordered_array_set set) {
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

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_array_set set) {
    free(set.data);
}
