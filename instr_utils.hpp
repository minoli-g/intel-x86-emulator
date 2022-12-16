#ifndef INSTR_UTILS_H
#define INSTR_UTILS_H

#include <cstdint>
#include "register.hpp"
#include "input_reader.hpp"

uint32_t getSIBMemLocation(uint8_t sib, RegisterBank* rb, uint8_t mod, InputReader* ir);

uint8_t getDisp8(InputReader* ir);
uint16_t getDisp16(InputReader* ir);
uint32_t getDisp32(InputReader* ir);

#endif