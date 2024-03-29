#include "and.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void and_24(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "24 - AND AL and imm8 \n";
    uint8_t al = rb->get("AL");
    uint8_t imm8 = getImm8(ir);

    rb->set("AL", al&imm8);

    // Set flags - No overflow possible, so no need to cast to long
    setFlagGroup(al&imm8, 8, rb); 
}

void and_25(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "25 - AND EAX and imm32 \n";
    uint32_t eax = rb->get("EAX");
    uint32_t imm32 = getImm32(ir);

    rb->set("EAX", eax&imm32);

    // Set flags
    setFlagGroup(eax&imm32, 32, rb);
}

void and_20(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "20 - AND r/m8, r8 \n";
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        uint8_t result = rb->get(r8) & rb->get(rm8);
        rb->set(rm8, result);
        setFlagGroup(result, 8, rb);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r8) & mem->read(rm_mem);
        mem->write(rm_mem, result);
        setFlagGroup(result, 32, rb);
    }
}

void and_21(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "21 - AND r/m32, r32 \n";
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint8_t result = rb->get(r32) & rb->get(rm32);
        rb->set(rm32, result);
        setFlagGroup(result, 32, rb);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r32) & mem->read(rm_mem);
        mem->write(rm_mem, result);
        setFlagGroup(result, 32, rb);
    }
}
void and_22(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "22 - AND r8, r/m8 \n";
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);
    uint8_t rm8;

    if (isRMReg(modrm)){
        rm8 = rb->get(getRMReg(modrm, REG_8));
    }
    else{
        rm8 = mem->read(getRMMemLocation(modrm, rb, ir));
    }
    uint8_t result = rb->get(r8)&rm8;
    rb->set(r8, result);
    setFlagGroup(result, 8, rb);
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