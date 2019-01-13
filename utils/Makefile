CC = g++
CXXFLAGS=-Wall -g -std=c++17
LIB=libljts
EXEC=test

test: main.o class_struct.o
	$(CC) -o $@ $^ $(LDFLAGS)

	
%.o: %.cpp
	$(CC) -c $< $(CXXFLAGS)