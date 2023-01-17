#include <iostream>

#include "BitVector.h"

int main() {
    BitVector v;
    v.set(0, 1);
    v.set(1, 1);
    std::cout << v.to_string() << std::endl;
}