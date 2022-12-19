#include "add.hpp"
#include "../modrm.hpp"

void add_00(InputReader* ir, RegisterBank* rb, Memory* mem){

    // 00/r - Add r8 to r/m8
    uint8_t modrm = ir->nextByte();
    std::cout<< +getMod(modrm) << +getRM(modrm) <<"\n";

    std::string r8 = getRegFromIndex(getReg(modrm), REG_8);

    if (isRMReg(modrm)){
        std::string rm8 = getRMReg(modrm, REG_8);
        uint8_t result = rb->get(r8)+ rb->get(rm8);
        rb->set(r8, result);
    }
    else{
        uint32_t rm_mem = getRMMemLocation(modrm, rb, ir);
        uint32_t result = rb->get(r8) + mem->read(rm_mem);
        mem->write(rm_mem, result);
    }

    // Set flags - TODO
}

void add(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode){
    switch (opcode) {
        case 0x00:
            add_00(ir, rb, mem);
            break;

        default:
            std::cout<<"Add error \n";
    }
}