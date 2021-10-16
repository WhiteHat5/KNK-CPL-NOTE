sortword: sortword.o readline.o
	gcc -o sortword sortword.o readline.o
sortword.o: sortword.c readline.h
	gcc -c sortword.c
readline.o: readline.c readline.h
	gcc -c readline.c