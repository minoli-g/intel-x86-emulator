CC = g++
CFLAGS = -std=c++17 -Wall -g

main: main.o input_reader.o register.o modrm.o add.o bsf.o opcodes.o
	$(CC) $(CFLAGS) -o main main.o input_reader.o register.o modrm.o add.o bsf.o opcodes.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

input_reader.o: input_reader.hpp input_reader.cpp
	$(CC) $(CFLAGS) -c input_reader.cpp

register.o: register.hpp register.cpp
	$(CC) $(CFLAGS) -c register.cpp

modrm.o: modrm.hpp modrm.cpp
	$(CC) $(CFLAGS) -c modrm.cpp

opcodes.o: opcodes.hpp opcodes.cpp
	$(CC) $(CFLAGS) -c opcodes.cpp

add.o: operations/add.hpp operations/add.cpp
	$(CC) $(CFLAGS) -c operations/add.cpp

bsf.o: operations/bsf.hpp operations/bsf.cpp
	$(CC) $(CFLAGS) -c operations/bsf.cpp