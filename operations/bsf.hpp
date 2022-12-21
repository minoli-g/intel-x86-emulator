#ifndef BSF_H
#define BSF_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void bsf_BC(InputReader* ir, RegisterBank* rb, Memory* mem);

void bsf(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif