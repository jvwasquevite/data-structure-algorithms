// Linked list: linear collection of nodes, used on stacks, queues, etc.
// [ START ] -> [content|*next] -> [content|*next] -> [content|NULL]
// Self-referential data type
// Nodes are doesn't need to be on consecutive memory locations as arrays
// Nodes in a linked list can be accessed only in a sequential manner
// Singly linked listed allow to access the nodes in only one way

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crating nested structs for node and content
struct content {
  char name[50];
  int age;
} content;

struct node {
  struct content cont;
  struct node *next;
};

struct node *start = NULL;
struct node *create_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);

int main(int argc, char *argv[]) {
  int option;

  printf("1: Create a list\n");
  printf("2: Display the list\n");
  printf("3: Add a node at the beginning\n");
  printf("4: Add a node at the end\n");
  printf("5: Add a node before a given node\n");
  printf("6: Add a node after a given node\n");
  printf("7: Delete a node from the beginning\n");
  printf("8: Delete a node from the end\n");
  printf("9: Delete a given node\n");
  printf("10: Delete a node after a given node\n");
  printf("11: Delete the entire list\n");
  printf("12: Sort the list\n");
  printf("13: EXIT\n");

  do {
    printf("\nEnter your option: ");
    scanf("%d", &option);
    getchar();
    printf("\n");
    
		switch(option) {
      case 1: start = create_list(start);
      printf("\nLINKED LIST SUCCESSFULLY CREATED!");
			break;
      case 2: display(start);
			break;
      case 3: start = insert_beg(start);
			break;
      // case 4: start = insert_end(start);
			// break;
      // case 5: start = insert_before(start);
			// break;
      // case 6: start = insert_after(start);
			// break;
      case 7: start = delete_beg(start);
      printf("NODE SUCCESSFULLY DELETED!\n");
			break;
      // case 8: start = delete_end(start);
			// break;
      case 9: start = delete_node(start);
			break;
      // case 10: start = delete_after(start);
			// break;
      // case 11: start = delete_list(start);
      // printf("LINKED LIST DELETED\n");
			// break;
      // case 12: start = sort_list(start);
			// break;
		}
  } while(option != 13);

  return 0;
}

struct node *create_list(struct node *start) {
  struct node *new_node, *ptr;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Name and age:\n");
  scanf("%[^\n]s", new_node->cont.name);
  getchar();
  scanf("%d", &new_node->cont.age);
  getchar();

  // Test if the linked list is started or not
  if(start == NULL) {
    // Start node recevives the new_node
    new_node->next = NULL;
    start = new_node;
  } else {
    ptr = start;
    // Moves ptr to point to the last node
    while(ptr->next != NULL) {
      ptr = ptr->next;
    }
    
    // Add a new node at the end
    ptr->next = new_node;
    new_node->next = NULL;
  }

  return start;
}

struct node *display(struct node *start) {
  struct node *ptr;
  ptr = start;

  // Test if the list is empty
  if(start == NULL) {
    printf("Linked list empty!\n");
  } else {
    // Algorithm for traversing a linked list
    while(ptr != NULL) {
      printf("[%s, %d]\n", ptr->cont.name, ptr->cont.age);
      ptr = ptr->next;
    }
  }

  return start;
}

struct node *insert_beg(struct node *start) {
  struct node *new_node;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Name and age:\n");
  scanf("%[^\n]s", new_node->cont.name);
  getchar();
  scanf("%d", &new_node->cont.age);
  getchar();

  // start node receives new_node
  new_node->next = start;
  start = new_node;

  return start;
}

struct node *insert_end(struct node *start) {
  struct node *new_node, *ptr;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Name and age:\n");
  scanf("%[^\n]s", new_node->cont.name);
  getchar();
  scanf("%d", &new_node->cont.age);
  getchar();

  ptr = start;

  // Moves ptr to point to the last node
  while(ptr->next != NULL) {
    ptr = ptr->next;
  }
  
  // Add a new node at the end
  ptr->next = new_node;
  new_node->next = NULL;

  return start;
}

struct node *insert_before(struct node *start) {
  struct node *new_node, *ptr, *preptr;
  char name[50];

  printf("Name of the node to be inserted before:\n");
  scanf("%[^\n]s", name);
  getchar();

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Name and age:\n");
  scanf("%[^\n]s", new_node->cont.name);
  getchar();
  scanf("%d", &new_node->cont.age);
  getchar();

  ptr = start;

  while(strcmp(ptr->cont.name, name) != 0)  {
    preptr = ptr;
    ptr = ptr -> next;
  }

  preptr->next = new_node;
  new_node->next = ptr;

  return start;
}

struct node *insert_after(struct node *start) {
  struct node *new_node, *ptr, *preptr;
  char name[50];

  printf("Name of the node to be inserted after:\n");
  scanf("%[^\n]s", name);
  getchar();

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Name and age:\n");
  scanf("%[^\n]s", new_node->cont.name);
  getchar();
  scanf("%d", &new_node->cont.age);
  getchar();

  ptr = start;
  preptr = ptr;

  while(strcmp(ptr->cont.name, name) != 0)  {
    preptr = ptr;
    ptr = ptr -> next;
  }

  preptr->next = new_node;
  new_node->next = ptr;

  return start;
}

struct node *delete_beg(struct node *start) {
  struct node *ptr;
  ptr = start;

  // start node reveives the next node
  start = start -> next;

  free(ptr);
  return start;
}

struct node *delete_end(struct node *start) {
  struct node *ptr, *preptr;
  ptr = start;

  // Moves ptr to point to the last node
  while(ptr->next != NULL) {
    preptr = ptr;
    ptr = ptr->next;
  }

  preptr->next = NULL;
  free(ptr);

  return start;
}

struct node *delete_node(struct node *start) {
  struct node *ptr, *preptr;
  char name[50];

  printf("Name of the node to delete:\n");
  scanf("%[^\n]s", name);
  getchar();

  ptr = start;

  // Test if is the first node or not
  if(strcmp(ptr->cont.name, name) == 0) {
    start = delete_beg(start);
    return start;
  } else {
    while(strcmp(ptr->cont.name, name) != 0) {
      preptr = ptr;
      ptr = ptr->next;
    }

    // When while ends:
    // ptr -> node to delete
    // preptr -> previous node

    preptr->next = ptr->next;
    free(ptr);

    return start;
  }
}

struct node *delete_after(struct node *start) {
  struct node *ptr, *preptr;
  char name[50];

  printf("Name of the node to be deleted after:\n");
  scanf("%[^\n]s", name);
  getchar();

  ptr = start;
  preptr = ptr;

  while(strcmp(preptr->cont.name, name) != 0)  {
    preptr = ptr;
    ptr = ptr -> next;
  }

  preptr->next = ptr->next;
  return start;
}

struct node *delete_list(struct node *start) {
  struct node *ptr;

  if(start != NULL) {
    ptr = start;
    while(ptr != NULL) {
			start = delete_beg(ptr);
			ptr = start;
    }
  }

  return start;
}

struct node *sort_list(struct node *start) {
  // Implementar
}
