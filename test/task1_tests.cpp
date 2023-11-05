#include <catch2/catch_test_macros.hpp>
#include <string>

#include "simulator.h"

TEST_CASE("Part 1 - Addlarge") {
    std::ifstream binary("../test/test_cases/task1/addlarge.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task1/addlarge.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, true);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}
TEST_CASE("Part 1 - Addneg") {
    std::ifstream binary("../test/test_cases/task1/addneg.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task1/addneg.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, true);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}
TEST_CASE("Part 1 - Addpos") {
    std::ifstream binary("../test/test_cases/task1/addpos.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task1/addpos.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, true);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}
TEST_CASE("Part 1 - Bool") {
    std::ifstream binary("../test/test_cases/task1/bool.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task1/bool.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, true);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}

TEST_CASE("Part 1 - Set") {
    std::ifstream binary("../test/test_cases/task1/set.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task1/set.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, true);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}
TEST_CASE("Part 1 - Shift") {
    std::ifstream binary("../test/test_cases/task1/shift.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task1/shift.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, true);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}
TEST_CASE("Part 1 - Shift2") {
    std::ifstream binary("../test/test_cases/task1/shift2.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task1/shift2.res", std::ios::in | std::ios::binary);
    if(!res) {
        REQUIRE(false);
    }
    
    std::array<uint32_t, 32> reg = Simulator::run(binary, true);
    
    for (int i = 0; i < 32; i++) {
        uint32_t val;
        res.read((char *) &val, sizeof(val));
        REQUIRE(reg[i] == val);
    }
}








