#ifndef INSTR_UTILS_H
#define INSTR_UTILS_H

#include <cstdint>
#include "input_reader.hpp"

uint32_t getSIBMemLocation(uint8_t sib);
uint32_t getDisp32(InputReader* ir);

#endif