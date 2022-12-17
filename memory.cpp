#include "memory.hpp"
#include <iostream>

Memory::Memory(){
    memory_map = {};
}

uint32_t Memory::read(uint32_t address){
    if (memory_map.count(address)){
        return memory_map[address];
    }
    std::cout << "Error: attempted to read from invalid memory location \n";
    exit(0);
}

void Memory::write(uint32_t address, uint32_t data) {
    memory_map[address] = data;
}