#ifndef CMP_H
#define CMP_H

#include "../input_reader.hpp"
#include "../register.hpp"
#include "../memory.hpp"

void cmp_3C(InputReader* ir, RegisterBank* rb, Memory* mem);
void cmp_3D(InputReader* ir, RegisterBank* rb, Memory* mem);
void cmp_38(InputReader* ir, RegisterBank* rb, Memory* mem);
void cmp_39(InputReader* ir, RegisterBank* rb, Memory* mem);

void cmp(InputReader* ir, RegisterBank* rb, Memory* mem, uint8_t opcode);

#endif