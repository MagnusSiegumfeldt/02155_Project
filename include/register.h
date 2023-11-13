class Register {
    std::array<uint32_t, 32> reg = std::array<uint32_t, 32>();
public:
    void set(int index, uint32_t word) {
        this->reg[index] = word;
    };
    uint32_t get(int index) {
        return this->reg[index];
    };
};