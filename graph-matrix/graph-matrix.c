#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 99999

void createGraph(int graph[MAX][MAX], int no_of_nodes);
void displayGraph(int graph[MAX][MAX], int no_of_nodes);

void dijkstra(int graph[MAX][MAX], int no_of_nodes, int start_node);
void kruskal(int graph[MAX][MAX], int no_of_nodes);

int main() {
  int graph[MAX][MAX], no_of_nodes, start_node;

  // Reads nodes quantity up to 20
  printf("How many nodes has the graph (up to 20): ");
  do {
    scanf("%d", &no_of_nodes);
    getchar();
  } while (no_of_nodes < 1 || no_of_nodes > MAX);

  // Initialize matrix with zero values
  for(int i=0; i<no_of_nodes; i++) {
    for(int j=0; j<no_of_nodes; j++) {
      graph[i][j] = 0;
    }
  }

  createGraph(graph, no_of_nodes);

  displayGraph(graph, no_of_nodes);

  printf("\nEnter the starting node: ");
  scanf("%d", &start_node);
  getchar();

  dijkstra(graph, no_of_nodes, start_node);

  kruskal(graph, no_of_nodes);

  return 0;
}

void createGraph(int graph[MAX][MAX], int no_of_nodes) {
  int option, first_node, second_node, weight;

  printf("\nCreate all relations between nodes [0 to %d]:\n", no_of_nodes - 1);

  do {
    printf("Type the first node [0 to %d]: ",  no_of_nodes - 1);
    do {
      scanf("%d", &first_node);
      getchar();
    } while (first_node < 0 || first_node > (no_of_nodes - 1));

    printf("Type the second node [0 to %d]: ",  no_of_nodes - 1);
    do {
      scanf("%d", &second_node);
      getchar();
    } while (second_node < 0 || second_node > (no_of_nodes - 1));

    printf("Type the weight/cost between nodes [%d and %d]: ", first_node, second_node);
    scanf("%d", &weight);
    getchar();

    /**
     * Generates bidirectional adjacency matrix with weight values
    */
    for(int i=0; i<no_of_nodes; i++) {
      for(int j=0; j<no_of_nodes; j++) {
        graph[first_node][second_node] = weight;
        graph[second_node][first_node] = weight;
      }
    }

    printf("Type [1] to create a new relation or [0] to exit.\n");
    do {
      scanf("%d", &option);
      getchar();
    } while (option < 0 || option > 1);
  } while (option == 1);
}

void displayGraph(int graph[MAX][MAX], int no_of_nodes) {
  /**
   * Prints adjacency matrix with weight values
  */
  printf("The adjacency matrix of this graph are:\n");
  for(int i=0; i<no_of_nodes; i++) {
    for(int j=0; j<no_of_nodes; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

void dijkstra(int graph[MAX][MAX], int no_of_nodes, int start_node) {
  int cost[MAX][MAX], distance[MAX], visited[MAX], previous[MAX];
  int count, min_distance, next_node;

  /**
   * Test if there is an edge between nodes 'i' and 'j'
   * If false (0), cost receives infinite
   * If true (!=0), cost receives the weight value
  */
  for(int i=0; i<no_of_nodes; i++) {
    for(int j=0; j<no_of_nodes; j++) {
      if(graph[i][j] == 0) {
        cost[i][j] = INF;
      } else {
        cost[i][j] = graph[i][j];
      }
    }
  }

  /**
   * Update the distance array based on cost
   * Update the previous node array
   * Update the visited array for controlling
  */
  for(int i=0; i<no_of_nodes; i++) {
    distance[i] = cost[start_node][i];
    previous[i] = start_node;
    visited[i] = 0;
  }

  distance[start_node] = 0;
  visited[start_node] = 1;

  count = 1;
  while(count < no_of_nodes - 1) {
    min_distance = INF;
    for(int i=0; i<no_of_nodes; i++) {
      if(distance[i] < min_distance && !visited[i]) {
        min_distance = distance[i];
        next_node = i;
      }
    }

    visited[next_node] = 1;
    for(int i=0; i<no_of_nodes; i++) {
      if(!visited[i]) {
        if((min_distance + cost[next_node][i]) < distance[i]) {
          distance[i] = min_distance + cost[next_node][i];
          previous[i] = next_node;
        }
      }
    }

    count++;
  }

  for(int i=0; i<no_of_nodes; i++) {
    if(i != start_node) {
      printf("Between nodes %d and %d:\n", start_node, i);
      printf("The shortest distance is: %d\n", distance[i]);
      printf("The shortest path is: %d", i);

      int j = i;
      do {
        j = previous[j];
        printf("<-%d", j);
      } while (j != start_node);
    }

    printf("\n\n");
  }
}

void kruskal(int graph[MAX][MAX], int no_of_nodes) {
  int count = 1, min, mincost = 0;
  int a, b, u, v;

  /**
   * Turn zero cost into 999 for manipulation
  */
  for(int i=0; i<no_of_nodes; i++) {
    for(int j=0; j<no_of_nodes; j++) {
      if(graph[i][j]==0) {
        graph[i][j]=999;
      }
    }
  }

  /**
   * Traverse all minimum edges between nodes
  */
  printf("The edges of the MST are:\n");
  while(count < no_of_nodes) {
    min = 999;

    for(int i=0;i<no_of_nodes;i++) {
      for(int j=0;j<no_of_nodes;j++) {
        // Testing for all costs != 0
        if(graph[i][j] < min) {
          min = graph[i][j];

          // Copying values for manipulation
    			a = u = i;
    			b = v = j;
        }
      }
    }

    if(u!=v) {
      printf("%d edge (%d,%d) = %d\n", count, a, b, min);
      mincost += min;
      
      count++;
    }

    graph[a][b] = graph[b][a] = 999;
  }

  printf("\n");
  printf("The minimum cost are: %d\n", mincost);
}