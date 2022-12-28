#ifndef MOV_H
#define MOV_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void mov_88(InputReader* ir, RegisterBank* rb, Memory* mem);
void mov_89(InputReader* ir, RegisterBank* rb, Memory* mem);
void mov_8A(InputReader* ir, RegisterBank* rb, Memory* mem);
void mov_8B(InputReader* ir, RegisterBank* rb, Memory* mem);

void mov(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif