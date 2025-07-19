#include "modrm.hpp"
#include "register.hpp"
#include "input_reader.hpp"
#include "instr_utils.hpp"

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

std::string getRegFromIndex(uint8_t index, enum RegisterTypes reg_type){
    switch (reg_type){
        case REG_8:
            return regs_8bit[index];

        case REG_16:
            return regs_16bit[index];

        case REG_32:
            return regs_32bit[index];

        default:
            std::cout << "Unsupported register type \n";
            exit(0);
    }
}

bool isRMReg(uint8_t modrm){
    return (getMod(modrm)==3);
}

std::string getRMReg(uint8_t modrm, enum RegisterTypes reg_type){
    int index = getRM(modrm);
    return getRegFromIndex(index, reg_type);
}

uint32_t getRMMemLocation(uint8_t modrm, RegisterBank* rb, InputReader* ir){

    uint8_t mod = getMod(modrm);
    uint8_t rm = getRM(modrm);

    if (mod==0){
        switch (rm){

            case 4: {
                uint8_t sib = ir->nextByte();
                return getSIBMemLocation(sib, rb, mod, ir);
            }
            case 5:
                return getDisp32(ir);

            default:
                return rb->get(regs_32bit[rm]);
        }
    }
    if (mod==1){
        switch (rm){

            case 4: {
                uint8_t sib = ir->nextByte();
                uint8_t disp8 = ir->nextByte();
                return getSIBMemLocation(sib, rb, mod, ir) + disp8;
            }
            default:
                uint8_t disp8 = ir->nextByte();
                return rb->get(regs_32bit[rm]) + disp8;
        }
    }
    if (mod==2){
        switch (rm){

            case 4: {
                uint8_t sib = ir->nextByte();
                uint8_t disp32 = getDisp32(ir);
                return getSIBMemLocation(sib, rb, mod, ir) + disp32;
            }
            default:
                uint32_t disp32 = getDisp32(ir);
                return rb->get(regs_32bit[rm]) + disp32;
        }
    }
    else {
        std::cout << "Error: Memory location requested but operand is a register";
        exit(0);
    }
}