CFLAGS = -std=gnu99 -Wall 
CFLAGS += $$(gsl-config --cflags) 
LDLIBS = -lm
LDLIBS += $$(gsl-config --libs)
PLOTTER = gnuplot
FORMAT = pdf
SCRIPT = log.gpi
DATA = data.out

.PHONY: clean default

report.pdf: report.tex plot.$(FORMAT) 
	pdflatex $<
	pdflatex $<

plot.$(FORMAT): $(DATA) Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT)
	echo 'set out "$@"' >> $(SCRIPT)
	echo 'set key out' >> $(SCRIPT)
	echo 'set xlabel "x"' >> $(SCRIPT)
	echo 'set ylabel "y"' >> $(SCRIPT)
	echo 'set yrange [-10:10]' >> $(SCRIPT)
	echo 'set grid' >> $(SCRIPT)
	echo 'set linetype 2 dashtype 2' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT)
	echo '"$(word 1,$^)" using 1:2 with lines title "tan(x)" \' >> $(SCRIPT)
	echo ',"$(word 1,$^)" using 1:3 with lines title "my\_tan(x)" noenhanced' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)

$(DATA): main
	./$^ -4.0 4.0 0.01 > $@

main: main.o
	$(CC) $(CFLAGS) $< $(LDLIBS) -o $@
	
main.o: main.c
	$(CC) $(CFLAGS) -c $<	

clean:
	rm *.o main $(SCRIPT) *.pdf *.log *.aux *.out
