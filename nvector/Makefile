CFLAGS = -std=gnu99 -Wall
LDLIBS = -lm
OBJS = main.o nvector.o
.PHONY: clean nvector

default: out.txt
	cat out.txt

out.txt: main
	./main > out.txt

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

nvector.o: nvector.c
	$(CC) $(CFLAGS) -c nvector.c

clean:
	rm -rf main out.txt nvector $(OBJS)
