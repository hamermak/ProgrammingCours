#include <malloc.h>
#include <stdbool.h>
#include <memory.h>

#include "vectorVoid.h"

// Коммит второй

VectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    char *data = (char *) malloc(baseTypeSize * n);
    if (data == NULL) {
        fprintf(stderr, "Wrong value: capacity");
        exit(1);
    }
    return (VectorVoid) {
            data,
            0,
            n,
            baseTypeSize
    };
}

void reserveV(VectorVoid *v, size_t newCapacity) {
    if (newCapacity == 0) v->data = NULL;
    v->data = (void *) realloc(v->data, v->baseTypeSize * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "Wrong value: newCapacity = %llu", newCapacity);
        exit(1);
    }
    v->capacity = newCapacity;
    if (newCapacity < v->size) v->size = newCapacity;
}

void clearV(VectorVoid *v) {
    v->size = 0;
}

void shrinkToFitV(VectorVoid *v) {
    v->capacity = v->size;
}

void deleteVectorV(VectorVoid *v) {
    free(v->data);
    v->size = 0;
    v->capacity = 0;
}

//

bool isEmptyV(VectorVoid *v) {
    return v->size == 0;
}

bool isFullV(VectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(VectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(VectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
    if (index >= v->size) {
        fprintf(stderr, "Wrong value: index = %llu", index);
        exit(1);
    }
}

void popBackV(VectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }
    v->size--;
}

void pushBackV(VectorVoid *v, void *source) {
    if (v->capacity == 0) {
        v->capacity++;
    } else if (isFullV(v)) {
        reserveV(v, v->capacity * 2);
    }

    char *destination = (char *) v->data + v->size++ * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}