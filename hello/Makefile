CLAGS = -std=gnu99 -Wall
.PHONY: default clean # make sure these are not interpreted as a file 

default: out.txt # by default print content of out.txt to terminal
	cat out.txt	

out.txt: hello
	./hello > out.txt # print output to out.txt

hello: hello.c
	$(CC) hello.c -o hello

clean: 
	rm -rf out.txt hello 
