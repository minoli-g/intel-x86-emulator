#ifndef MODRM_H
#define MODRM_H

#include "register.hpp"
#include "input_reader.hpp"

enum RegisterTypes{
    REG_8, REG_16, REG_32, REG_MM, REG_XMM
};

uint8_t getModRM(InputReader* ir);
uint8_t getMod(uint8_t modrm);
uint8_t getReg(uint8_t modrm);
uint8_t getRM(uint8_t modrm);

std::string getRegFromIndex(uint8_t index, enum RegisterTypes reg_type);
bool isRMReg(uint8_t modrm);
std::string getRMReg(uint8_t modrm, enum RegisterTypes reg_type);
uint32_t getRMMemLocation(uint8_t modrm, RegisterBank* rb, InputReader* ir);

#endif