run:
	gcc graph-matrix.c -Wall -o graph-matrix; ./graph-matrix

debug:
	gcc -g ./graph-matrix.c -Wall 

test:
	gcc graph-matrix.c -Wall -o graph-matrix; ./graph-matrix < input.txt

valgrind:
	gcc graph-matrix.c -Wall -o graph-matrix; valgrind --leak-check=full --track-origins=yes -s  ./graph-matrix < input.txt