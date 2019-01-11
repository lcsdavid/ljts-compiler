CC = g++
CXXFLAGS=-Wall -g -std=c++17
LIB=libljts
EXEC=test

$(EXEC): main.o
	$(CC) -o $@ $^ $(LDFLAGS)
	
%.o: %.cpp
	$(CC) -c $< $(CXXFLAGS)