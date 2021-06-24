#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked list is a linear collection of nodes, used on stacks, queues, etc.
// Linked list is a self-referential data type
// Linked list has irrestrict access: can PUSH and POP in any position

// Nodes doesn't need to be on consecutive memory locations as arrays
// Nodes in a linked list can be accessed only in a sequential manner
// Singly linked listed allow to access the nodes in only one way
// Doubly linked listed allow to access the nodes in two ways

// Header points to the first element and can store others information:
// [header] -> [content|*next] -> [content|*next] -> [content|NULL]

struct content {
  char name[50];
  int age;
};

struct node {
  struct content cont;
  struct node *next;
};

struct header {
  struct node *start;
};

struct header *initialize_header();
void add_person(struct header *);
void delete_person(struct header *);
void delete_person_by_name(struct header *);
void display(struct header *);
void clear(struct header *);

// Basic operations with index insertion
void PUSH(struct header *, struct node *, unsigned int);
int POP(struct header *, unsigned int);

int main(int argc, char *argv[]) {
  int option;

  printf("0: Add new person by index\n");
  printf("1: Delete person by index\n");
  printf("2: Delete person by name\n");
  printf("3: Display linked list\n");
  printf("4: Clean linked list\n");
  printf("5: Exit\n");

  // Initialize header
  struct header *header = initialize_header();

  do {
    printf("\nEnter your option: ");
    scanf("%d", &option);
    getchar();
    printf("\n");
    
		switch(option) {
      case 0: add_person(header);
			break;
      case 1: delete_person(header);
			break;
      case 2: delete_person_by_name(header);
			break;
      case 3: display(header);
			break;
      case 4: clear(header);
			break;
		}
  } while(option != 5);

  return 0;
}

struct header *initialize_header() {
  struct header *header;

  // Allocating memory for header
  header = (struct header*)malloc((sizeof(struct header)));

  if(!header){
      printf("Memory allocation error.\n");
      exit(1);
  }

  // Initializating header
  header->start = NULL;

  return header;
}

void add_person(struct header *header) {
  struct node *new_node;
  unsigned int index;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  if (header->start == NULL) {
    index = 0; // Index zero if list is empty
  } else {
    do {
      printf("Inform the position: ");
      scanf("%d", &index);
      getchar();
    } while(index < 0);
  }

  printf("Type the name and age:\n");
  scanf("%[^\n]s", new_node->cont.name);
  getchar();
  scanf("%d", &new_node->cont.age);
  getchar();

  PUSH(header, new_node, index);
}

void delete_person(struct header *header) {
  unsigned int index;

  do {
    printf("Inform the position to delete: ");
    scanf("%d", &index);
    getchar();
  } while(index < 0);

  if(!POP(header, index)) {
    printf("Error: empty list or invalid index. \n");
  }
}

void delete_person_by_name(struct header *header) {
  struct node *ptr, *preptr;
  char name[50];

  printf("Name of the node to delete: ");
  scanf("%[^\n]s", name);
  getchar();

  ptr = header->start;

  // Test if is the first node or not
  if(strcmp(ptr->cont.name, name) == 0) {
    header->start = header->start->next;
    free(ptr);
  } else {
    while(strcmp(ptr->cont.name, name) != 0) {
      preptr = ptr;
      ptr = ptr->next;
    }

    preptr->next = ptr->next;
    free(ptr);
  }
}

void display(struct header *header) {
  struct node *ptr;
  int count = 0;

  ptr = header->start;

  // Test if the list is empty
  if(ptr == NULL) {
    printf("Linked list empty!\n");
  } else {
    // Algorithm for traversing a linked list
    while(ptr != NULL) {
      printf("%d: [%s, %d]\n", count++, ptr->cont.name, ptr->cont.age);
      ptr = ptr->next;
    }
  }
}

void clear(struct header *header) {
  struct node *ptr, *node_to_delete;

  if(header->start != NULL) {
    ptr = header->start;
    while(ptr != NULL) {
      node_to_delete = header->start;
			header->start = header->start->next;
      ptr = header->start;
      free(node_to_delete);
    }
  }
}

void PUSH(struct header *header, struct node *node, unsigned int index) {
  struct node *ptr, *preptr;
  int count = 0;

  ptr = header->start;

  if(header->start == NULL && index == 0) { // First insertion
    node->next = NULL;
    header->start = node;
  } else if(index == 0) { // Insertion on the beggining
    node->next = header->start;
    header->start = node;
  } else {
    // Moves ptr to point to desired index
    while(count < index) {
      preptr = ptr;
      ptr = ptr -> next;
      count++;
    }

    // Add a new node on the desired index
    preptr->next = node;
    node->next = ptr;
  }
}

int POP(struct header *header, unsigned int index) {
  struct node *ptr, *preptr;

  ptr = header->start;

  if(header->start == NULL) {
    return 0; // Empty list error
  }

  // Moves ptr to point to desired index
  for(int count=0; count<index && ptr!=NULL; count++) {
    preptr = ptr;
    ptr = ptr -> next;
  }

  if(!ptr) {
    return 0; // Invalid index error
  }

  if(index == 0) {
    header->start = header->start->next;
    free(ptr);
    return 1;
  } else {
    preptr->next = ptr->next;
    free(ptr);
    return 1;
  }
}