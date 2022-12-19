#ifndef ADD_H
#define ADD_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void add_00(InputReader* ir, RegisterBank* rb, Memory* mem);
void add_01(InputReader* ir, RegisterBank* rb, Memory* mem);
void add_02(InputReader* ir, RegisterBank* rb, Memory* mem);
void add_03(InputReader* ir, RegisterBank* rb, Memory* mem);
void add_04(InputReader* ir, RegisterBank* rb, Memory* mem);
void add_05(InputReader* ir, RegisterBank* rb, Memory* mem);
void add_83(InputReader* ir, RegisterBank* rb, Memory* mem);

void add(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif