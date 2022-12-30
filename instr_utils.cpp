#include "instr_utils.hpp"
#include <bitset>

std::string reg_names_32bit[] = {"EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI" };

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

int8_t getImm8(InputReader* ir){
    int8_t ans = (int8_t) getDisp8(ir);
    // Imm data is signed - show it as a decimal with the sign
    std::cout << std::dec << "Read Imm8 data decimal value " << +ans <<"\n" << std::hex; 
    return ans;
}

int16_t getImm16(InputReader* ir){
    int16_t ans = (int16_t) getDisp16(ir);
    // Imm data is signed - show it as a decimal with the sign
    std::cout << std::dec << "Read Imm16 data decimal value " << +ans <<"\n" << std::hex;
    return ans;
}

int32_t getImm32(InputReader* ir){
    int32_t ans = (int32_t) getDisp8(ir);
    // Imm data is signed - show it as a decimal with the sign
    std::cout << std::dec << "Read Imm32 data decimal value " << +ans <<"\n" << std::hex;
    return ans;
}

uint32_t getSIBMemLocation(uint8_t sib, RegisterBank* rb, uint8_t mod, InputReader* ir){

    int scale = sib >> 6;
    int index = (sib>>3)&7;
    int base = sib&7;

    uint32_t base_value = 0;
    if (base == 5 && mod == 0){
        base_value = getDisp32(ir);
    }
    else {
        base_value = rb->get(reg_names_32bit[base]);
    }

    uint32_t scaled_value = 0;
    if (index != 4){
        scaled_value += rb->get(reg_names_32bit[index]) * (1<<scale);
    }
    
    std::cout << "Effective addr of SIB byte "<<+sib<<" is "<< +(base_value + scaled_value) <<"\n";
    return base_value + scaled_value; 
}

void setFlagGroup(long long int value, int size, RegisterBank* rb){

    // Check the value and size of its allocated space, and set flags accordingly
    // Flags affected - CF, OF, SF, ZF, PF

    long long int max_unsigned_val = (1<<size)-1;      // Fill with ones, read as unsigned positive
    long long int min_signed_val = 1-((max_unsigned_val+1)/2);    // E.g.: 255 to -127

    if (value > max_unsigned_val){ 
        rb->setFlag("CF");
        rb->clearFlag("OF");
    }
    else if (value < min_signed_val){
        rb->setFlag("OF");
        rb->clearFlag("CF");
    }
    else {
        rb->clearFlag("CF");
        rb->clearFlag("OF");
    }

    if (value>0){
        rb->clearFlag("SF");
        rb->clearFlag("ZF");
    }
    else if (value<0){
        rb->setFlag("SF");
        rb->clearFlag("ZF");
    }
    else {
        rb->setFlag("ZF");
    }

    uint8_t lsb = value & 0xFF;
    std::bitset<8> b(lsb);
    int parity = 0;
    for (int i=0; i<8; i++){
        if (b[i]==1){ parity++; }
    }
    if (parity%2==0){
        rb->setFlag("PF");
    }
    else {
        rb->clearFlag("PF");
    }
}