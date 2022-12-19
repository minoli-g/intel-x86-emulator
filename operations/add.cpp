#include "add.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void add_00(InputReader* ir, RegisterBank* rb, Memory* mem){

    // 00/r - Add r8 to r/m8
    uint8_t modrm = ir->nextByte();

    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        uint8_t result = rb->get(r8)+ rb->get(rm8);
        rb->set(rm8, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r8) + mem->read(rm_mem);
        mem->write(rm_mem, result);
    }

    // Set flags - TODO
}

void add_01(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add r32 to r/m32
    uint8_t modrm = ir->nextByte();

    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint32_t result = rb->get(r32)+ rb->get(rm32);
        rb->set(rm32, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r32) + mem->read(rm_mem);
        mem->write(rm_mem, result);
    }

    // Set flags - TODO
}

void add_02(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add r/m8 to r8
    uint8_t modrm = ir->nextByte();

    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        uint8_t result = rb->get(r8)+ rb->get(rm8);
        rb->set(r8, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint8_t result = (uint8_t) (rb->get(r8) + mem->read(rm_mem));
        rb->set(r8, result);
    }

    // Set flags - TODO
}

void add_04(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add imm8 to AL.
    uint8_t imm8 = getImm8(ir);
    uint32_t al = rb->get("AL");
    rb->set("AL", al+imm8);

    // Set flags - TODO
}

void add_83(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Add imm8 to r/m32.
    uint8_t modrm = ir->nextByte();
    uint8_t imm8 = getImm8(ir);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint32_t result = imm8 + rb->get(rm32);
        rb->set(rm32, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = imm8 + mem->read(rm_mem);
        mem->write(rm_mem, result);
    }

    // Set flags - TODO
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