#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>
#include <string>
#include <map>

class RegisterBank {

    private:

        // General registers

        std::uint32_t EAX;
        std::uint32_t EBX;
        std::uint32_t ECX;
        std::uint32_t EDX;

        std::uint16_t AX;
        std::uint16_t BX;
        std::uint16_t CX;
        std::uint16_t DX;
        
        std::uint8_t AH;
        std::uint8_t BH;
        std::uint8_t CH;
        std::uint8_t DH;
        
        std::uint8_t AL;
        std::uint8_t BL;
        std::uint8_t CL;
        std::uint8_t DL;

        // Index and pointers

        std::uint32_t ESI;
        std::uint32_t EDI;
        std::uint32_t EBP;
        std::uint32_t EIP;
        std::uint32_t ESP;

        // Segment registers

        std::uint16_t CS;
        std::uint16_t DS;
        std::uint16_t ES;
        std::uint16_t FS;
        std::uint16_t GS;
        std::uint16_t SS;

        // Indicator
        std::uint32_t EFLAGS;

        // Name-variable maps
        std::map<std::string, uint32_t> gen_32_regs;
        std::map<std::string, uint16_t> gen_16_regs;
        std::map<std::string, uint8_t> gen_8h_regs;
        std::map<std::string, uint8_t> gen_8l_regs;
        std::map<std::string, uint16_t> seg_regs;
        std::map<std::string, uint32_t> other_regs;

        // Flag-bit map
        std::map<std::string, uint8_t> flag_bits;

    public:
        RegisterBank();

        void set(std::string reg, uint32_t value); 
        std::uint32_t get(std::string reg);

        void setFlag(std::string flag);
        void clearFlag(std::string flag);
        bool getFlag(std::string flag);

        void dumpValues();

};

#endif