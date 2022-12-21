#include "bsf.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void bsf_BC(InputReader* ir, RegisterBank* rb, Memory* mem){
    
};
    
void bsf(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode){
        case 0xBC:
            bsf_BC(ir, rb, mem);
            return;
        default:
            std::cout<<"Unsupported BSF operand \n";
            return;
    }
}