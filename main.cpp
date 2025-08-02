#include "src/emulator.hpp"

#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	Emulator& emulator = Emulator::getInstance();
	emulator.run(argv[1]);
}