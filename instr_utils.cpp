#include "instr_utils.hpp"

std::string regs_32bit[] = {"EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI" };

uint8_t getDisp8(InputReader* ir){
    return ir->nextByte();
}

uint16_t getDisp16(InputReader* ir){
    uint16_t disp16 = 0;

    // Concatenate the next 2 bytes
    disp16 |= (ir->nextByte()) << 8;
    disp16 |= ir->nextByte();

    return disp16;
}

uint32_t getDisp32(InputReader* ir){
    uint32_t disp32 = 0;

    // Concatenate the 4 bytes following
    for (int i=3; i>=0; i--){
        disp32 |= (ir->nextByte()) << 8*i;
    }
    return disp32;
}

uint32_t getSIBMemLocation(uint8_t sib, RegisterBank* rb, uint8_t mod, InputReader* ir){

    int scale = sib >> 6;
    int index = (sib>>3)&7;
    int base = sib&7;

    uint32_t base_value = 0;
    if (base != 4){
        base_value = rb->get(regs_32bit[base]);
    }
    else {
        switch (mod){
            case 0: 
                base_value = getDisp32(ir);
                break;
            case 1:
                base_value = getDisp8(ir) + rb->get("EBP");
                break;
            case 2:
                base_value = getDisp32(ir) + rb->get("EBP");
                break;    
        }
    }

    uint32_t scaled_value = 0;
    if (index != 5){
        scaled_value += rb->get(regs_32bit[index]) * (1<<scale);
    }

    return base_value + scaled_value; 
}