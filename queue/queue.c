#include <stdio.h>
#include <stdlib.h>

// FIFO: First In, First Out
// POP: on the beginning of queue
// PUSH: on the end of queue

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
void delete_person(struct queue *);
void display(struct queue *);
void clear(struct queue *);

// Basic operations
void PUSH(struct queue *, struct node *);
//int POP(struct queue *, struct node *);

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
      case 1: delete_person(queue);
			break;
      case 3: display(queue);
			break;
      case 4: clear(queue);
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

void delete_person(struct queue *queue) {
  struct node *ptr;
  ptr = queue->first;

  if(ptr == NULL) {
    printf("Queue is empty. \n");
  } else {
    queue->first = queue->first->next;
    free(ptr);
  }
}

void display(struct queue *queue) {
  struct node *ptr;
  ptr = queue->first;

  if(ptr == NULL) {
    printf("Queue is empty. \n");
  } else {
    while(ptr != queue->last) {
      printf("[%s, %d]\n", ptr->cont.name, ptr->cont.age);
      ptr = ptr->next;
    }

    printf("[%s, %d]\n", ptr->cont.name, ptr->cont.age);
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