#include <stdio.h>
#include <stdlib.h>

/*
 * Graph with weight implementation using adjacency list
 * Maximum 20 nodes with weight reading
 * Show stored data
*/

struct node {
  char vertex;
  int weight;
  struct node *next;
};

struct node *gnode;
void createGraph(struct node *Adj[], int no_of_nodes);
void displayGraph(struct node *Adj[], int no_of_nodes);
void deleteGraph (struct node *Adj[], int no_of_nodes);

int main() {
  struct node *Adj[20];
  int i, no_of_nodes;

  printf("How many nodes has the graph: ");
  do {
    scanf("%d", &no_of_nodes);
    getchar();
  } while (no_of_nodes < 1 || no_of_nodes > 20);

  for(i = 0; i < no_of_nodes; i++) {
    Adj[i] = NULL;
  }

  createGraph(Adj, no_of_nodes);
  printf("\nThe graph is:\n");
  displayGraph(Adj, no_of_nodes);
  deleteGraph(Adj, no_of_nodes);

  return 0;
}

void createGraph(struct node *Adj[], int no_of_nodes) {
  struct node *new_node, *last;
  int n, val, weight;

  // Runs over all graph nodes
  for(int i = 0; i < no_of_nodes; i++) {
    last = NULL;

    printf("Node %d has how many neighbours? ", i);
    scanf("%d", &n);
    
    // Runs over each node neighbours
    for(int j = 1; j <= n; j++) {
      printf("Enter the neighbour %d of %d: ", j, i);
			scanf("%d", &val);

      printf("Enter the weight %d of %d: ", j, i);
      scanf("%d", &weight);

      // Allocating memory for a new node
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node -> vertex = val;
      new_node -> weight = weight;
      new_node -> next = NULL;

      if (Adj[i] == NULL) {
        Adj[i] = new_node;
      } else {
        last -> next = new_node;
      }

			last = new_node;
    }
  }
}

void displayGraph(struct node *Adj[], int no_of_nodes) {
  struct node *ptr;
  
  for(int i = 0; i < no_of_nodes; i++) {
    ptr = Adj[i];

    printf("The neighbours of node %d are:", i);
    while(ptr != NULL) {	
      printf(" %d, %d.", ptr -> vertex, ptr -> weight);	
      ptr = ptr -> next;
    }
    printf("\n");
  }
}

void deleteGraph (struct node *Adj[], int no_of_nodes) {
  struct node *temp, *ptr;

  for(int i = 0; i <= no_of_nodes; i++) {
    ptr = Adj[i];

    while(ptr != NULL) {
			temp = ptr;
      ptr = ptr -> next;
			free(temp);
		}

    Adj[i] = NULL;
  }
}