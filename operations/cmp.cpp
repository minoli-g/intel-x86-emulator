#include "cmp.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void cmp_3C(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Compare AL, imm8
    uint8_t al = rb->get("AL");
    int8_t imm8 = getImm8(ir);

    long long int temp = (long long int)al - (long long int)imm8;
    setFlagGroup(temp, 8, rb);
}

void cmp_3D(InputReader* ir, RegisterBank* rb, Memory* mem){

    // Compare EAX and imm32
    uint32_t eax = rb->get("EAX");
    int32_t imm32 = getImm32(ir);

    long long int temp = (long long int)eax - (long long int)imm32;
    setFlagGroup(temp, 32, rb);
}

void cmp_38(InputReader* ir, RegisterBank* rb, Memory* mem){

    // compare r/m8, r8
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        long long int temp = (long long int)(rb->get(rm8)) - (long long int)(rb->get(r8));
        setFlagGroup(temp, 8, rb);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        long long int temp = (long long int)(mem->read(rm_mem)) - (long long int)(rb->get(r8));
        setFlagGroup(temp, 32, rb);
    }
}

void cmp_39(InputReader* ir, RegisterBank* rb, Memory* mem){

    // compare r/m32, r32
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_8);
        long long int temp = (long long int)(rb->get(rm32)) - (long long int)(rb->get(r32));
        setFlagGroup(temp, 32, rb);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        long long int temp = (long long int)(mem->read(rm_mem)) - (long long int)(rb->get(r32));
        setFlagGroup(temp, 32, rb);
    }
}

void cmp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode) {
        case 0x3C:
            cmp_3C(ir, rb, mem);
            break;

        case 0x3D:
            cmp_3D(ir, rb, mem);
            break;

        case 0x38:
            cmp_38(ir, rb, mem);
            break;

        case 0x39:
            cmp_39(ir, rb, mem);
            break;

        default:
            std::cout<<"Unsupported compare opcode \n";
    }
}