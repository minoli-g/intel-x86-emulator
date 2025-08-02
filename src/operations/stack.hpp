#ifndef STACK_H
#define STACK_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void push_50(InputReader* ir, RegisterBank* rb, Memory* mem);
void push_6A(InputReader* ir, RegisterBank* rb, Memory* mem);
void push_68(InputReader* ir, RegisterBank* rb, Memory* mem);

void push(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

void pop_8F(InputReader* ir, RegisterBank* rb, Memory* mem);
void pop_1F(InputReader* ir, RegisterBank* rb, Memory* mem);
void pop_07(InputReader* ir, RegisterBank* rb, Memory* mem);

void pop(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);


#endif