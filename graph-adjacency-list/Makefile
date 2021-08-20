run:
	gcc graph-adjacency-list.c -Wall -o graph-adjacency-list; ./graph-adjacency-list

debug:
	gcc -g ./graph-adjacency-list.c -Wall 

test:
	gcc graph-adjacency-list.c -Wall -o graph-adjacency-list; ./graph-adjacency-list < input.txt

valgrind:
	gcc graph-adjacency-list.c -Wall -o graph-adjacency-list; valgrind --leak-check=full --track-origins=yes -s  ./graph-adjacency-list < input.txt