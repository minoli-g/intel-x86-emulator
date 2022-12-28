#include "cmp.hpp"
#include "../modrm.hpp"
#include "../instr_utils.hpp"

void cmp_3C(InputReader* ir, RegisterBank* rb, Memory* mem){

}

void cmp_3D(InputReader* ir, RegisterBank* rb, Memory* mem){

}

void cmp_38(InputReader* ir, RegisterBank* rb, Memory* mem){

}

void cmp_39(InputReader* ir, RegisterBank* rb, Memory* mem){

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