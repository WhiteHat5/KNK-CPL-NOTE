rpnstack: rpnSTACK.o stack.o
	gcc -o rpnstack rpnSTACK.o stack.o
rpnSTACK.o: rpnSTACK.c stack.h
	gcc -c rpnSTACK.c
stack.o: stack.c stack.h
	gcc -c stack.c