CFLAGS = -std=gnu99 -Wall
LDLIBS = -lm
.PHONY: default clean

default: out.txt
	cat out.txt

out.txt: main
	./main > out.txt

main: main.o
	$(CC) $(CFLAGS) main.o $(LDLIBS) -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf main main.o out.txt
