CFLAGS = -std=gnu99 -Wall 
CFLAGS += $$(gsl-config --cflags) 
LDLIBS = -lm
LDLIBS += $$(gsl-config --libs)
PLOTTER = gnuplot
FORMAT = pdf
SCRIPT = log.gpi

.PHONY: clean default

default: out_ODE.txt plot.$(FORMAT)
	cat out_ODE.txt


plot.$(FORMAT): out_orbit.txt Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT)
	echo 'set out "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "y"' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set key left' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1,$^)" using (1/$$2)*sin($$1):(1/$$2)*cos($$1) with lines notitle \' >> $(SCRIPT)
	echo ',"-" with points pt 5 title "star"' >> $(SCRIPT)
	echo '0 0' >> $(SCRIPT)
	echo 'e' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

out_ODE.txt: ODE
	./ODE > out_ODE.txt

ODE: ODE.o
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
	
ODE.o: ODE.c
	$(CC) $(CFLAGS) -c $<


out_orbit.txt: orbit
	./orbit > out_orbit.txt

orbit: orbit.o
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
	
orbit.o: orbit.c
	$(CC) $(CFLAGS) -c $<	

clean:
	rm *.o out_ODE.txt out_orbit.txt ODE orbit $(SCRIPT) plot.$(FORMAT)
