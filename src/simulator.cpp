#include "simulator.h"



std::array<uint32_t, 32> Simulator::run(std::ifstream& rf, bool print_reg) {
    uint32_t pc = 0;
    std::array<uint32_t, 32> reg = std::array<uint32_t, 32>();
    //Register reg = Register(); 
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

        //std::cout << "PC: " << pc << ", instr: " << instr << std::endl;

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
        // TODO: Handle exits
        switch (opcode) {
            case 0b0000011:
                switch(funct3){
                    case 0b000: // lb
                        {
                            uint32_t byte = (uint32_t) mem[reg[rs1] + i_imm];
                            if (byte & (1 << 7)) { // sign ext.
                                byte |= 0xFFFFFF00;
                            }
                            reg[rd] = byte;
                        }
                        break;
                
                    case 0b001: //lh
                        {
                            uint32_t byte1 = (uint32_t) mem[reg[rs1] + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg[rs1] + i_imm + 1] << 8;
                            uint32_t word = byte1 | byte2;
                            if (word & (1 << 15)) {
                                word |= 0xFFFF0000;
                            }
                            reg[rd] = word;
                        }
                        break;
                    
                    case 0b010: // lw
                        {
                            uint32_t byte1 = (uint32_t) mem[reg[rs1] + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg[rs1] + i_imm + 1] << 8;
                            uint32_t byte3 = (uint32_t) mem[reg[rs1] + i_imm + 2] << 16;
                            uint32_t byte4 = (uint32_t) mem[reg[rs1] + i_imm + 3] << 24;
                            reg[rd] = byte1 | byte2 | byte3 | byte4;
                        }
                        break;

                    case 0b100: // lbu
                        {
                            uint32_t byte = (uint32_t) mem[reg[rs1] + i_imm];
                            reg[rd] = byte;
                        }
                        break;
                    case 0b101: // lhu
                        {
                            uint32_t byte1 = (uint32_t) mem[reg[rs1] + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg[rs1] + i_imm + 1] << 8;
                            reg[rd] = byte1 | byte2;
                        }
                        break;
                    case 0b110: // lwu
                        {
                            uint32_t byte1 = (uint32_t) mem[reg[rs1] + i_imm];
                            uint32_t byte2 = (uint32_t) mem[reg[rs1] + i_imm + 1] << 8;
                            uint32_t byte3 = (uint32_t) mem[reg[rs1] + i_imm + 2] << 16;
                            uint32_t byte4 = (uint32_t) mem[reg[rs1] + i_imm + 3] << 24;
                            reg[rd] = byte1 | byte2 | byte3 | byte4;
                        }
                        break;
                }
                break;
            case 0b0010011: 
                switch (funct3) {   
                    case 0b000: // addi
                        if (rd != 0) {
                            reg[rd] = reg[rs1] + i_imm;
                        }
                        break;

                    case 0b001: //slli
                        reg[rd] = reg[rs1] << i_imm;
                        break;

                    case 0b010: //slti
                        reg[rd] = (int32_t) reg[rs1] < (int32_t) i_imm;
                        break;

                    case 0b011: //sltiu
                        reg[rd] = reg[rs1] < i_imm;
                        break;

                    case 0b100: // xori
                        reg[rd] = reg[rs1] ^ i_imm;
                        break;

                    case 0b101: 
                        switch (funct7) {
                            case 0b0000000: //srli
                                reg[rd] = reg[rs1] >> i_imm;
                                break;
                            
                            case 0b0100000: //srai
                                reg[rd] = (int32_t) reg[rs1] >> i_imm;
                                break;
                        }
                        break;

                    case 0b110: //ori
                        reg[rd] = reg[rs1] | i_imm;
                        break;

                    case 0b111: //andi
                        reg[rd] = reg[rs1] & i_imm;
                        break;
                }
                break;
            case 0b0010111: // auipc
                reg[rd] = pc + u_imm;
                break;
            case 0b0110011: 
                switch (funct3) {
                    case 0b000:
                        switch (funct7) {
                            case 0b0000000: // add
                                if (rd != 0) {
                                    reg[rd] = reg[rs1] + reg[rs2];    
                                }
                                break;
                            case 0b0100000: // sub
                                reg[rd] = reg[rs1] - reg[rs2];
                                break;
                        }
                        break;
                    case 0b001: // sll // TODO: negative numbers (uint32_t??)??
                        reg[rd] = reg[rs1] << reg[rs2];
                        break;
                    case 0b010: // slt
                        reg[rd] = (int32_t) reg[rs1] < (int32_t) reg[rs2];
                        break;
                    case 0b011: // sltu
                        reg[rd] = reg[rs1] < reg[rs2];
                        break;
                    case 0b100: // xor
                        reg[rd] = reg[rs1] ^ reg[rs2];
                        break;
                    case 0b101: 
                        reg[rd] = 0;
                        switch (funct7) {
                            case 0b0000000: // srl
                                reg[rd] = reg[rs1] >> reg[rs2];
                                break;
                            
                            case 0b0100000: // sra
                                reg[rd] = ((int32_t) reg[rs1]) >> reg[rs2];
                                break;
                        }
                        break;
                    case 0b110: // or
                        reg[rd] = reg[rs1] | reg[rs2];
                        break;
                    case 0b111: // and
                        reg[rd] = reg[rs1] & reg[rs2];
                        break;
                }
                break;
            
            case 0b0100011: 
                switch(funct3) {
                    case 0b000: //sb 
                        mem[reg[rs1] + s_imm] = (uint8_t) reg[rs2];
                        break;
                    
                    case 0b001: //sh
                        mem[reg[rs1] + s_imm] = (uint8_t) reg[rs2];
                        mem[reg[rs1] + s_imm + 1] = (uint8_t) (reg[rs2] >> 8);
                        std::cout << "Put " << unsigned((uint8_t) reg[rs2]) << " into " << reg[rs1] + s_imm << " and put "<<unsigned((uint8_t) (reg[rs2] >> 8)) << " into " << reg[rs1] + s_imm + 1 << std::endl;
                        break;

                    case 0b010: //sw
                        mem[reg[rs1] + s_imm] = (uint8_t) reg[rs2];
                        mem[reg[rs1] + s_imm + 1] = (uint8_t) (reg[rs2] >> 8);
                        mem[reg[rs1] + s_imm + 2] = (uint8_t) (reg[rs2] >> 16);
                        mem[reg[rs1] + s_imm + 3] = (uint8_t) (reg[rs2] >> 24);
                        break;
                }
                break;
            
            
            case 0b0110111: // lui
                reg[rd] = u_imm;
                break;
            case 0b1100011:
                switch(funct3) {
                    case 0b000: // beq
                        if (reg[rs1] == reg[rs2]) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                    case 0b001: // bne
                        if (reg[rs1] != reg[rs2]) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                    case 0b100: // blt
                        if((int32_t) reg[rs1] < (int32_t) reg[rs2]) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                    case 0b101: // bge
                        if((int32_t) reg[rs1] >= (int32_t) reg[rs2]) {
                            pc += b_imm;
                            branch_flag = true;
                        }    
                        break;
                    case 0b110: // bltu
                        if(reg[rs1] < reg[rs2]) {
                            pc += b_imm;
                            branch_flag = true;
                        }    
                        break;
                    case 0b111: // bgeu
                        if(reg[rs1] >= reg[rs2]) {
                            pc += b_imm;
                            branch_flag = true;
                        }
                        break;
                }
                break;
            case 0b1100111: // jalr
                if (rd != 0) {
                    reg[rd] = pc + 4;
                }
                pc = reg[rs1] + i_imm;
                branch_flag = true;
                break;
            case 0b1101111: // jal
                if (rd != 0) {
                    reg[rd] = pc + 4;
                }
                pc += j_imm;
                branch_flag = true;
                break;
            case 0b1110011: // ecall // TODO : Some of these are missing
                std::cout << "in ecall" << std::endl;
                if (reg[17] == 10 || reg[10] == 10) {
                    std::cout << "exiting" << std::endl;
                    return reg;
                }
                break;
            default:
                std::cout << "Opcode " << opcode << " not yet implemented" << std::endl;
                return reg;
                break;
        }

        if (!branch_flag) {
            pc += 4; // One instruction is four bytes
        }

        /*if ((pc >> 2) >= progr.size()) { // TODO: Consider this
            break;
        }*/

        if (print_reg) {
            for (int i = 0; i < reg.size(); i++) {
                std::cout << reg[i] << " ";
            }
            std::cout << std::endl;    
        }
        
    }

    /*std::cout << "Program exit" << std::endl;
    for (size_t i(0); i < reg.size(); ++i) {
        std::cout << reg[i] << " ";
    }*/
    return reg;
}

