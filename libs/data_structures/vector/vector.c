#include <malloc.h>

#include "vector.h"

// Коммит второй

Vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "Wrong value: capacity");
        exit(1);
    }
    return (Vector) {
            data,
            0,
            n
    };
}

void reserve(Vector *v, size_t newCapacity) {
    if (newCapacity == 0) v->data = NULL;
    v->data = (int *) realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "Wrong value: newCapacity = %llu", newCapacity);
        exit(1);
    }
    v->capacity = newCapacity;
    if (newCapacity < v->size) v->size = newCapacity;
}

void clear(Vector *v) {
    v->size = 0;
}

void shrinkToFit(Vector *v) {
    v->capacity = v->size;
}

void deleteVector(Vector *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

// Коммит третий

bool isEmpty(Vector *v) {
    return v->size == 0;
}

bool isFull(Vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(Vector *v, size_t i) {
    return *(v->data + i);
}

void pushBack(Vector *v, int x) {
    if (v->capacity == 0) {
        v->capacity++;
    } else if (isFull(v)) {
        reserve(v, v->capacity * 2);
    }
    *(v->data + v->size++) = x;
}

void popBack(Vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
    v->size--;
}

// Коммит четвертый

int *atVector(Vector *v, size_t index) {
    if (index > v->size) {
        fprintf(stderr, "IndexError: a[%llu] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int *back(Vector *v) {
    return v->data + v->size - 1;
}

int *front(Vector *v) {
    return v->data;
}