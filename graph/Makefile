run:
	gcc graph.c -Wall -o graph; ./graph

debug:
	gcc -g ./graph.c -Wall 

test:
	gcc graph.c -Wall -o graph; ./graph < input.txt

valgrind:
	gcc graph.c -Wall -o graph; valgrind --leak-check=full --track-origins=yes -s  ./graph < input.txt