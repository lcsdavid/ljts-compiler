CC=g++
CXXFLAGS=-Wall -g -std=c++17
LDFLAGS=-lfl
EXEC=ljts-compiler

$(EXEC): ljts-compiler.tab.o ljts-compiler.yy.o
	$(CC) -o $@ $^ $(LDFLAGS)

lex_only: $(EXEC).yy.cpp
	$(CC) -DLEX_MAIN -o $(EXEC).yy.o -c $(EXEC).yy.cpp $(CXXFLAGS)
	$(CC) -o $@ $(EXEC).yy.o $(LDFLAGS)

bison_only: $(EXEC).yy.o $(EXEC).tab.cpp
	$(CC) -DBISON_MAIN -o $(EXEC).tab.o -c $(EXEC).tab.cpp $(CXXFLAGS)
	$(CC) -o $@ $(EXEC).yy.o $(EXEC).tab.o $(LDFLAGS)

%.yy.cpp: %.lex
	flex -o $@ $<
	
%.tab.cpp: %.ypp
	bison -o $@ $<

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

.Phony: clean

clean:
	rm -f *.o *.yy.c *.tab.h *.tab.c