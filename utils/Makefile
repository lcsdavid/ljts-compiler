CC = g++
CXXFLAGS=-Wall -g -std=c++17
EXEC=test

test: $(patsubst %.cpp,%.o,$(wildcard *.cpp))
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< $(CXXFLAGS)
	
clean:
	rm -rf $(EXEC) *.o