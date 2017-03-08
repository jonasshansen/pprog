CFLAGS = -std=gnu99 -Wall
LDLIBS = -lm
OBJS = main.o equal.o
.PHONY: clean

default: out.txt
	cat out.txt

out.txt: main
	./main > out.txt

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o main

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

equal.o: equal.c
	$(CC) $(CFLAGS) -c equal.c

clean: 
	rm -rf main out.txt equal $(OBJS)
