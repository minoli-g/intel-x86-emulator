#include "memory.hpp"
#include <iostream>

Memory::Memory(){
    memory_map = {};
}

uint32_t Memory::read(uint32_t address){
    if (memory_map.count(address)){
        return memory_map[address];
    }
    std::cout << std::hex 
            << "Error: attempted to read from invalid memory location "<< address <<"\n"
            << std::dec;
    exit(0);
}

void Memory::write(uint32_t address, uint32_t data) {
    memory_map[address] = data;
}

void Memory::dumpValues(){
    std::cout << "\n-------MEMORY DUMP------- \n" << std::hex;
    for (auto const& [address, data]: memory_map){
        std::cout << address << " : " << data << "\t";
    }
    std::cout << std::dec << "\n";
}