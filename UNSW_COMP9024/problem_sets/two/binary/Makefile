binary : stack.o binary.o
	gcc -o binary binary.o stack.o

binary.o : binary.c
	gcc -Wall -Werror -c binary.c

stack.o : stack.c
	gcc -Wall -Werror -c stack.c

clean :
	rm *.o binary
