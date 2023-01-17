#include "BitVector.h"

BitVector::BitVector() {

}

BitVector::~BitVector() {}

void BitVector::clear() {
    bits.clear();
}

void BitVector::set(size_t pos, bool bit1) {
    int zero = 0;
    int byte = pos / bitCount;
    int bit = pos % bitCount;

    for (int i = bits.size(); i <= byte; ++i) {
        bits.push_back(zero);
    }

    if (bit1) {
        bits[byte] |= (1 << bit);
        return;
    }

    int m = (1 << bit);
    m = ~m;
    bits[byte] &= m;
}

bool BitVector::get(size_t pos) const {
    int byte = pos / bitCount;
    int bit = pos % bitCount;

    return bits[byte] & (1 << bit);
}

std::string BitVector::to_string() const {
    std::string res;
    for (const auto& el : bits) {
        res += std::to_string(el);
    }
    return res;
}
