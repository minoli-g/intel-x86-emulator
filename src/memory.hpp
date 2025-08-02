#ifndef MEMORY_H
#define MEMORY_H

#include "register.hpp"
#include <cstdint>
#include <unordered_map>

using MEMORY_MAP = std::unordered_map <uint32_t, uint32_t>;

class Memory {

    private:
        MEMORY_MAP memory_map;
    
    public:
        Memory();
        uint32_t read(uint32_t address);
        void write(uint32_t address, uint32_t data);
        void push_stack(uint32_t data, RegisterBank* rb, int size);
        uint32_t pop_stack(RegisterBank* rb, int size);
        void dumpValues();

        const MEMORY_MAP& getMemoryLayout() { return memory_map; }
};

#endif