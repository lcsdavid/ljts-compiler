CC=g++
CXXFLAGS=-Wall -g -std=c++17
LDFLAGS=-lfl
EXEC=ljts-compiler

$(EXEC): ljts-compiler.tab.o ljts-compiler.yy.o
	$(CC) -o $@ $^ $(LDFLAGS)

lex_only: ljts-compiler.yy.o
	$(CC) -o $@ $^ $(LDFLAGS)

bison_only: ljts-compiler.tab.o ljts-compiler.yy.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.yy.cpp: %.lex
	flex -o $@ $<
	
%.tab.cpp: %.ypp
	bison -o $@ $<

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

.Phony: clean

clean:
	rm -f *.o *.yy.c *.tab.h *.tab.c