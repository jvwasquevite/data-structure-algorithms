run:
	gcc list.c -Wall -o list; ./list

debug:
	gcc -g ./list.c -Wall 

test:
	gcc list.c -Wall -o list; ./list < input.txt

valgrind:
	gcc list.c -Wall -o list; valgrind --leak-check=full --track-origins=yes -s  ./list < input.txt