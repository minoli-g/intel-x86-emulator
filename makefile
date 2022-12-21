CC = g++
CFLAGS = -std=c++17 -Wall -g

main: main.o input_reader.o register.o memory.o modrm.o instr_utils.o opcodes.o add.o mov.o and.o or.o cmp.o stack.o mul.o xor.o bsf.o
	$(CC) $(CFLAGS) -o main main.o input_reader.o register.o memory.o modrm.o instr_utils.o opcodes.o add.o mov.o and.o or.o cmp.o stack.o mul.o xor.o bsf.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

input_reader.o: input_reader.hpp input_reader.cpp
	$(CC) $(CFLAGS) -c input_reader.cpp

register.o: register.hpp register.cpp
	$(CC) $(CFLAGS) -c register.cpp

memory.o: memory.hpp memory.cpp
	$(CC) $(CFLAGS) -c memory.cpp

modrm.o: modrm.hpp modrm.cpp
	$(CC) $(CFLAGS) -c modrm.cpp

instr_utils.o: instr_utils.hpp instr_utils.cpp
	$(CC) $(CFLAGS) -c instr_utils.cpp

opcodes.o: opcodes.hpp opcodes.cpp
	$(CC) $(CFLAGS) -c opcodes.cpp

add.o: operations/add.hpp operations/add.cpp
	$(CC) $(CFLAGS) -c operations/add.cpp

mov.o: operations/mov.cpp operations/mov.hpp
	$(CC) $(CFLAGS) -c operations/mov.cpp

and.o: operations/and.cpp operations/and.hpp
	$(CC) $(CFLAGS) -c operations/and.cpp

or.o: operations/or.cpp operations/or.hpp
	$(CC) $(CFLAGS) -c operations/or.cpp

cmp.o: operations/cmp.cpp operations/cmp.hpp
	$(CC) $(CFLAGS) -c operations/cmp.cpp

stack.o: operations/stack.cpp operations/stack.hpp
	$(CC) $(CFLAGS) -c operations/stack.cpp

mul.o: operations/mul.cpp operations/mul.hpp
	$(CC) $(CFLAGS) -c operations/mul.cpp

xor.o: operations/xor.cpp operations/xor.hpp
	$(CC) $(CFLAGS) -c operations/xor.cpp

bsf.o: operations/bsf.hpp operations/bsf.cpp
	$(CC) $(CFLAGS) -c operations/bsf.cpp