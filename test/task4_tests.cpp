#include <catch2/catch_test_macros.hpp>
#include <string>

#include "simulator.h"

TEST_CASE("Part 4 - t1") {
    std::ifstream binary("../test/test_cases/task4/t1.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t1.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Part 4 - t2") {
    std::ifstream binary("../test/test_cases/task4/t2.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t2.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t3") {
    std::ifstream binary("../test/test_cases/task4/t3.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t3.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t4") {
    std::ifstream binary("../test/test_cases/task4/t4.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t4.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t5") {
    std::ifstream binary("../test/test_cases/task4/t5.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t5.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t6") {
    std::ifstream binary("../test/test_cases/task4/t6.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t6.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t7") {
    std::ifstream binary("../test/test_cases/task4/t7.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t7.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t8") {
    std::ifstream binary("../test/test_cases/task4/t8.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t8.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t9") {
    std::ifstream binary("../test/test_cases/task4/t9.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t9.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t10") {
    std::ifstream binary("../test/test_cases/task4/t10.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t10.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t11") {
    std::ifstream binary("../test/test_cases/task4/t11.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t11.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t12") {
    std::ifstream binary("../test/test_cases/task4/t12.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t12.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t13") {
    std::ifstream binary("../test/test_cases/task4/t13.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t13.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t14") {
    std::ifstream binary("../test/test_cases/task4/t14.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t14.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Part 4 - t15") {
    std::ifstream binary("../test/test_cases/task4/t15.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/task4/t15.res", std::ios::in | std::ios::binary);
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
