#include <iostream>
#include <cstdint>
#include <fstream>

#include "simulator.h"

#define NO_ERR 0;

int main(void) {
    std::ifstream binary("../test/test_cases/task1/AddLarge.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }
    Simulator::run(binary, false);
    return NO_ERR;
}
