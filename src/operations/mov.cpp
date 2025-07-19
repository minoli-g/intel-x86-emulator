#include "mov.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void mov_88(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "88 - MOV r/m8,r8 \n";
    uint8_t modrm = ir->nextByte();

    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        rb->set(rm8, rb->get(r8));
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        mem->write(rm_mem, rb->get(r8));
    }

    // No flags affected
}

void mov_89(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "89 - MOV r/m32,r32 \n";
    uint8_t modrm = ir->nextByte();

    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);

    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        rb->set(rm32, rb->get(r32));
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        mem->write(rm_mem, rb->get(r32));
    }

    // No flags affected
}

void mov_8A(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "8A - MOV r8,r/m8 \n";
    uint8_t modrm = ir->nextByte();
    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);
    uint8_t rm8;

    if (isRMReg(modrm)){
        rm8 = rb->get(getRMReg(modrm, REG_8));
    }
    else{
        rm8 = mem->read(getRMMemLocation(modrm, rb, ir));
    }
    rb->set(r8, rm8);

    // No flags affected
}

void mov_8B(InputReader* ir, RegisterBank* rb, Memory* mem){

    std::cout << "8B - MOV r32,r/m32 \n";
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);
    uint32_t rm32;

    if (isRMReg(modrm)){
        rm32 = rb->get(getRMReg(modrm, REG_32));
    }
    else{
        rm32 = mem->read(getRMMemLocation(modrm, rb, ir));
    }
    rb->set(r32, rm32);

    // No flags affected
}

void mov(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode) {
        case 0x88:
            mov_88(ir, rb, mem);
            break;

        case 0x89:
            mov_89(ir, rb, mem);
            break;

        case 0x8A:
            mov_8A(ir, rb, mem);
            break;

        case 0x8B:
            mov_8B(ir, rb, mem);
            break;

        default:
            std::cout<<"Unsupported MOV opcode \n";
    }
}