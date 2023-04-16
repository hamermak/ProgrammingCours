#ifndef VECTOR_VECTORVOID_H
#define VECTOR_VECTORVOID_H

#include <stdio.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} VectorVoid;

VectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(VectorVoid *v, size_t newCapacity);

void clearV(VectorVoid *v);

void shrinkToFitV(VectorVoid *v);

void deleteVectorV(VectorVoid *v);

//

bool isEmptyV(VectorVoid *v);

bool isFullV(VectorVoid *v);

void getVectorValueV(VectorVoid *v, size_t index, void *destination);

void setVectorValueV(VectorVoid *v, size_t index, void *source);

void popBackV(VectorVoid *v);

void pushBackV(VectorVoid *v, void *source);

#endif //VECTOR_VECTORVOID_H
