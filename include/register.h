class Register {
    std::array<uint32_t, 32> reg = std::array<uint32_t, 32>();
public:
    void set(int index, uint32_t word) {
        if (index != 0) {
            this->reg[index] = word;
        }
    };
    uint32_t get(int index) {
        return this->reg[index];
    };

    size_t size() {
        return 32;
    }
    std::array<uint32_t, 32> get() {
        return reg;
    }

    void print() {
        for (int i = 0; i < this->size() / 4; i++) {
                for (int j = 0; j < 4; j++) {
                    std::cout << std::dec << "x" <<  i * 4 + j ;
                    if (i * 4 + j < 10)
                        std::cout << " ";
                    std::cout << " = 0x" << std::hex << std::setfill('0') << std::setw(8) <<  this->get(i * 4 + j) << ",\t";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl; 
    }

};