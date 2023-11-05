#include <iostream>
#include <array>
#include <cstdint>
#include <fstream>


class Simulator {
public:
    static std::array<uint32_t, 32> run(std::ifstream&);

};