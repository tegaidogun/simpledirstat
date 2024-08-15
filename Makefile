CC=g++
CFLAGS=-std=c++17 -Iinclude -Wall
LDFLAGS=
SRCS=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp, build/%.o, $(SRCS))
EXECUTABLE=build/simpledirstat

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

build/%.o: src/%.cpp
	mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: all clean
