CC=g++
CXXFLAGS=-Wall -g -std=c++17
LDFLAGS=-lfl
EXEC=ljts-compiler

$(EXEC): $(EXEC).o $(EXEC).tab.o $(EXEC).yy.o $(wildcard utils/*.cpp)
	$(CC) -o $@ $^ $(LDFLAGS)

lex_only: $(EXEC).o $(EXEC).yy.cpp
	$(CC) -DLEX_MAIN -o $(EXEC).yy.o -c $(EXEC).yy.cpp $(CXXFLAGS)
	$(CC) -o $@ $(EXEC).o $(EXEC).yy.o $(LDFLAGS)

bison_only: $(EXEC).o $(EXEC).yy.o $(EXEC).tab.cpp  $(wildcard utils/*.cpp)
	$(CC) -DBISON_MAIN -o $(EXEC).tab.o -c $(EXEC).tab.cpp $(CXXFLAGS)
	$(CC) -o $@ $(EXEC).o $(EXEC).yy.o $(EXEC).tab.o $(LDFLAGS)

%.yy.cpp: %.lex
	flex -o $@ $<
	
%.tab.cpp: %.ypp
	bison -o $@ $<

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

.Phony: clean

clean:
	rm -rf $(EXEC) *.o *.yy.cpp *.tab.h *.tab.cpp