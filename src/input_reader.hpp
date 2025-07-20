#ifndef INPUTREADER_H
#define INPUTREADER_H

#include <cstdint>
#include <fstream>
#include <iostream>

class InputReader
{
private:
	std::ifstream input_file;

public:
	InputReader(std::string path);
	~InputReader();
	std::uint8_t nextByte();
	bool fileRemaining();
};

#endif