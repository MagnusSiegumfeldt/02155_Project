#include <catch2/catch_test_macros.hpp>
#include <string>

#include "simulator.h"

TEST_CASE("Instr - add") {
    std::ifstream binary("../test/test_cases/instructions/test_add.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_add.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - addi") {
    std::ifstream binary("../test/test_cases/instructions/test_addi.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_addi.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - and") {
    std::ifstream binary("../test/test_cases/instructions/test_and.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_and.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - andi") {
    std::ifstream binary("../test/test_cases/instructions/test_andi.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_andi.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - auipc") {
    std::ifstream binary("../test/test_cases/instructions/test_auipc.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_auipc.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - beq") {
    std::ifstream binary("../test/test_cases/instructions/test_beq.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_beq.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - bge") {
    std::ifstream binary("../test/test_cases/instructions/test_bge.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_bge.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - bgeu") {
    std::ifstream binary("../test/test_cases/instructions/test_bgeu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_bgeu.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - blt") {
    std::ifstream binary("../test/test_cases/instructions/test_blt.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_blt.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - bltu") {
    std::ifstream binary("../test/test_cases/instructions/test_bltu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_bltu.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - bne") {
    std::ifstream binary("../test/test_cases/instructions/test_bne.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_bne.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - div") {
    std::ifstream binary("../test/test_cases/instructions/test_div.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_div.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - divu") {
    std::ifstream binary("../test/test_cases/instructions/test_divu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_divu.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Instr - ecall") {
    std::ifstream binary("../test/test_cases/instructions/test_ecall.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_ecall.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - jal") {
    std::ifstream binary("../test/test_cases/instructions/test_jal.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_jal.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - jalr") {
    std::ifstream binary("../test/test_cases/instructions/test_jalr.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_jalr.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - lb") {
    std::ifstream binary("../test/test_cases/instructions/test_lb.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_lb.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - lbu") {
    std::ifstream binary("../test/test_cases/instructions/test_lbu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_lbu.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - lh") {
    std::ifstream binary("../test/test_cases/instructions/test_lh.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_lh.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - lhu") {
    std::ifstream binary("../test/test_cases/instructions/test_lhu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_lhu.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - li") {
    std::ifstream binary("../test/test_cases/instructions/test_li.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_li.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - lui") {
    std::ifstream binary("../test/test_cases/instructions/test_lui.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_lui.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - lw") {
    std::ifstream binary("../test/test_cases/instructions/test_lw.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_lw.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - mul") {
    std::ifstream binary("../test/test_cases/instructions/test_mul.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_mul.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - mulh") {
    std::ifstream binary("../test/test_cases/instructions/test_mulh.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_mulh.res", std::ios::in | std::ios::binary);
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


TEST_CASE("Instr - mulhsu") {
    std::ifstream binary("../test/test_cases/instructions/test_mulhsu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_mulhsu.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - mulhu") {
    std::ifstream binary("../test/test_cases/instructions/test_mulhu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_mulhu.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - or") {
    std::ifstream binary("../test/test_cases/instructions/test_or.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_or.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - ori") {
    std::ifstream binary("../test/test_cases/instructions/test_ori.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_ori.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - rem") {
    std::ifstream binary("../test/test_cases/instructions/test_rem.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_rem.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - remu") {
    std::ifstream binary("../test/test_cases/instructions/test_remu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_remu.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - sb") {
    std::ifstream binary("../test/test_cases/instructions/test_sb.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sb.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - sh") {
    std::ifstream binary("../test/test_cases/instructions/test_sh.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sh.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - sll") {
    std::ifstream binary("../test/test_cases/instructions/test_sll.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sll.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - slli") {
    std::ifstream binary("../test/test_cases/instructions/test_slli.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_slli.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - slt") {
    std::ifstream binary("../test/test_cases/instructions/test_slt.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_slt.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - slti") {
    std::ifstream binary("../test/test_cases/instructions/test_slti.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_slti.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - sltiu") {
    std::ifstream binary("../test/test_cases/instructions/test_sltiu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sltiu.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - sltu") {
    std::ifstream binary("../test/test_cases/instructions/test_sltu.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sltu.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - sra") {
    std::ifstream binary("../test/test_cases/instructions/test_sra.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sra.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - srai") {
    std::ifstream binary("../test/test_cases/instructions/test_srai.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_srai.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - srl") {
    std::ifstream binary("../test/test_cases/instructions/test_srl.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_srl.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - srli") {
    std::ifstream binary("../test/test_cases/instructions/test_srli.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_srli.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - sub") {
    std::ifstream binary("../test/test_cases/instructions/test_sub.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sub.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - sw") {
    std::ifstream binary("../test/test_cases/instructions/test_sw.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_sw.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - xor") {
    std::ifstream binary("../test/test_cases/instructions/test_xor.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_xor.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - xori") {
    std::ifstream binary("../test/test_cases/instructions/test_xori.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_xori.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - random1") {
    std::ifstream binary("../test/test_cases/instructions/test_random1.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random1.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - random2") {
    std::ifstream binary("../test/test_cases/instructions/test_random2.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random2.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - random3") {
    std::ifstream binary("../test/test_cases/instructions/test_random3.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random3.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - random4") {
    std::ifstream binary("../test/test_cases/instructions/test_random4.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random4.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - random5") {
    std::ifstream binary("../test/test_cases/instructions/test_random5.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random5.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - random6") {
    std::ifstream binary("../test/test_cases/instructions/test_random6.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random6.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - random7") {
    std::ifstream binary("../test/test_cases/instructions/test_random7.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random7.res", std::ios::in | std::ios::binary);
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
TEST_CASE("Instr - random8") {
    std::ifstream binary("../test/test_cases/instructions/test_random8.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random8.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - random9") {
    std::ifstream binary("../test/test_cases/instructions/test_random9.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random9.res", std::ios::in | std::ios::binary);
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

TEST_CASE("Instr - random10") {
    std::ifstream binary("../test/test_cases/instructions/test_random10.bin", std::ios::in | std::ios::binary);
    if(!binary) {
        REQUIRE(false);
    }
    std::ifstream res("../test/test_cases/instructions/test_random10.res", std::ios::in | std::ios::binary);
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











