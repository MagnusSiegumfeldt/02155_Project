#include <iostream>
#include <cstdint>
#include <fstream>

#include "simulator.h"

#define NO_ERR 0;

int main(void) {
    std::ifstream rf("../test/test_cases/task1/shift2.bin", std::ios::in | std::ios::binary);
    if(!rf) {
        std::cout << "Cannot open file!" << std::endl;
        return 1;
    }
    Simulator::run(rf, true);
    return NO_ERR;
}
