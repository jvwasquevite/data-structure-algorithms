#include <stdio.h>
#include <stdlib.h>

// Queue has restrict access: can't PUSH and POP in any position
// FIFO: First In, First Out
// POP: on the beginning of the queue
// PUSH: on the end of the queue

// Nodes are linked together using linked list concepts
// There are two pointers to point to first and last node:
// (first) -> [content|*next] -> [content|*next] -> [content|NULL] <- (last)

struct content {
  char name[50];
  int age;
};

struct node {
  struct content cont;
  struct node *next;
};

struct queue {
  struct node *first;
  struct node *last;
};

struct queue *initialize_queue();
void add_person(struct queue *);
void display(struct queue *);
void clear(struct queue *);

// Basic operations
void PUSH(struct queue *, struct node *);
void POP(struct queue *);

int main(int argc, char *argv[]) {
  int option;

  printf("0: Add new person\n");
  printf("1: Delete person\n");
  printf("3: Display queue\n");
  printf("4: Clean queue\n");
  printf("5: Exit\n");

  // Initialize queue
  struct queue *queue = initialize_queue();

  do {
    printf("\nEnter your option: ");
    scanf("%d", &option);
    getchar();
    printf("\n");
    
		switch(option) {
      case 0: add_person(queue);
			break;
      case 1: POP(queue);
			break;
      case 3: display(queue);
			break;
      case 4: clear(queue);
			break;
      case 5: free(queue);
      break;
		}
  } while(option != 5);

  return 0;
}

struct queue *initialize_queue() {
  struct queue *queue;

  // Allocating memory for queue
  queue = (struct queue*)malloc((sizeof(struct queue)));

  if(!queue){
      printf("Memory allocation error.\n");
      exit(1);
  }

  // Initializating queue
  queue->first = NULL;
  queue->last = NULL;

  return queue;
}

void add_person(struct queue *queue) {
  struct node *new_node;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Type the name and age:\n");
  scanf("%[^\n]s", new_node->cont.name);
  getchar();
  scanf("%d", &new_node->cont.age);
  getchar();

  PUSH(queue, new_node);
}

void display(struct queue *queue) {
  struct node *ptr;

  if(queue->first == NULL) {
    printf("Queue is empty. \n");
  } else {
    for(ptr = queue->first; ptr != NULL; ptr = ptr->next) {
      printf("[%s, %d]\n", ptr->cont.name, ptr->cont.age);
    }
  }
}

void clear(struct queue *queue) {
  struct node *ptr, *node_to_delete;

  if(queue->first != NULL) {
    ptr = queue->first;
    while(ptr != NULL) {
      node_to_delete = queue->first;
			queue->first = queue->first->next;
      ptr = queue->first;
      free(node_to_delete);
    }
  }

  // Reseting pointers
  queue->first = NULL;
  queue->last = NULL;
}

void PUSH(struct queue *queue, struct node *node) {
  if(queue->first == NULL) { // First insertion
    queue->first = node;
    queue->first->next = NULL;
    queue->last = node;
    queue->last->next = NULL;
  } else {
    queue->last->next = node;
    queue->last = node;
    queue->last->next = NULL;
  }
}

void POP(struct queue *queue) {
  struct node *ptr;
  ptr = queue->first;

  if(ptr == NULL) {
    printf("Queue is empty. \n");
  } else {
    queue->first = queue->first->next;
    free(ptr);
  }
}