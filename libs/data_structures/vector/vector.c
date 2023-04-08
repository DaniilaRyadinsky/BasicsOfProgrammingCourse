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

void reserve(vector *v, size_t newCapacity) {
    int *a = malloc(sizeof(int) * newCapacity);
    if (a == NULL)
        bad_alloc();
    if (newCapacity == 0)
        v->data = NULL;
    if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
    v->data = realloc(v->data, v->capacity);
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

bool isEmpty(vector *v){
    return v->size == 0 ? true: false;
}

bool isFull(vector *v) {
    return v->size == v->capacity ? true: false;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if (v->size == v->capacity)
        reserve(v, v->capacity * 2 + 1);
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if(isEmpty(v))
        bad_alloc();
    v->size--;
}