run:
	gcc graph-with-weight.c -Wall -o graph-with-weight; ./graph-with-weight

debug:
	gcc -g ./graph-with-weight.c -Wall 

test:
	gcc graph-with-weight.c -Wall -o graph-with-weight; ./graph-with-weight < input.txt

valgrind:
	gcc graph-with-weight.c -Wall -o graph-with-weight; valgrind --leak-check=full --track-origins=yes -s  ./graph-with-weight < input.txt