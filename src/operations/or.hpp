#ifndef OR_H
#define OR_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void or_0C(InputReader* ir, RegisterBank* rb, Memory* mem);
void or_0D(InputReader* ir, RegisterBank* rb, Memory* mem);
void or_08(InputReader* ir, RegisterBank* rb, Memory* mem);
void or_09(InputReader* ir, RegisterBank* rb, Memory* mem);

void orOp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif