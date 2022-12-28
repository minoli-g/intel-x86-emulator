#ifndef REGISTER_H
#define REGISTER_H

#include <cstdint>
#include <string>
#include <map>

class RegisterBank {

    private:

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