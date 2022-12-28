#ifndef XOR_H
#define XOR_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void xor_34(InputReader* ir, RegisterBank* rb, Memory* mem);
void xor_35(InputReader* ir, RegisterBank* rb, Memory* mem);
void xor_30(InputReader* ir, RegisterBank* rb, Memory* mem);
void xor_31(InputReader* ir, RegisterBank* rb, Memory* mem);

void xorOp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif