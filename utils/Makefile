CC = g++
CXXFLAGS=-Wall -g -std=c++17
LIB=libljts

$(EXEC): tree.o
	g++ -o main $(CXXFLAGS)
	
%.o: %.cpp
	$(CC) -c $< $(CXXFLAGS)