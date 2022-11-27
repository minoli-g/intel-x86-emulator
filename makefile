CC = g++
CFLAGS = -std=c++17 -Wall -g

main: main.o input_reader.o
	$(CC) $(CFLAGS) -o main main.o input_reader.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

input_reader.o: input_reader.hpp input_reader.cpp
	$(CC) $(CFLAGS) -c input_reader.cpp
