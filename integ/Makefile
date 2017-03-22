CFLAGS = -std=gnu99 -Wall 
CFLAGS += $$(gsl-config --cflags) 
LDLIBS = -lm
LDLIBS += $$(gsl-config --libs)
OBJS = main.o integral1.o integral2.o integral2norm.o

.PHONY: clean

default: out.txt
	cat $^

out.txt: main
	./$^ > $@

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $@

integral2norm.o: integral2norm.c	
	$(CC) $(CFLAGS) -c $<

integral2.o: integral2.c
	$(CC) $(CFLAGS) -c $<
	
integral1.o: integral1.c
	$(CC) $(CFLAGS) -c $<

main.o: main.c
	$(CC) $(CFLAGS) -c $<	

clean:
	rm $(OBJS) out.txt main
