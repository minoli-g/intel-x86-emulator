#include "bsf.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

#include <bitset>

void bsf_BC(InputReader* ir, RegisterBank* rb, Memory* mem){
    
    // Bit scan forward on r/m32.
    uint8_t modrm = ir->nextByte();
    
    if (isRMReg(modrm)){
        std::string rm32 = getRMReg(modrm, REG_32);
        uint32_t operand = rb->get(rm32);
        std::bitset<32> b(operand);

        for (int i=b.size()-1; i>=0; i--){
            if (b[i]){
                // Set ZF to 0
                rb->clearFlag("ZF");
                rb->set(rm32, (uint32_t)i);
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
                mem->write(rm_mem, (uint32_t)i);
                return;
            }
        }
        // Set ZF to 1
        rb->setFlag("ZF");
        return;
    }
};
    
void bsf(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    // Find the least significant set bit
    
    switch (opcode){
        case 0xBC:
            bsf_BC(ir, rb, mem);
            return;
        default:
            std::cout<<"Unsupported BSF operand \n";
            return;
    }
}