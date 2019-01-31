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

lex_only: $(EXEC).o
	$(CC) -DLEX_MAIN -o $(EXEC).yy.o -c $(EXEC).yy.cpp $(CXXFLAGS)
	$(CC) -o $@ $(EXEC).o $(EXEC).yy.o $(LDFLAGS)

bison_only: $(EXEC).o $(EXEC).yy.o $(wildcard utils/*.cpp)
	$(CC) -DBISON_MAIN -o $(EXEC).tab.o -c $(EXEC).tab.cpp $(CXXFLAGS)
	$(CC) -o $@ $(EXEC).o $(EXEC).yy.o $(EXEC).tab.o $(LDFLAGS)

%.yy.cpp: %.lex
	flex -o $@ $<
	
%.tab.cpp: %.ypp
	bison -o $@ $<

GénérationDeCodeTerritoireDeJules/GenerationCodeTree.o:
	
%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)

.Phony: clean

clean:
	rm -rfv $(EXEC) $(OBJs) *.yy.cpp *.tab.h *.tab.cpp