run:
	gcc linked-list-with-header.c -Wall -o linked-list-with-header; ./linked-list-with-header

debug:
	gcc -g ./linked-list-with-header.c -Wall 

test:
	gcc linked-list-with-header.c -Wall -o linked-list-with-header; ./linked-list-with-header < input.txt

valgrind:
	gcc linked-list-with-header.c -Wall -o linked-list-with-header; valgrind --leak-check=full --track-origins=yes -s  ./linked-list-with-header < input.txt