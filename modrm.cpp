#include "modrm.hpp"

uint8_t getModRM(InputReader* ir){
    return ir->nextByte();
}

uint8_t getMod(uint8_t modrm){
    return (uint8_t) (modrm>>6);
}

uint8_t getReg(uint8_t modrm){
    return (uint8_t) ((modrm>>3)&7);
}

uint8_t getRM(uint8_t modrm){
    return (uint8_t) (modrm&7);
}