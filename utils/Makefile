CC = g++
CXXFLAGS=-Wall -g -std=c++17
EXEC=test

test:  main.o structs.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< $(CXXFLAGS)