CFLAGS = -std=gnu99 -Wall 
CFLAGS += $$(gsl-config --cflags) 
LDLIBS = -lm
LDLIBS += $$(gsl-config --libs)
OBJS = main.o rosenbrock.o

.PHONY: clean

default: out.txt
	cat $^

out.txt: main
	./$^ > $@

main: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c $<	

rosenbrock.o: rosenbrock.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm $(OBJS) out.txt main
