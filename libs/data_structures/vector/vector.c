#include "vector.h"

void bad_alloc(){
    fprintf(stderr, "bad alloc");
    exit(1);
}

vector createVector(size_t n){
    int *a = malloc(sizeof(int) * n);

    if (a == NULL)
        bad_alloc();
    return (vector) {(n == 0 ? NULL: a),0,n};
}

bool isEmpty(vector *v){
    return v->size == 0 ? true: false;
}

bool isFull(vector *v) {
    return v->size == v->capacity ? true: false;
}

void reserve(vector *v, size_t newCapacity) {
    int *a = realloc(v->data, v->capacity);
    if (a == NULL)
        bad_alloc();
    if (newCapacity == 0)
        v->data = NULL;
    if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
    v->data = a;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}


int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if (isFull(v))
        reserve(v, v->capacity * 2 + 1);
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if(isEmpty(v))
        bad_alloc();
    v->size--;
}

int* atVector(vector *v, size_t index){
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }
    return &v->data[index];
}

int* back(vector *v){
    return &v->data[v->size - 1];
}

int* front(vector *v) {
    return v->data;
}