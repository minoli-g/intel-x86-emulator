#include "or.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void or_0C(InputReader* ir, RegisterBank* rb, Memory* mem){

    // OR AL and imm8
    uint8_t al = rb->get("AL");
    uint8_t imm8 = getImm8(ir);

    rb->set("AL", al|imm8);
}

void or_0D(InputReader* ir, RegisterBank* rb, Memory* mem){

    // OR EAX and imm32
    uint32_t eax = rb->get("EAX");
    uint32_t imm32 = getImm32(ir);

    rb->set("EAX", eax|imm32);
}

void or_08(InputReader* ir, RegisterBank* rb, Memory* mem){

    // OR r/m8, r8
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        uint8_t result = rb->get(r8) | rb->get(rm8);
        rb->set(rm8, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r8) | mem->read(rm_mem);
        mem->write(rm_mem, result);
    }
}

void or_09(InputReader* ir, RegisterBank* rb, Memory* mem){

    // OR r/m32, r32
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint8_t result = rb->get(r32) | rb->get(rm32);
        rb->set(rm32, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r32) | mem->read(rm_mem);
        mem->write(rm_mem, result);
    }
}

void orOp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode) {
        case 0x0C:
            or_0C(ir, rb, mem);
            break;

        case 0x0D:
            or_0D(ir, rb, mem);
            break;

        case 0x08:
            or_08(ir, rb, mem);
            break;

        case 0x09:
            or_09(ir, rb, mem);
            break;

        default:
            std::cout<<"Unsupported AND opcode \n";
    }
}