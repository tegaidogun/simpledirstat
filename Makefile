CC=g++
CFLAGS=-std=c++17 -Iinclude -Wall
LDFLAGS=
SRCS=$(wildcard src/*.cpp)
OBJS=$(SRCS:.cpp=.o)
EXECUTABLE=simpledirstat

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

src/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(EXECUTABLE)

.PHONY: all clean
