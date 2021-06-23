#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct content {
  char name[50];
  int age;
};

struct node {
  struct content cont;
  struct node *next;
};

struct sentinel {
  struct node *start;
};

struct sentinel *initialize_sentinel();
void add_person(struct sentinel *);
void delete_person(struct sentinel *);
void delete_person_by_name(struct sentinel *);
void display(struct sentinel *);
void clear(struct sentinel *);

// Basic operations
void PUSH(struct sentinel *, struct node *, unsigned int);
int POP(struct sentinel *, unsigned int);

int main(int argc, char *argv[]) {
  int option;

  printf("0: Add new person by index\n");
  printf("1: Delete person by index\n");
  printf("2: Delete person by name\n");
  printf("3: Display linked list\n");
  printf("4: Clean linked list\n");
  printf("5: Exit\n");

  // Initialize sentinel
  struct sentinel *sentinel = initialize_sentinel();

  do {
    printf("\nEnter your option: ");
    scanf("%d", &option);
    getchar();
    printf("\n");
    
		switch(option) {
      case 0: add_person(sentinel);
			break;
      case 1: delete_person(sentinel);
			break;
      case 2: delete_person_by_name(sentinel);
			break;
      case 3: display(sentinel);
			break;
      case 4: clear(sentinel);
			break;
		}
  } while(option != 5);

  return 0;
}

struct sentinel *initialize_sentinel() {
  struct sentinel *sentinel;

  // Allocating memory for sentinel
  sentinel = (struct sentinel*)malloc((sizeof(struct sentinel)));

  if(!sentinel){
      printf("Memory allocation error.\n");
      exit(1);
  }

  // Initializating sentinel
  sentinel->start = NULL;

  return sentinel;
}

void add_person(struct sentinel *sentinel) {
  struct node *new_node;
  unsigned int index;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  if (sentinel->start == NULL) {
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

  PUSH(sentinel, new_node, index);
}

void delete_person(struct sentinel *sentinel) {
  unsigned int index;

  do {
    printf("Inform the position to delete: ");
    scanf("%d", &index);
    getchar();
  } while(index < 0);

  if(!POP(sentinel, index)) {
    printf("Error: empty list or invalid index. \n");
  }
}

void delete_person_by_name(struct sentinel *sentinel) {
  struct node *ptr, *preptr;
  char name[50];

  printf("Name of the node to delete: ");
  scanf("%[^\n]s", name);
  getchar();

  ptr = sentinel->start;

  // Test if is the first node or not
  if(strcmp(ptr->cont.name, name) == 0) {
    sentinel->start = sentinel->start->next;
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

void display(struct sentinel *sentinel) {
  struct node *ptr;
  int count = 0;

  ptr = sentinel->start;

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

void clear(struct sentinel *sentinel) {
  struct node *ptr, *node_to_delete;

  if(sentinel->start != NULL) {
    ptr = sentinel->start;
    while(ptr != NULL) {
      node_to_delete = sentinel->start;
			sentinel->start = sentinel->start->next;
      ptr = sentinel->start;
      free(node_to_delete);
    }
  }
}

void PUSH(struct sentinel *sentinel, struct node *node, unsigned int index) {
  struct node *ptr, *preptr;
  int count = 0;

  ptr = sentinel->start;

  if(sentinel->start == NULL && index == 0) { // First insertion
    node->next = NULL;
    sentinel->start = node;
  } else if(index == 0) { // Insertion on the beggining
    node->next = sentinel->start;
    sentinel->start = node;
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

int POP(struct sentinel *sentinel, unsigned int index) {
  struct node *ptr, *preptr;

  ptr = sentinel->start;

  if(sentinel->start == NULL) {
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
    sentinel->start = sentinel->start->next;
    free(ptr);
    return 1;
  } else {
    preptr->next = ptr->next;
    free(ptr);
    return 1;
  }
}