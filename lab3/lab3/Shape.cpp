#include "Shape.h"


Shape::Shape() {
    if (Count < 1000) {
        shapes[Count] = this;
        Count++;
    }
}

Shape::~Shape() {
    for (int i = 0; i < Count; i++) {
        if (shapes[i] == this) {
            for (int j = i; j < Count - 1; j++) {
                shapes[j] = shapes[j + 1];
            }
        }
    }
    Count--;
}


