#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>
#include <unordered_map>

class Memory {

    private:
        std::unordered_map <uint32_t, uint32_t> memory_map;
    
    public:
        Memory();
        uint32_t read(uint32_t address);
        void write(uint32_t address, uint32_t data);
        void dumpValues();

};

#endif