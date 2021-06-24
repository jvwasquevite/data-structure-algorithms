run:
	gcc stack.c -Wall -o stack; ./stack

debug:
	gcc -g ./stack.c -Wall 

test:
	gcc stack.c -Wall -o stack; ./stack < input.txt

valgrind:
	gcc stack.c -Wall -o stack; valgrind --leak-check=full --track-origins=yes -s  ./stack < input.txt