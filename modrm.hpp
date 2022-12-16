#ifndef MODRM_H
#define MODRM_H

#include "input_reader.hpp"

enum RegisterTypes{
    REG_8, REG_16, REG_32, REG_MM, REG_XMM
};

uint8_t getModRM(InputReader* ir);
uint8_t getMod(uint8_t modrm);
uint8_t getReg(uint8_t modrm);
uint8_t getRM(uint8_t modrm);

bool isRMReg(uint8_t modrm);
std::string getRMReg(uint8_t modrm);
uint32_t getRMMemLocation(uint8_t modrm);

#endif