#include "add.hpp"
#include "../modrm.hpp"

void add_00(InputReader* ir){

    // 00/r - Add r8 to r/m8

    uint8_t modrm = ir->nextByte();
    uint8_t r8 = getReg(modrm);
    uint8_t rm8 = getRM(modrm);

    std::cout<< "Adding value of Register "<< std::to_string(r8) 
    << " to value of Register " << std::to_string(rm8) << "\n";
}

void add(InputReader* ir, std::vector<uint8_t> incoming_opcodes){
    switch (incoming_opcodes[0]) {
        case 0x00:
            add_00(ir);
            break;

        default:
            std::cout<<"Add error \n";
    }
}