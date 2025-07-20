#include "input_reader.hpp"

#include <cstdint>
#include <fstream>
#include <iostream>

InputReader::InputReader(std::string path)
{
	this->input_file.open(path);
	if (!this->input_file)
	{
		throw std::runtime_error("Error: Failed to open file");
	}
}

InputReader::~InputReader()
{
	this->input_file.close();
}

std::uint8_t InputReader::nextByte()
{
	if (this->fileRemaining())
	{
		std::string next_byte;
		this->input_file >> next_byte; // Stops at the whitespace, reading only 1 byte
		return (std::uint8_t)std::stoi(
			next_byte, nullptr, 16); // Read the string's hex value into an integer
	}
	else
	{
		throw std::runtime_error(
			"Error: Reached end of input file while attempting to read further bytes \n");
	}
}

bool InputReader::fileRemaining() const
{
	return this->input_file.good();
}
