run:
	gcc stack.c -Wall -o stack; ./stack

debug:
	gcc -g ./stack.c -Wall 

test:
	gcc stack.c -Wall -o stack; ./stack < input.txt

valgrind:
	gcc valgrind.c -Wall -o valgrind; valgrind --leak-check=full --track-origins=yes -s  ./valgrind < input.txt