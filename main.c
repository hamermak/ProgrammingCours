#include <assert.h>
#include <malloc.h>

#include "C:\Program Files\JetBrains\CLion 2023.1.1\libs\data_structures\vector\vector.h"
#include "C:\Program Files\JetBrains\CLion 2023.1.1\libs\data_structures\vector\vectorVoid.h"


void test_pushBack_emptyVector() {
    Vector v = createVector(0);
    assert(isEmpty(&v));

    pushBack(&v, 1);
    assert(v.data[0] == 1 && v.capacity == 1 && v.size == 1);

    reserve(&v, 0);
    pushBack(&v, 7);
    assert(v.data[0] == 7 && v.capacity == 1 && v.size == 1);

    reserve(&v, 0);
    pushBack(&v, 42);
    assert(v.data[0] == 42 && v.capacity == 1 && v.size == 1);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    Vector v = createVector(0);
    assert(isFull(&v));

    pushBack(&v, 1);
    assert(v.data[0] == 1 && v.capacity == 1 && v.size == 1);

    pushBack(&v, 42);
    assert(v.data[1] == 42 && v.capacity == 2 && v.size == 2);

    pushBack(&v, 42);
    pushBack(&v, 100500);
    assert(v.data[3] == 100500 && v.capacity == 4 && v.size == 4);

    pushBack(&v, -100500);
    assert(v.data[4] == -100500 && v.capacity == 8 && v.size == 5);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    pushBack(&v, -720);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_nonEmptyVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);

    assert(&v.data[0] == atVector(&v, 0));

    pushBack(&v, 42);
    assert(v.size == 2);

    assert(&v.data[1] == atVector(&v, 1));

    pushBack(&v, 505);
    pushBack(&v, 702);
    assert(v.size == 4);

    assert(&v.data[2] == atVector(&v, 2));

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    pushBack(&v, 13);

    assert(v.size == 4);
    assert(&v.data[3] == atVector(&v, 3));

    pushBack(&v, 13);
    assert(&v.data[4] == atVector(&v, 4));

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    pushBack(&v, 13);

    assert(v.size == 4);
    assert(&v.data[3] == back(&v));

    pushBack(&v, 13);
    assert(&v.data[4] == back(&v));

    popBack(&v);
    assert(&v.data[3] == back(&v));

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    Vector v = createVector(0);
    pushBack(&v, 10);
    pushBack(&v, 11);
    pushBack(&v, 12);
    pushBack(&v, 13);

    assert(v.size == 4);
    assert(&v.data[0] == front(&v));

    pushBack(&v, 13);
    assert(&v.data[0] == front(&v));

    popBack(&v);
    assert(&v.data[0] == front(&v));

    reserve(&v, 2);
    assert(&v.data[0] == front(&v));

    deleteVector(&v);
}

//

void test_pushBackV_emptyVector() {
    VectorVoid v = createVectorV(0, sizeof(char));
    assert(isEmptyV(&v));

    char a = 'a';
    pushBackV(&v, &a);
    char a1;
    getVectorValueV(&v, 0, &a1);
    assert(a1 == a && v.capacity == 1 && v.size == 1);

    char b = 'b';
    reserveV(&v, 0);
    pushBackV(&v, &b);
    getVectorValueV(&v, 0, &a1);
    assert(a1 == b && v.capacity == 1 && v.size == 1);

    char c = 'c';
    reserveV(&v, 0);
    pushBackV(&v, &c);
    getVectorValueV(&v, 0, &a1);
    assert(a1 == c && v.capacity == 1 && v.size == 1);

    deleteVectorV(&v);
}

void test_pushBackV_fullVector() {
    VectorVoid v = createVectorV(0, sizeof(float));
    assert(isFullV(&v));

    float a = 0.123f;
    pushBackV(&v, &a);
    float a1;
    getVectorValueV(&v, 0, &a1);
    assert(a1 == a && v.capacity == 1 && v.size == 1);

    float b = 0.132f;
    pushBackV(&v, &b);
    getVectorValueV(&v, 1, &a1);
    assert(a1 == b && v.capacity == 2 && v.size == 2);

    float c = 0.213f;
    float d = 0.231f;
    pushBackV(&v, &c);
    pushBackV(&v, &d);
    getVectorValueV(&v, 2, &a1);
    assert(a1 == c && v.capacity == 4 && v.size == 4);

    float e = -150.150f;
    pushBackV(&v, &e);
    getVectorValueV(&v, 4, &a1);
    assert(a1 == e && v.capacity == 8 && v.size == 5);

    deleteVectorV(&v);
}

void test_popBackV_notEmptyVector() {
    VectorVoid v = createVectorV(0, sizeof(int));
    int a = 10;
    pushBackV(&v, &a);

    assert(v.size == 1);
    popBackV(&v);
    assert(v.size == 0 && v.capacity == 1);

    int b = -820;
    pushBackV(&v, &b);

    assert(v.size == 1);
    popBackV(&v);
    assert(v.size == 0 && v.capacity == 1);

    deleteVectorV(&v);
}

void test_setVectorValueV_nonEmptyVector() {
    VectorVoid v = createVectorV(SIZE_MAX, sizeof(unsigned long long));
    unsigned long long a = 1000000000000;
    pushBackV(&v, &a);
    unsigned long long b = 755;
    setVectorValueV(&v, 0, &b);
    assert(v.size == 1);

    unsigned long long a1;
    getVectorValueV(&v, 0, &a1);
    assert(b == a1);

    unsigned long long c = 100500;
    setVectorValueV(&v, 0, &c);
    assert(v.size == 1);

    getVectorValueV(&v, 0, &a1);
    assert(c == a1);

    deleteVectorV(&v);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_nonEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_pushBackV_emptyVector();
    test_pushBackV_fullVector();
    test_popBackV_notEmptyVector();
    test_setVectorValueV_nonEmptyVector();
}

int main() {
    test();

    return 0;
}
