#include "vector.h"

struct Vector {
    int length;
    char elements[][255];
} vector;

void pushItem(struct Vector* v, char i[]) {
    struct Vector newVec;
    newVec.length = v->length + 1;
    for (int i = 0; i < sizeof(v->elements)/sizeof(v->elements[0]); i++) {

    }
}