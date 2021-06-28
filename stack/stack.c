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
  int size;
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
  stack->size = 2;

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
  int top = stack->limit;

  if(stack->nodes == NULL) {
    printf("Stack empty!\n");
  } else {
    //printf("Top: %s \nBottom: %s \nLimit: %d \n\n", stack->top->name, stack->bottom->name, stack->limit);

    for(int i=top; i>=0; i--) {
      printf("%d: [%s, %d]\n", i, stack->nodes[i].name, stack->nodes[i].age);
    }
  }
}

void clear(struct stack *stack) {
  struct node *node_to_delete;
  int top = stack->limit;

  for(int i=top; i>=0; i--) {
    node_to_delete = &stack->nodes[i];

    printf("Deleta o %s", node_to_delete->name);

    if(!POP(stack, node_to_delete)) {
      printf("Error: there is not top to delete.");
    }
  }

  stack->nodes = NULL;
  stack->top = NULL;
  stack->bottom = NULL;
}

void PUSH(struct stack *stack, struct node *node) {
  struct node *temp;
  
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

  } else {
    // Reallocating memory for a new node on the stack
    temp = (struct node*)realloc(stack->nodes, sizeof(struct node) * stack->size);
    printf("Size: %d \n", stack->size);

    if(!temp){
      printf("Memory allocation error.\n");
      exit(1);
    }

    stack->nodes = temp;

    // Updating stack informations
    stack->limit++;
    stack->top = &stack->nodes[stack->limit];

    // Copying new_node to stack
    strcpy(stack->nodes[stack->limit].name, node->name);
    stack->nodes[stack->limit].age = node->age;

    stack->size++;
  }

  free(node);
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