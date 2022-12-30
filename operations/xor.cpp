#include "xor.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void xor_34(InputReader* ir, RegisterBank* rb, Memory* mem){

    //XOR AL, imm8
    uint8_t al = rb->get("AL");
    uint8_t imm8 = getImm8(ir);

    rb->set("AL", al^imm8);

    // Set flags - No overflow possible, so no need to cast to long
    setFlagGroup(al^imm8, 8, rb); 
}

void xor_35(InputReader* ir, RegisterBank* rb, Memory* mem){

    // XOR EAX, imm32
    uint32_t eax = rb->get("EAX");
    uint32_t imm32 = getImm32(ir);

    rb->set("EAX", eax^imm32);

    // Set flags
    setFlagGroup(eax^imm32, 32, rb);
}

void xor_30(InputReader* ir, RegisterBank* rb, Memory* mem){

    // XOR r/m8, r8
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        uint8_t result = rb->get(r8) ^ rb->get(rm8);
        rb->set(rm8, result);
        setFlagGroup(result, 8, rb);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r8) ^ mem->read(rm_mem);
        mem->write(rm_mem, result);
        setFlagGroup(result, 32, rb);
    }
}

void xor_31(InputReader* ir, RegisterBank* rb, Memory* mem){

    // XOR r/m32, r32
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint32_t result = rb->get(r32) ^ rb->get(rm32);
        rb->set(rm32, result);
        setFlagGroup(result, 32, rb);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r32) ^ mem->read(rm_mem);
        mem->write(rm_mem, result);
        setFlagGroup(result, 32, rb);
    }
}

void xorOp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode) {
        case 0x34:
            xor_34(ir, rb, mem);
            break;

        case 0x35:
            xor_35(ir, rb, mem);
            break;

        case 0x30:
            xor_30(ir, rb, mem);
            break;

        case 0x31:
            xor_31(ir, rb, mem);
            break;

        default:
            std::cout<<"Unsupported XOR opcode \n";
    }    
}