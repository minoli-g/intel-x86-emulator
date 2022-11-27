#include "input_reader.hpp"
#include <iostream>
#include <fstream>

InputReader::InputReader(std::string path){
    this->input_file.open(path);
    if(!this->input_file){
        std::cout<<"Error: Failed to open file";
        exit(0);
    }
}

InputReader::~InputReader(){
    this->input_file.close();
}

uint8_t InputReader::nextByte(){
    std::string next_byte;              
    this->input_file >> next_byte;      // Stops at the whitespace, reading only 1 byte
    return (uint8_t) std::stoi(next_byte, nullptr, 16);     // Read the string's hex value into an integer
}
