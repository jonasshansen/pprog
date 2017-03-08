CFLAGS = -std=gnu99 -Wall
LDLIBS = -lm
PLOTTER = gnuplot
FORMAT = pdf
SCRIPT = log.gpi
DATAFILE = in.dat

.PHONY: all clean 

all: plot.$(FORMAT)
	evince plot.$(FORMAT)

plot.$(FORMAT): out-stdio.dat out-cmdline.dat Makefile
	echo 'set term $(FORMAT)' > $(SCRIPT) #write gnuplot script file here
	echo 'set out "$@"' >> $(SCRIPT) #set output file to the target plot.pdf
	echo 'set key out' >> $(SCRIPT) #display key (legend) outside the plot
	echo 'set xlabel "x"' >> $(SCRIPT) #append to script
	echo 'set ylabel "y"' >> $(SCRIPT)
	echo 'plot \' >> $(SCRIPT) #break line with \
	echo '"$(word 1,$^)" with points title "stdio" \' >> $(SCRIPT) #use first prerequisite
	echo ',"$(word 2,$^)" with points title "cmdline" \' >> $(SCRIPT) #use second prerequisite
	echo ',sin(x) with lines \' >> $(SCRIPT)
	echo ',cos(x) with lines' >> $(SCRIPT)
	$(PLOTTER) $(SCRIPT)



out-stdio.dat: $(DATAFILE) main-stdio
	./main-stdio < $(DATAFILE) > $@ #run main-stdio with input in.dat and write to target out-stdio.dat

main-stdio: main-stdio.o
	$(CC) $(CFLAGS) main-stdio.o $(LDLIBS) -o main-stdio

main-stdio.o: main-stdio.c
	$(CC) $(CFLAGS) -c main-stdio.c 



out-cmdline.dat: $(DATAFILE) main-cmdline
	./main-cmdline `cat $(DATAFILE)` > $@

main-cmdline: main-cmdline.o
	$(CC) $(CFLAGS) main-cmdline.o $(LDLIBS) -o main-cmdline

main-cmdline.o: main-cmdline.c
	$(CC) $(CFLAGS) -c main-cmdline.c 



#create data file for plotting
in.dat: Makefile
	echo $$(seq 0 0.2 10) > $(DATAFILE) #write the sequence to the data file



clean:
	find ./ -type f -executable -delete
	rm *.o plot.$(FORMAT) $(SCRIPT) *.dat
