#include "simulator.h"



std::array<uint32_t, 32> Simulator::run(std::ifstream& rf, bool print_reg) {
    uint32_t pc = 0;
    std::array<uint32_t, 32> reg = std::array<uint32_t, 32>();

    //Simulation loop
    while (!rf.eof()) {    
        // Continously read 32 bits from file into instr.
        uint32_t instr;
        rf.read((char *) &instr, sizeof(instr));

        // Decode the instruction
        uint32_t opcode = instr & 0x7f;
        uint32_t rd = (instr >> 7) & 0x01f;
        uint32_t rs1 = (instr >> 15) & 0x01f;
        uint32_t rs2 = (instr >> 20) & 0x01f;
        uint32_t imm = (instr >> 20);
        uint32_t uimm = (instr >> 12);
        uint32_t funct3 = (instr >> 12) & 0x7;
        uint32_t funct7 = (instr >> 25);

        // extend with 1's if necessary.
        if (imm & (1 << 11)) {
            imm |= 0xFFFFF000;
        }
        // TODO: Handle exits
        switch (opcode) { // TODO: Add upper immideate AUIPC
            case 0b0010011: 
                switch (funct3) {
                    case 0b000: // addi
                        reg[rd] = reg[rs1] + imm;
                        break;

                    case 0b001: //slli
                        reg[rd] = reg[rs1] << imm;
                        break;

                    case 0b010: //slti
                        reg[rd] = (int32_t) reg[rs1] < (int32_t) imm;
                        break;

                    case 0b011: //sltiu
                        reg[rd] = reg[rs1] < imm;
                        break;

                    case 0b100: // xori
                        reg[rd] = reg[rs1] ^ imm;
                        break;

                    case 0b101: 
                        switch (funct7) {
                            case 0b0000000: //srli
                                reg[rd] = reg[rs1] >> imm;
                                break;
                            
                            case 0b0100000: //srai
                                reg[rd] = (int32_t) reg[rs1] >> imm;
                                break;
                        }
                        break;

                    case 0b110: //ori
                        reg[rd] = reg[rs1] | imm;
                        break;

                    case 0b111: //andi
                        reg[rd] = reg[rs1] & imm;
                        break;
                }
                break;
                
            case 0b0110011: 
                switch (funct3) {
                    case 0b000:
                        switch (funct7) {
                            case 0b0000000: // add
                                reg[rd] = reg[rs1] + reg[rs2];
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
            case 0b0110111: // lui
                reg[rd] = ((int32_t) uimm) << 12;
            case 0b1110011: // ecall
                if (reg[17] == 10) {
                    return reg;
                }
                break;
            default:
                std::cout << "Opcode " << opcode << " not yet implemented" << std::endl;
                break;
        }

        pc += 4; // One instruction is four bytes

        /*if ((pc >> 2) >= progr.size()) {
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

