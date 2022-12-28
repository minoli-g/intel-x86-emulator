#ifndef AND_H
#define AND_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void and_24(InputReader* ir, RegisterBank* rb, Memory* mem);
void and_25(InputReader* ir, RegisterBank* rb, Memory* mem);
void and_20(InputReader* ir, RegisterBank* rb, Memory* mem);
void and_21(InputReader* ir, RegisterBank* rb, Memory* mem);
void and_22(InputReader* ir, RegisterBank* rb, Memory* mem);

void andOp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif