run:
	gcc queue.c -Wall -o queue; ./queue

debug:
	gcc -g ./queue.c -Wall 

test:
	gcc queue.c -Wall -o queue; ./queue < input.txt

valgrind:
	gcc queue.c -Wall -o queue; valgrind --leak-check=full --track-origins=yes -s  ./queue < input.txt