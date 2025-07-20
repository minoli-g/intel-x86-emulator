#ifndef instruction_utils_H
#define instruction_utils_H

#include "input_reader.hpp"
#include "register.hpp"
#include <cstdint>
#include <vector>

class InstructionUtils
{
public:
	static const std::vector<std::string> reg_names_32bit; // TODO keep this info in RB class

	static uint32_t getSIBMemLocation(uint8_t sib, RegisterBank* rb, uint8_t mod, InputReader* ir);
	static void setFlagGroup(long long int value, int size, RegisterBank* rb);

	static uint8_t getDisp8(InputReader* ir);
	static uint16_t getDisp16(InputReader* ir);
	static uint32_t getDisp32(InputReader* ir);

	static int8_t getImm8(InputReader* ir);
	static int16_t getImm16(InputReader* ir);
	static int32_t getImm32(InputReader* ir);
};

#endif