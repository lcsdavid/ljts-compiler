find_sources=$(foreach directory,$(call list_directories, $1),$(wildcard $(directory)*.cpp))
list_directories=$(foreach directory,$(sort $(dir $(wildcard $1*))),$(directory) $(call list_directories, $(directory)*/))

CC = g++
CXXFLAGS=-Wall -g -std=c++17
EXEC=test
SRCs=$(call find_sources, */)
OBJs=$(SRCs:.cpp=.o)

all: $(OBJs)

%.o: %.cpp
	$(CC) -o $@ -c $< $(CXXFLAGS)
	
clean:
	rm -rf $(EXEC) $(OBJs)