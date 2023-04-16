#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

#include <stdio.h>
#include <stdbool.h>

#define SIZE_MAX 500000

// Коммит второй

typedef struct vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

Vector createVector(size_t n);

void reserve(Vector *v, size_t newCapacity);

void clear(Vector *v);

void shrinkToFit(Vector *v);

void deleteVector(Vector *v);

// Коммит третий

bool isEmpty(Vector *v);

bool isFull(Vector *v);

int getVectorValue(Vector *v, size_t i);

void pushBack(Vector *v, int x);

void popBack(Vector *v);

// Коммит четвертый

int *atVector(Vector *v, size_t index);

int *back(Vector *v);

int *front(Vector *v);

#endif //VECTORS_VECTOR_H
