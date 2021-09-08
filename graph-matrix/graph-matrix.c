#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 99999

void dijkstra(int graph[MAX][MAX], int no_of_nodes, int start_node);

int main() {
  int graph[MAX][MAX], no_of_nodes, start_node;

  printf("How many nodes has the graph: ");
  do {
    scanf("%d", &no_of_nodes);
    getchar();
  } while (no_of_nodes < 1 || no_of_nodes > 20);

  printf("\nEnter with the graph matrix representation:\n");
  for(int i=0; i<no_of_nodes; i++) {
    for(int j=0; j<no_of_nodes; j++) {
      scanf("%d", &graph[i][j]);
      getchar();
    }
  }

  printf("\nEnter the starting node: ");
  scanf("%d", &start_node);
  getchar();

  dijkstra(graph, no_of_nodes, start_node);

  return 0;
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
      } while(j != start_node);
    }

    printf("\n\n");
  }

}