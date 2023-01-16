#include "bsr.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

#include <bitset>

void bsr_BD(InputReader* ir, RegisterBank* rb, Memory* mem){
    
    std::cout << "BD - Bit scan reverse on r/m32, write to r32 \n";
    uint8_t modrm = ir->nextByte();
    std::string r32 = getRegFromIndex(getReg(modrm), REG_32);
    
    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint32_t operand = rb->get(rm32);
        std::bitset<32> b(operand);

        for (int i=b.size()-1; i>=0; i--){
            if (b[i]){
                // Set ZF to 0
                rb->clearFlag("ZF");
                rb->set(r32, (uint32_t)i);
                return;
            }
        }
        // Set ZF to 1
        rb->setFlag("ZF");
        return;
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t operand = mem->read(rm_mem);
        std::bitset<32> b(operand);

        for (int i=b.size()-1; i>=0; i--){
            if (b[i]){
                // Set ZF to 0
                rb->clearFlag("ZF");
                rb->set(r32, (uint32_t)i);
                return;
            }
        }
        // Set ZF to 1
        rb->setFlag("ZF");
        return;
    }
};
    
void bsr(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    // Find the most significant set bit
    
    switch (opcode){
        case 0xBD:
            bsr_BD(ir, rb, mem);
            return;
        default:
            std::cout<<"Unsupported BSR operand \n";
            return;
    }
}