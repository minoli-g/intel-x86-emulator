#include "bsr.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

#include <bitset>

void bsr_BD(InputReader* ir, RegisterBank* rb, Memory* mem){
    
    // Bit scan reverse on r/m32.
    uint8_t modrm = ir->nextByte();
    
    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint32_t operand = rb->get(rm32);
        std::bitset<32> b(operand);

        for (int i=0; i<b.size(); i++){
            if (b[i]){
                // Set ZF to 0
                rb->set(rm32, (uint32_t)i);
                return;
            }
        }
        // Set ZF to 1
        return;
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t operand = mem->read(rm_mem);
        std::bitset<32> b(operand);

        for (int i=0; i<b.size(); i++){
            if (b[i]){
                // Set ZF to 0
                mem->write(rm_mem, (uint32_t)i);
                return;
            }
        }
        // Set ZF to 1
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