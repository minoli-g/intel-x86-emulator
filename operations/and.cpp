#include "and.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void and_24(InputReader* ir, RegisterBank* rb, Memory* mem){

    // AND AL and imm8
    uint8_t al = rb->get("AL");
    uint8_t imm8 = getImm8(ir);

    rb->set("AL", al&imm8);
}

void and_25(InputReader* ir, RegisterBank* rb, Memory* mem){

    // AND EAX and imm32
    uint32_t eax = rb->get("EAX");
    uint32_t imm32 = getImm32(ir);

    rb->set("EAX", eax&imm32);
}

void and_20(InputReader* ir, RegisterBank* rb, Memory* mem){

    // AND r/m8, r8
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        uint8_t result = rb->get(r8) & rb->get(rm8);
        rb->set(rm8, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r8) & mem->read(rm_mem);
        mem->write(rm_mem, result);
    }
}

void and_21(InputReader* ir, RegisterBank* rb, Memory* mem){

    // AND r/m32, r32
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint8_t result = rb->get(r32) & rb->get(rm32);
        rb->set(rm32, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r32) & mem->read(rm_mem);
        mem->write(rm_mem, result);
    }
}
void and_22(InputReader* ir, RegisterBank* rb, Memory* mem){

    // AND r8, r/m8
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);
    uint8_t rm8;

    if (isRMReg(modrm)){
        rm8 = rb->get(getRMReg(modrm, REG_8));
    }
    else{
        rm8 = mem->read(getRMMemLocation(modrm, rb, ir));
    }
    rb->set(r8, rb->get(r8)&rm8);
}


void andOp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode) {
        case 0x24:
            and_24(ir, rb, mem);
            break;

        case 0x25:
            and_25(ir, rb, mem);
            break;

        case 0x20:
            and_20(ir, rb, mem);
            break;

        case 0x21:
            and_21(ir, rb, mem);
            break;

        case 0x22:
            and_22(ir, rb, mem);
            break;

        default:
            std::cout<<"Unsupported AND opcode \n";
    }
}