#ifndef MEMORY_H
#define MEMORY_H

#include "register.hpp"
#include <cstdint>
#include <unordered_map>

class Memory {

    private:
        std::unordered_map <uint32_t, uint32_t> memory_map;
    
    public:
        Memory();
        uint32_t read(uint32_t address);
        void write(uint32_t address, uint32_t data);
        void push_stack(uint32_t data, RegisterBank* rb, int size);
        uint32_t pop_stack(RegisterBank* rb, int size);
        void dumpValues();

};

#endif