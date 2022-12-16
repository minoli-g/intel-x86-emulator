#include "instr_utils.hpp"

uint32_t getDisp32(InputReader* ir){
    uint32_t disp32 = 0;

    // Concatenate the 4 bytes following
    for (int i=3; i>=0; i--){
        disp32 |= (ir->nextByte()) << 8*i;
    }
    return disp32;
}

uint32_t getSIBMemLocation(uint8_t sib){
    //TODO
    return 0; 
}