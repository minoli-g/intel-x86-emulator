#ifndef BSR_H
#define BSR_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void bsr_BD(InputReader* ir, RegisterBank* rb, Memory* mem);

void bsr(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif