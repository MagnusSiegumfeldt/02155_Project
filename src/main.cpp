#include <iostream>
#include <cstdint>
#include <fstream>

#include "simulator.h"

int main(void) {
    std::ifstream binary("../test/test_cases/task1/AddLarge.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, false);
    
    std::ofstream res("../out.res", std::ios::out | std::ios::binary);
    if(!res) {
      std::cout << "Cannot open file!" << std::endl;
      return 1;
    }
    for (int i = 0; i < reg.size(); i++) {
        res.write((char *) &reg[i], sizeof(reg[i]));
    }
    return 0;
}
