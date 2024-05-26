uint32_t reverseBits(uint32_t n) {
    for (int i = 0; i<16; ++i) {
        uint32_t leftBit = (n >> i) & 1;
        uint32_t rightBit = (n >> (31 - i)) & 1;
        if (leftBit != rightBit) {
            n ^= (1U << i); //reverse i-th bit from left
            n ^= (1U << (31 - i)); //reverse i-th bit from right 
        }
    }
    return n;
}
