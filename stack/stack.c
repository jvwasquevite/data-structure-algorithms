#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack has restrict access: can't PUSH and POP in any position
// LIFO: last in, first out
// POP: on the top of the stack
// PUSH: on the top of the stack

// Nodes are not linked together: has no next pointer
// Nodes is allocated in consecutive memory locations as arrays
// Nodes can be manipulated as arrays: node[índex]
// There are two pointers to point to top and bottom node + limit integer:
// (bottom) -> [node] -> [node] -> [node] <- (top) with limit = 2

struct node {
  char name[50];
  int age;
};

struct stack {
  struct node *nodes;
  struct node *top;
  struct node *bottom;
  int limit;
};

struct stack *initialize_stack();

void add_person(struct stack *);
void delete_person(struct stack *);
void display(struct stack *);
void clear(struct stack *);

// Basic operations
void PUSH(struct stack *, struct node *);
int POP(struct stack *, struct node *);

int main(int argc, char *argv[]) {
  int option;

  printf("0: Add new person\n");
  printf("1: Delete person from top\n");
  printf("3: Display stack\n");
  printf("4: Clean stack\n");
  printf("5: Exit\n");

  // Initialize stack
  struct stack *stack = initialize_stack();

  do {
    printf("\nEnter your option: ");
    scanf("%d", &option);
    getchar();
    printf("\n");
    
		switch(option) {
      case 0: add_person(stack);
			break;
      case 1: delete_person(stack);
			break;
      case 3: display(stack);
			break;
      case 4: clear(stack);
			break;
      case 5: free(stack);
      break;
		}
  } while(option != 5);

  return 0;
}

struct stack *initialize_stack() {
  struct stack *stack;

  // Allocating memory for stack
  stack = (struct stack*)malloc((sizeof(struct stack)));

  if(!stack){
      printf("Memory allocation error.\n");
      exit(1);
  }

  // Initializating stack
  stack->nodes = NULL;
  stack->top = NULL;
  stack->bottom =  NULL;
  stack->limit = -1;

  return stack;
}

void add_person(struct stack *stack) {
  struct node *new_node;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Type the name and age:\n");
  scanf("%[^\n]s", new_node->name);
  getchar();
  scanf("%d", &new_node->age);
  getchar();

  PUSH(stack, new_node);
}

void delete_person(struct stack *stack) {
  struct node *node_to_delete;
  node_to_delete = &stack->nodes[stack->limit];
  
  // Pass the toppest node to delete
  if(!POP(stack, node_to_delete)) {
    printf("Error: there is not top to delete.");
  }
}

void display(struct stack *stack) {
  struct node *ptr;
  
  if(stack->nodes == NULL) {
    printf("Stack empty!\n");
  } else {
    for(ptr = stack->top; ptr != stack->bottom; ptr--) {
      printf("[%s, %d]\n", ptr->name, ptr->age);
    }

    printf("[%s, %d]\n", ptr->name, ptr->age); // Bottom node
  }
}

void clear(struct stack *stack) {
  free(stack);

  // Reset stack
  stack = initialize_stack();
}

void PUSH(struct stack *stack, struct node *node) {
  if(stack->nodes==NULL) {
    // Allocating memory for the first node on the stack
    stack->nodes = (struct node*)malloc((sizeof(struct node)));

    if(!stack->nodes){
      printf("Memory allocation error.\n");
      exit(1);
    }

    // Copying new_node to stack
    strcpy(stack->nodes->name, node->name);
    stack->nodes->age = node->age;

    // Updating stack informations
    stack->top = &stack->nodes[0];
    stack->bottom = &stack->nodes[0];
    stack->limit++;

    printf("Tamanho: %zu \n", sizeof(stack->nodes));

    free(node);
  } else {
    // Reallocating memory for a new node on the stack
    stack->nodes = (struct node*)realloc(stack->nodes, 3 * sizeof(struct node)*2);

    if(!stack->nodes){
      printf("Memory allocation error.\n");
      exit(1);
    }

    // Copying new_node to stack
    strcpy(stack->nodes[stack->limit].name, node->name);
    stack->nodes[stack->limit].age = node->age;

    // Updating stack informations
    stack->limit++;
    stack->top = &stack->nodes[stack->limit];
    
    printf("Tamanho: %zu \n", sizeof(stack->nodes));

    free(node);
  }
}

int POP(struct stack *stack, struct node *node) {
  if(stack->top == NULL) {
    return 0; // No top error
  } else {
    stack->limit--;
    stack->top = &stack->nodes[stack->limit];

    if (node == stack->bottom) {
      stack->nodes = NULL;
    }
    return 1;
  }
}