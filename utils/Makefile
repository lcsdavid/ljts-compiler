CC = g++
CXXFLAGS=-Wall -g -std=c++17
LIB=libljts

$(EXEC): tree.o
	ar rvs libljts.a $^
	
%.o: %.cpp
	$(CC) -c $< $(CXXFLAGS)