#include "add.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void add_00(InputReader* ir, RegisterBank* rb, Memory* mem){

    // 00/r - Add r8 to r/m8
    uint8_t modrm = ir->nextByte();

    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);
    uint8_t op1 = rb->get(r8);
    uint32_t op2;

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        op2 = rb->get(rm8);
        rb->set(rm8, (op1+op2));
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        op2 = mem->read(rm_mem);
        mem->write(rm_mem, (op1+op2));
    }

    // Set flags
    long long int temp = (long long int)op1 + (long long int)op2;
    setFlagGroup(temp, 8, rb);
}

void add_01(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add r32 to r/m32
    uint8_t modrm = ir->nextByte();

    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);
    uint32_t op1 = rb->get(r32);
    uint32_t op2;

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        op2 = rb->get(rm32);
        rb->set(rm32, (op1+op2));
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        op2 = mem->read(rm_mem);
        mem->write(rm_mem, (op1+op2));
    }

    // Set flags 
    long long int temp = (long long int)op1 + (long long int)op2;
    setFlagGroup(temp, 32, rb);
}

void add_02(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add r/m8 to r8
    uint8_t modrm = ir->nextByte();

    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);
    uint32_t op1;
    uint8_t op2 = rb->get(r8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        op1 = rb->get(rm8);
        rb->set(r8, (op1+op2));
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        op1 = mem->read(rm_mem);
        rb->set(r8, (op1+op2));
    }

    // Set flags
    long long int temp = (long long int)op1 + (long long int)op2;
    setFlagGroup(temp, 8, rb);
}

void add_04(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add imm8 to AL.
    int8_t imm8 = getImm8(ir);
    uint8_t al = rb->get("AL");
    rb->set("AL", (uint8_t) (al+imm8));

    // Set flags
    long long int temp = (long long int)imm8 + (long long int)al;
    setFlagGroup(temp, 8, rb);
}

void add_83(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add imm8 to r/m32.
    uint8_t modrm = ir->nextByte();
    int8_t imm8;
    uint32_t op2;

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        op2 = rb->get(rm32);
        imm8 = getImm8(ir);
        rb->set(rm32, (imm8+op2));
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        op2 = mem->read(rm_mem);
        imm8 = getImm8(ir);
        mem->write(rm_mem, (imm8+op2));
    }

    // Set flags 
    long long int temp = (long long int)imm8 + (long long int)op2;
    setFlagGroup(temp, 32, rb);
}

void add(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode) {
        case 0x00:
            add_00(ir, rb, mem);
            break;

        case 0x01:
            add_01(ir, rb, mem);
            break;

        case 0x02:
            add_02(ir, rb, mem);
            break;

        case 0x04:
            add_04(ir, rb, mem);
            break;

        case 0x83:
            add_83(ir, rb, mem);
            break;

        default:
            std::cout<<"Unsupported addition opcode \n";
    }
}