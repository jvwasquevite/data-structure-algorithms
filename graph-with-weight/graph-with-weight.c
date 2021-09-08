#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Graph with weight implementation using adjacency list
 * Maximum 20 nodes with weight reading
 * Show stored data
*/

struct content {
  char name[50];
  int weight;
};

struct node {
  struct content data;
  struct node *next;
};

void createRelation(struct node *nodes, int no_of_nodes);

int PUSH(Lista *pLista, Nodo *pNodo, int index);

int main() {
  int no_of_nodes, option;
  struct node *nodes;

  // Reads nodes quantity
  printf("How many nodes has the graph (up to 20): ");
  do {
    scanf("%d", &no_of_nodes);
    getchar();
  } while (no_of_nodes < 1 || no_of_nodes > 20);

  // Memory allocation for n graph nodes
  nodes = (struct node *)malloc(sizeof(struct node)*no_of_nodes);
  if(!nodes){
      printf("Memory allocation error.\n");
      exit(1);
  }

  // Reads all nodes name
  printf("\nType all nodes name:\n");
  for(int i=0; i<no_of_nodes; i++) {
    printf("[%d] Node name: ", i);
    scanf("%[^\n]s", nodes[i].data.name);
    getchar();
  }

  printf("\nMenu options:\n[1] Create a new relation between nodes\n[2] Read all graph nodes\n[3] Exit\n\nWhat do you want to do? ");
  scanf("%d", &option);
  getchar();

  switch (option) {
    case 1:
      createRelation(nodes, no_of_nodes);
      break;
    case 2:
      /* read code */
      break;
    case 3:
      /* exit code */
      break;
    default:
      break;
  }

  return 0;
}

void createRelation(struct node *nodes, int no_of_nodes) {
  int fir_node_pos = -1, sec_node_pos = -1, weight;
  char name[50];

  while(fir_node_pos == -1) {
    printf("First node name: ");
    scanf("%[^\n]s", name);
    getchar();

    // Node search by name
    for(int i=0; i<no_of_nodes; i++) {
      if(strcmp(name, nodes[i].data.name) == 0) {
        fir_node_pos = i;
      }
    }

    // 'Node not found' error
    if(fir_node_pos == -1) {
      printf("Error: node not found, try again.\n");
    }
  }

  while(sec_node_pos == -1) {
    printf("Second node name: ");
    scanf("%[^\n]s", name);
    getchar();

    // Node search by name
    for(int i=0; i<no_of_nodes; i++) {
      if(strcmp(name, nodes[i].data.name) == 0) {
        sec_node_pos = i;
      }
    }

    // 'Node not found' error
    if(sec_node_pos == -1) {
      printf("Error: node not found, try again.\n");
    }
  }

  printf("Edge weight: ");
  scanf("%d", &nodes[fir_node_pos].data.weight);
  weight = nodes[fir_node_pos].data.weight; // Stores weight to create bidirectinal graph
  // FAZER PUSH AQUI

  nodes[sec_node_pos].data.weight = weight;
  // FAZER PUSH AQUI
}