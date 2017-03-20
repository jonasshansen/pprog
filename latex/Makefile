CFLAGS = -std=gnu99 -Wall 
CFLAGS += $$(gsl-config --cflags) 
LDLIBS = -lm
LDLIBS += $$(gsl-config --libs)
PLOTTER = gnuplot
FORMAT = pdf
SCRIPT = log.gpi

.PHONY: clean default

report.pdf: report.tex plot.$(FORMAT) 
	pdflatex $<
	pdflatex $<

plot.$(FORMAT): data.txt Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT)
	echo 'set out "$@"' >> $(SCRIPT)
	echo 'set term pdf size 2.5,3' >> $(SCRIPT)
	echo 'set nokey' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "erf(x)"' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1,$^)" using 1:2 with lines' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

data.txt: main
	./$^ -3.0 3.0 0.2 > $@

main: main.o
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
	
main.o: main.c
	$(CC) $(CFLAGS) -c $<	

clean:
	rm *.o data.txt main $(SCRIPT) *.pdf *.log *.aux *.out
