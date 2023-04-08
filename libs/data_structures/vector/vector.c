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
    int *a = malloc(sizeof(int) * n);
    if (a == NULL)
        bad_alloc();
    if (newCapacity == 0)
        v->data = NULL;
    if (newCapacity < v->size)
        v->size = newCapacity;
    v->capacity = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v){
    v->capacity = v->size;
}

void deleteVector(vector *v) {
    free(v->data);
}