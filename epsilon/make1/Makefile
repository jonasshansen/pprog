add : main.o add.o disp.o
	gcc -o add main.o add.o disp.o

main.o : main.c 
	gcc -c main.c 
add.o : add.c 
	gcc -c add.c 
disp.o : disp.c 
	gcc -c disp.c
.PHONY : clean
clean : 
	rm add main.o add.o disp.o
