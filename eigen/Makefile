CFLAGS = -std=gnu99 -Wall 
CFLAGS += $$(gsl-config --cflags) 
LDLIBS = -lm
LDLIBS += $$(gsl-config --libs)

.PHONY: clean

default: out.txt
	cat out.txt

out.txt: main
	./main > out.txt

main: main.o
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
	
main.o: main.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o out.txt main
