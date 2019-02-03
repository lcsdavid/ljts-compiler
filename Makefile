find_sources=$(foreach directory,$(call list_directories, $1),$(wildcard $(directory)*.cpp))
list_directories=$(foreach directory,$(sort $(dir $(wildcard $1*))),$(directory) $(call list_directories, $(directory)*/))

CC=g++
CXXFLAGS=-Wall -g -std=c++17
LDFLAGS=-lfl
EXEC=ljts-compiler
SRCs=$(call find_sources, *) 
OBJs=$(SRCs:.cpp=.o) $(EXEC).yy.o $(EXEC).tab.o

$(EXEC): $(OBJs)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

%.yy.cpp: %.lex
	flex --yylineno -o $@ $<
	
%.tab.cpp: %.ypp
	bison --verbose -d -o $@ $<

.Phony: clean

clean:
	rm -rfv $(EXEC) $(OBJs) *.yy.cpp *.tab.cpp