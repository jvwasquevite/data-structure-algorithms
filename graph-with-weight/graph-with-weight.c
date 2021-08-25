#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Graph with weight implementation using adjacency list
 * Maximum 20 nodes with weight reading
 * Show stored data
 * 
 * This algorithm implements a simple map using graphs,
 * with distances between up to 20 cities
*/

struct edge {
  char name[50];
  int distance;
};

struct node {
  char name[50];
  struct edge edge[50];
  struct node *next;
};

void createNodes(struct node *gnodes[], int no_of_nodes);
void createEdges(struct node *gnodes[], int no_of_nodes);

struct node *findNode(char name[50], struct node *gnodes[], int no_of_nodes);

void createGraph(struct node *gnodes[], int no_of_nodes);
void displayGraph(struct node *gnodes[], int no_of_nodes);
void deleteGraph (struct node *gnodes[], int no_of_nodes);

int main() {
  struct node *gnodes[20];
  int no_of_nodes;

  printf("How many cities has the graph (up to 20): ");
  do {
    scanf("%d", &no_of_nodes);
    getchar();
  } while (no_of_nodes < 1 || no_of_nodes > 20);

  // Initialize all n graph nodes with NULL
  for(int i = 0; i < no_of_nodes; i++) {
    gnodes[i] = NULL;
  }

  createNodes(gnodes, no_of_nodes);
  createEdges(gnodes, no_of_nodes);
  //createGraph(gnodes, no_of_nodes);
  
  printf("\nThe graph is:\n");
  displayGraph(gnodes, no_of_nodes);

  //deleteGraph(gnodes, no_of_nodes);

  return 0;
}

void createNodes(struct node *gnodes[], int no_of_nodes) {
  struct node *new_node;

  // Create and read all graph nodes
  for(int i = 0; i < no_of_nodes; i++) {
    new_node = (struct node *)malloc(sizeof(struct node));

    if(!new_node){
        printf("Memory allocation error.\n");
        exit(1);
    }

    printf("[%d] City name: ", i);
    scanf("%[^\n]s", new_node->name);
    getchar();

    new_node->next = NULL;
    gnodes[i] = new_node;
  }
}

void createEdges(struct node *gnodes[], int no_of_nodes) {
  int choice = 1, dest_distance;
  char dest_name[50];
  struct node *dest_node, *ptr;

  for(int i = 0; i < no_of_nodes; i++) {
    printf("\nPaths leaving from %s:\n", gnodes[i]->name);

    do {
      printf("City name: ");
      scanf("%[^\n]s", dest_name);
      getchar();

      printf("City distance: ");
      scanf("%d", &dest_distance);
      getchar();

      dest_node = findNode(dest_name, gnodes, no_of_nodes);

      if(dest_node == NULL) {
        printf("Error: node not found!\n");
      } else {
        ptr = gnodes[i];

        // Moves ptr to point to the last node
        while(ptr->next != NULL) {
          ptr = ptr->next;
        }

        // Add a new node at the end
        ptr->next = dest_node;
        dest_node->next = NULL;
      }

      printf("Add new path [1/0]? ");
      scanf("%d", &choice);
      getchar();
    } while (choice == 1);
  }
}

struct node *findNode(char name[50], struct node *gnodes[], int no_of_nodes) {
  for(int i = 0; i < no_of_nodes; i++) {
    if(strcmp(name, gnodes[i]->name) == 0) {
      return gnodes[i];
    }
  }
  return NULL;
}

// void createGraph(struct node *gnodes[], int no_of_nodes) {
//   struct node *new_node, *last;
//   char name[50];
//   int n, weight;

//   // Generates all graph nodes
//   for(int i = 0; i < no_of_nodes; i++) {
//     // Allocating memory for a new node
//       new_node = (struct node *)malloc(sizeof(struct node));

//       if(!new_node){
//           printf("Memory allocation error.\n");
//           exit(1);
//       }

//       strcpy(new_node -> name, name);
//       new_node -> distance = weight;
//       new_node -> next = NULL;
//     printf("[%d] City name: ", i);
//     scanf("%[^\n]s", name);
//     getchar();
//   }

//   // Runs over all graph nodes
//   for(int i = 0; i < no_of_nodes; i++) {
//     last = NULL;

//     printf("[%d] City name: ", i);
//     scanf("%[^\n]s", name);
//     getchar();

//     printf("City '%s' has how many routes? ", name);
//     scanf("%d", &n);
//     getchar();
    
//     // Runs over each node neighbours
//     for(int j = 1; j <= n; j++) {
//       printf("[%d of %d] Enter the neighbour city name and distance:\n", j, i);
//       scanf("%[^\n]s", name);
//       getchar();
// 			scanf("%d", &weight);
//       getchar();

//       // Allocating memory for a new node
//       new_node = (struct node *)malloc(sizeof(struct node));

//       if(!new_node){
//           printf("Memory allocation error.\n");
//           exit(1);
//       }
//       strcpy(new_node -> name, name);
//       new_node -> distance = weight;
//       new_node -> next = NULL;

//       if (gnodes[i] == NULL) {
//         gnodes[i] = new_node;
//       } else {
//         last -> next = new_node;
//       }

// 			last = new_node;
//     }
//   }
// }

void displayGraph(struct node *gnodes[], int no_of_nodes) {
  struct node *ptr;
  
  for(int i = 0; i < no_of_nodes; i++) {
    printf("Routes from %s:\n", gnodes[i]->name);

    ptr = gnodes[i]->next;

    if(ptr == NULL) {
      printf("Adjacency list empty!\n");
    } else {
      while(ptr != NULL) {	
        printf("%s \n", ptr -> name);	
        ptr = ptr -> next;
      }
    }

    printf("\n");
    free(ptr);
  }
}

void deleteGraph (struct node *gnodes[], int no_of_nodes) {
  struct node *temp, *ptr;

  for(int i = 0; i <= no_of_nodes; i++) {getchar();getchar();getchar();
    ptr = gnodes[i];

    while(ptr != NULL) {
			temp = ptr;
      ptr = ptr -> next;
			free(temp);
		}

    gnodes[i] = NULL;
  }
}