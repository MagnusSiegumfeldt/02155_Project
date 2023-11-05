#include <catch2/catch_test_macros.hpp>
#include <string>

#include "simulator.h"

TEST_CASE("Part 3 - Loop") {
    std::ifstream binary("../test/test_cases/task3/loop.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task3/loop.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}
TEST_CASE("Part 3 - Recursive") {
    std::ifstream binary("../test/test_cases/task3/recursive.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task3/recursive.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}
TEST_CASE("Part 3 - String") {
    std::ifstream binary("../test/test_cases/task3/string.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task3/string.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}

TEST_CASE("Part 3 - Width") {
    std::ifstream binary("../test/test_cases/task3/width.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task3/width.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}







