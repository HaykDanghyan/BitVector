#ifndef BITVECTOR_H
#define BITVECTOR_H

#include <iostream>
#include <vector>

class BitVector {
public:
    BitVector();
    BitVector(size_t);
    ~BitVector();

public:
    const static size_t bitCount = 64;
    void clear();
    size_t size() const;
    bool get(size_t) const;
    void set(size_t, bool);
    std::string to_string() const;
    
public:
    friend std::ostream& operator<<(std::ostream& os, const BitVector& v) {
        for (int i = v.bits.size() - 1; i >= 0; --i) {
            int byte = i / bitCount;
            int bit = i % bitCount;
            std::cout << bool(v.bits[byte] & (1 << bit)) << " ";
        }
        return os;
    }

private:
    std::vector<size_t> bits;
};

#endif // BITVECTOR_H