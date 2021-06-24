#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LIFO: last in, first out

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
  
  if(!POP(stack, node_to_delete)) {
    printf("Error: there is not top to delete.");
  }
}

void display(struct stack *stack) {
  int top = stack->limit;

  if(stack->nodes == NULL) {
    printf("Stack empty!\n");
  } else {
    printf("Top: %s \nBottom: %s \nLimit: %d \n\n", stack->top->name, stack->bottom->name, stack->limit);

    for(int i=top; i>=0; i--) {
      printf("%d: [%s, %d]\n", i, stack->nodes[i].name, stack->nodes[i].age);
    }
  }
}

void clear(struct stack *stack) {
  int top = stack->limit;

  for(int i=top; i>=0; i--) {
    free(&stack->nodes[i]);
  }
}

void PUSH(struct stack *stack, struct node *node) {
  if(stack->nodes==NULL) {
    // Allocating memory for a new node on the stack
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

    free(node);
  } else {
    size_t size = sizeof(node)*(stack->limit + 1);

    // Reallocating memory for a new node on the stack
    stack->nodes = (struct node*)realloc(stack->nodes, size);

    if(!stack->nodes){
      printf("Memory allocation error.\n");
      exit(1);
    }

    // Updating stack informations
    stack->limit++;
    stack->top = &stack->nodes[stack->limit];

    // Copying new_node to stack
    strcpy(stack->nodes[stack->limit].name, node->name);
    stack->nodes[stack->limit].age = node->age;

    free(node);
  }
}

int POP(struct stack *stack, struct node *node) {
  if(stack->top == NULL) {
    return 0; // No top error
  } else {
    stack->limit--;
    stack->top = &stack->nodes[stack->limit];
    return 1;
  }
}