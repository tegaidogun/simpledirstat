CC=gcc
CFLAGS=-Iinclude

simpledirstat: main.o scanner.o utils.o
    $(CC) -o simpledirstat main.o scanner.o utils.o

%.o: src/%.cpp
    $(CC) -c -o $@ $< $(CFLAGS)

clean:
    rm -f *.o simpledirstat
