#include <stdio.h>
#include <stdlib.h>

struct node {
  char vertex;
  struct node *next;
};

struct node *gnode;
void createGraph(struct node *Adj[], int no_of_nodes);
void displayGraph(struct node *Adj[], int no_of_nodes);
void deleteGraph (struct node *Adj[], int no_of_nodes);

int main() {
  struct node *Adj[10];
  int i, no_of_nodes;

  printf("How many nodes has the graph: ");
  scanf("%d", &no_of_nodes);

  for(i = 0; i < no_of_nodes; i++) {
    Adj[i] = NULL;
  }

  createGraph(Adj, no_of_nodes);
  printf("The graph is: ");
  displayGraph(Adj, no_of_nodes);
  //deleteGraph(Adj, no_of_nodes);

  return 0;
}

void createGraph(struct node *Adj[], int no_of_nodes) {
  struct node *new_node, *last;
  int n, val;

  // Runs over all graph nodes
  for(int i = 0; i < no_of_nodes; i++) {
    last = NULL;

    printf("Node %d has how many neighbours? ", i);
    scanf("%d", &n);
    
    // Runs over each node neighbours
    for(int j = 1; j <= n; j++) {
      printf("Enter the neighbour %d of %d: ", j, i);
			scanf("%d", &val);

      // Allocating memory for a new node
      new_node = (struct node *)malloc(sizeof(struct node));
      new_node -> vertex = val;
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
      printf("\t%d", ptr -> vertex);	
      ptr = ptr -> next;
    }
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