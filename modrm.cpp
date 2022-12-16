#include "modrm.hpp"

std::string regs_32bit[] = {"EAX", "ECX", "EDX", "EBX", "ESP", "EBP", "ESI", "EDI" };
std::string regs_16bit[] = { "AX", "CX", "DX", "BX", "SP", "BP", "SI", "DI" };
std::string regs_8bit[] = { "AL", "CL", "DL", "BL", "AH", "CH", "DH", "BH" };
//std::string regs_mmx[] = { "MM0", "MM1", "MM2", "MM3", "MM4", "MM5", "MM6", "MM7" };
//std::string regs_xmm[] = { "XMM0", "XMM1", "XMM2", "XMM3", "XMM4", "XMM5", "XMM6", "XMM7" };

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

bool isRMReg(uint8_t modrm){
    return (getMod(modrm)==11);
}

std::string getRMReg(uint8_t modrm, enum RegisterTypes reg_type){
    int index = getRM(modrm);

    switch (reg_type){
        case REG_8:
            return regs_8bit[index];
            break;

        case REG_16:
            return regs_16bit[index];
            break;

        case REG_32:
            return regs_32bit[index];
            break;

        default:
            std::cout << "Unsupported register type \n";
    }
}

uint32_t getRMMemLocation(uint8_t modrm){
    
}