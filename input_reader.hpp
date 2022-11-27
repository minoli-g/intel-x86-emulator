#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <iostream>
#include <fstream>

class InputReader{
    private:
        std::ifstream input_file;

    public:
        InputReader(std::string path);
        ~InputReader();
        std::uint8_t nextByte();
};

#endif