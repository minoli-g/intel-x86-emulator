#ifndef ADD_H
#define ADD_H

#include "../input_reader.hpp"
#include <vector>

void add_00(InputReader* ir);
void add_01(InputReader* ir);
void add_02(InputReader* ir);
void add_03(InputReader* ir);
void add_04(InputReader* ir);
void add_05(InputReader* ir);
void add_83(InputReader* ir);

void add(InputReader* ir, std::vector<uint8_t> incoming_opcodes);

#endif