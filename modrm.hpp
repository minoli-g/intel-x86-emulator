#ifndef MODRM_H
#define MODRM_H

#include "input_reader.hpp"

uint8_t getModRM(InputReader* ir);
uint8_t getMod(uint8_t modrm);
uint8_t getReg(uint8_t modrm);
uint8_t getRM(uint8_t modrm);

#endif