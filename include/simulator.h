#include <iostream>
#include <array>
#include <cstdint>
#include <fstream>
#include <vector>
#include <iomanip>


#include "register.h"

class Simulator {
public:
    static std::array<uint32_t, 32> run(std::ifstream&, bool);
};