#include "simulator.h"


std::array<uint32_t, 32> Simulator::run(std::ifstream& rf, bool print_reg) {
    uint32_t pc = 0;
    
    Register reg = Register(); 
    std::array<uint8_t, 1048576> mem = std::array<uint8_t, 1048576>();

    std::vector<uint32_t> instructions;
    int counter = 0;
    while(!rf.eof()) {
        uint8_t byte;
        rf.read((char *) &byte, sizeof(byte));
        mem[counter] = byte;
        counter++;
    }

    //Simulation loop
    while (true) { // Todo: comeback
        uint32_t instr = (uint32_t) mem[pc] | ((uint32_t) mem[pc + 1] << 8) | ((uint32_t) mem[pc + 2] << 16) | ((uint32_t) mem[pc + 3] << 24);

        printf("PC: %03x, instr: %08x \n", pc, instr);

        // Decode the instruction
        uint32_t opcode = instr & 0x7f;
        uint32_t rd = (instr >> 7) & 0x01f;
        uint32_t rs1 = (instr >> 15) & 0x01f;
        uint32_t rs2 = (instr >> 20) & 0x01f;

        uint32_t i_imm = (instr >> 20);
        uint32_t u_imm = (instr >> 12) << 12;
        uint32_t b_imm = (((instr >> 8) & 0x0F) << 1) | (((instr >> 25) & 0x3F) << 5) | (((instr >> 7) & 0x01) << 11) | (((instr >> 31) & 0x01) << 12);
        uint32_t s_imm = (((instr >> 25) & 0x7f) << 5) | ((instr >> 7) & 0x1f);
        uint32_t j_imm = ((instr >> 31) << 20) | (((instr >> 21) & 0x3FF) << 1) | (((instr >> 20) & 0x1) << 11) | (((instr >> 12) & 0xFF) << 12);

        uint32_t funct3 = (instr >> 12) & 0x7;
        uint32_t funct7 = (instr >> 25);

        // extend with 1's if necessary.
        if (i_imm & (1 << 11)) {
            i_imm |= 0xFFFFF000;
        }
        if (s_imm & (1 << 11)) {
            s_imm |= 0xFFFFF000;
        }
        if (b_imm & (1 << 12)) {
            b_imm |= 0xFFFFE000;
        }
        if (j_imm & (1 << 20)) {
            j_imm |= 0xFFE00000;
        }

        bool branch_flag = false;
        switch (opcode) {
            case 0b0000011:
                switch(funct3){
                    case 0b000: // lb
                        {
                            uint32_t byte = (uint32_t) mem[reg.get(rs1) + i_imm];
                            if (byte & (1 << 7)) { // sign ext.
                                byte |= 0xFFFFFF00;
                            }
                            reg.set(rd, byte);
                        }
                        break;
                
                    case 0b001: //lh
                        {
                            uint32_t byte1 = (uint32_t) mem[reg.get(rs1) + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg.get(rs1) + i_imm + 1] << 8;
                            uint32_t word = byte1 | byte2;
                            if (word & (1 << 15)) {
                                word |= 0xFFFF0000;
                            }
                            reg.set(rd, word);
                        }
                        break;
                    
                    case 0b010: // lw
                        {
                            uint32_t byte1 = (uint32_t) mem[reg.get(rs1) + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg.get(rs1) + i_imm + 1] << 8;
                            uint32_t byte3 = (uint32_t) mem[reg.get(rs1) + i_imm + 2] << 16;
                            uint32_t byte4 = (uint32_t) mem[reg.get(rs1) + i_imm + 3] << 24;
                            reg.set(rd, byte1 | byte2 | byte3 | byte4);
                        }
                        break;

                    case 0b100: // lbu
                        {
                            uint32_t byte = (uint32_t) mem[reg.get(rs1) + i_imm];
                            reg.set(rd, byte);
                        }
                        break;
                    case 0b101: // lhu
                        {
                            uint32_t byte1 = (uint32_t) mem[reg.get(rs1) + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg.get(rs1) + i_imm + 1] << 8;
                            reg.set(rd, byte1 | byte2);
                        }
                        break;
                    case 0b110: // lwu
                        {
                            uint32_t byte1 = (uint32_t) mem[reg.get(rs1) + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg.get(rs1) + i_imm + 1] << 8;
                            uint32_t byte3 = (uint32_t) mem[reg.get(rs1) + i_imm + 2] << 16;
                            uint32_t byte4 = (uint32_t) mem[reg.get(rs1) + i_imm + 3] << 24;
                            reg.set(rd, byte1 | byte2 | byte3 | byte4);
                        }
                        break;
                }
                break;
            case 0b0010011: 
                switch (funct3) {   
                    case 0b000: // addi
                        reg.set(rd, reg.get(rs1) + i_imm);
                        break;

                    case 0b001: //slli
                        reg.set(rd, reg.get(rs1) << i_imm);
                        break;

                    case 0b010: //slti
                        reg.set(rd, (int32_t) reg.get(rs1) < (int32_t) i_imm);
                        break;

                    case 0b011: //sltiu
                        reg.set(rd, reg.get(rs1) < i_imm); 
                        break;

                    case 0b100: // xori
                        reg.set(rd, reg.get(rs1) ^ i_imm);
                        break;

                    case 0b101: 
                        switch (funct7) {
                            case 0b0000000: //srli
                                reg.set(rd, reg.get(rs1) >> i_imm);
                                break;
                            
                            case 0b0100000: //srai
                                reg.set(rd, (int32_t) reg.get(rs1) >> i_imm);
                                break;
                        }
                        break;

                    case 0b110: //ori
                        reg.set(rd, reg.get(rs1) | i_imm);
                        break;

                    case 0b111: //andi
                        reg.set(rd, reg.get(rs1) & i_imm);
                        break;
                }
                break;
            case 0b0010111: // auipc
                reg.set(rd, pc + u_imm);
                break;
            case 0b0110011: 
                switch (funct3) {
                    case 0b000:
                        switch (funct7) {
                            case 0b0000000: // add
                                reg.set(rd, reg.get(rs1) + reg.get(rs2));
                                break;
                            case 0b0100000: // sub
                                reg.set(rd, reg.get(rs1) - reg.get(rs2));
                                break;
                        }
                        break;
                    case 0b001: // sll
                        reg.set(rd, reg.get(rs1) << reg.get(rs2));
                        break;
                    case 0b010: // slt
                        reg.set(rd, (int32_t) reg.get(rs1) < (int32_t) reg.get(rs2));
                        break;
                    case 0b011: // sltu
                        reg.set(rd, reg.get(rs1) < reg.get(rs2));
                        break;
                    case 0b100: // xor
                        reg.set(rd, reg.get(rs1) ^ reg.get(rs2));
                        break;
                    case 0b101: 
                        reg.set(rd, 0);
                        switch (funct7) {
                            case 0b0000000: // srl
                                reg.set(rd, reg.get(rs1) >> reg.get(rs2));
                                break;
                            
                            case 0b0100000: // sra
                                reg.set(rd, ((int32_t) reg.get(rs1)) >> reg.get(rs2));
                                break;
                        }
                        break;
                    case 0b110: // or
                        reg.set(rd, reg.get(rs1) | reg.get(rs2));
                        break;
                    case 0b111: // and
                        reg.set(rd, reg.get(rs1) & reg.get(rs2));
                        break;
                }
                break;
            
            case 0b0100011: 
                switch(funct3) {
                    case 0b000: //sb 
                        mem[reg.get(rs1) + s_imm] = (uint8_t) reg.get(rs2);
                        break;
                    
                    case 0b001: //sh
                        mem[reg.get(rs1) + s_imm] = (uint8_t) reg.get(rs2);
                        mem[reg.get(rs1) + s_imm + 1] = (uint8_t) (reg.get(rs2) >> 8);
                        break;

                    case 0b010: //sw
                        mem[reg.get(rs1) + s_imm] = (uint8_t) reg.get(rs2);
                        mem[reg.get(rs1) + s_imm + 1] = (uint8_t) (reg.get(rs2) >> 8);
                        mem[reg.get(rs1) + s_imm + 2] = (uint8_t) (reg.get(rs2) >> 16);
                        mem[reg.get(rs1) + s_imm + 3] = (uint8_t) (reg.get(rs2) >> 24);
                        break;
                }
                break;
            
            
            case 0b0110111: // lui
                reg.set(rd, u_imm);
                break;
            case 0b1100011:
                switch(funct3) {
                    case 0b000: // beq
                        if (reg.get(rs1) == reg.get(rs2)) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                    case 0b001: // bne
                        if (reg.get(rs1) != reg.get(rs2)) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                    case 0b100: // blt
                        if((int32_t) reg.get(rs1) < (int32_t) reg.get(rs2)) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                    case 0b101: // bge
                        if((int32_t) reg.get(rs1) >= (int32_t) reg.get(rs2)) {
                            pc += b_imm;
                            branch_flag = true;
                        }    
                        break;
                    case 0b110: // bltu
                        if(reg.get(rs1) < reg.get(rs2)) {
                            pc += b_imm;
                            branch_flag = true;
                        }    
                        break;
                    case 0b111: // bgeu
                        if(reg.get(rs1) >= reg.get(rs2)) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                }
                break;
            case 0b1100111: // jalr
                reg.set(rd, pc + 4);
                pc = reg.get(rs1) + i_imm;
                branch_flag = true;
                break;
            case 0b1101111: // jal
                reg.set(rd, pc + 4);
                pc += j_imm;
                branch_flag = true;
                break;
            case 0b1110011: // ecall // TODO : Some of these are missing
                if (reg.get(17) == 10 || reg.get(10) == 10) {
                    return reg.get();
                }
                break;
            default:
                std::cout << "Opcode " << opcode << " not yet implemented" << std::endl;
                return reg.get();
                break;
        }

        if (!branch_flag) {
            pc += 4; // One instruction is four bytes
        }

        if (print_reg) {
            for (int i = 0; i < reg.size(); i++) {
                std::cout << reg.get(i) << " ";
            }
            std::cout << std::endl;    
        }
        
    }

    return reg.get();
}

