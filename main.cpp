#include "input_reader.hpp"

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    std::cout<<"Emulation started"<<"\n";

    InputReader ir = InputReader(argv[1]);

    // Testing - output decimal values of every byte
    std::cout<<std::to_string(ir.nextByte())<<"\n";
    std::cout<<std::to_string(ir.nextByte())<<"\n";
    std::cout<<std::to_string(ir.nextByte())<<"\n";
    std::cout<<std::to_string(ir.nextByte())<<"\n";
}