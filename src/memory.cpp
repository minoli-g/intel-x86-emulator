#include "memory.hpp"
#include <iostream>

Memory::Memory(){
    memory_map = {};
}

uint32_t Memory::read(uint32_t address){
    if (memory_map.count(address)){
        std::cout << "Read value "<< +memory_map[address] <<" from memory location " << +address << "\n";
        return memory_map[address];
    }
    std::cout << std::hex 
            << "Error: attempted to read from invalid memory location "<< address <<"\n"
            << std::dec;
    exit(0);
}

void Memory::write(uint32_t address, uint32_t data) {
    std::cout << "Set value of memory location "<< +address << " to "<< +data << "\n";
    memory_map[address] = data;
}

void Memory::push_stack(uint32_t data, RegisterBank* rb, int size){
    std::cout << "Pushing data " << +data << " to stack\n";
    uint32_t stack_ptr = rb->get("ESP");
    stack_ptr -= size;
    this->write(stack_ptr, data);
    rb->set("ESP", stack_ptr);
}

uint32_t Memory::pop_stack(RegisterBank* rb, int size){
    std::cout << "Popping data from stack \n";
    uint32_t stack_ptr = rb->get("ESP");
    uint32_t value = this->read(stack_ptr);
    stack_ptr += size;
    return value;
}

void Memory::dumpValues(){
    std::cout << "\n-------MEMORY DUMP------- \n" << std::hex;
    for (auto const& [address, data]: memory_map){
        std::cout << address << " : " << data << "\t";
    }
    std::cout << std::dec << "\n";
}