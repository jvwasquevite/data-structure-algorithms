#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 99999

/**
 * Stores an edge, with two nodes (u, v) + weight (w)
*/
typedef struct edge {
  int u, v, w;
} edge;

/**
 * Stores an edge listing for MST used on kruskal's algorithm
*/
typedef struct edge_list {
  edge edge[MAX];
  int no_of_edges;
} edge_list;

edge_list edgelist;
edge_list MSTlist;

void createGraph(int graph[MAX][MAX], int no_of_nodes);
void displayGraph(int graph[MAX][MAX], int no_of_nodes);

void dijkstra(int graph[MAX][MAX], int no_of_nodes);
void kruskal(int graph[MAX][MAX], int no_of_nodes);

int main() {
  int graph[MAX][MAX], no_of_nodes;

  printf("How many nodes has the graph (up to 20)? ");
  do {
    scanf("%d", &no_of_nodes);
    getchar();
  } while (no_of_nodes < 1 || no_of_nodes > MAX);

  /**
   * Initialize matrix with zero values
  */
  for(int i=0; i<no_of_nodes; i++) {
    for(int j=0; j<no_of_nodes; j++) {
      graph[i][j] = 0;
    }
  }

  createGraph(graph, no_of_nodes);

  displayGraph(graph, no_of_nodes);

  dijkstra(graph, no_of_nodes);

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
     * Generates non-oriented adjacency matrix with weight values
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

void dijkstra(int graph[MAX][MAX], int no_of_nodes) {
  int cost[MAX][MAX], distance[MAX], visited[MAX], previous[MAX];
  int count, min_distance, next_node, start_node;

  printf("\nEnter the starting node: ");
  scanf("%d", &start_node);
  getchar();

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

  printf("\n\n[DIJKSTRA] The minimum costs between nodes are:");

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
  int first_node, second_node, min_cost = 0, belongs[MAX];

  edgelist.no_of_edges = 0;
  edge temp;

  /**
   * Creates edgelist with adjacency matrix data
   * Stores the two nodes + edge weight on edgelist
  */
  for(int i=1; i<no_of_nodes; i++) {
    for(int j=0; j<i; j++) {
      if(graph[i][j] != 0) {
        edgelist.edge[edgelist.no_of_edges].u = i;
        edgelist.edge[edgelist.no_of_edges].v = j;
        edgelist.edge[edgelist.no_of_edges].w = graph[i][j];

        edgelist.no_of_edges++;
      }
    }
  }

  /**
   * Sorts edgelist on ascending order
   * based on edge weight (w)
  */
  for(int i=1; i<edgelist.no_of_edges; i++) {
    for(int j=0; j<(edgelist.no_of_edges-1); j++) {
      if(edgelist.edge[j].w > edgelist.edge[j+1].w) {
        temp = edgelist.edge[j];
        edgelist.edge[j] = edgelist.edge[j+1];
        edgelist.edge[j+1] = temp;
      }
    }
  }

  /**
   * Fill array belongs[] with all graph nodes
  */
  for(int i=0; i<no_of_nodes; i++) {
    belongs[i] = i;
  }

  MSTlist.no_of_edges = 0;

  /**
   * Creates MST list of edges based on
   * sorted edgelist
  */
  for(int i=0; i<edgelist.no_of_edges; i++) {
    first_node = belongs[edgelist.edge[i].u];
    second_node = belongs[edgelist.edge[i].v];

    /**
     * Copies edge from edgelist to MSTlist,
     * increments MSTlist no_of_edges and
     * executes nodes union 
    */
    if(first_node != second_node) {
      MSTlist.edge[MSTlist.no_of_edges] = edgelist.edge[i];
      MSTlist.no_of_edges = MSTlist.no_of_edges+1;

      for(int i=0; i<no_of_nodes; i++) {
        if(belongs[i] == second_node) {
          belongs[i] = first_node;
        }
      }
    }
  }

  /**
   * Print out MST edges with minimum cost
  */
  printf("[KRUSKAL] The Minimum Spanning Tree (MST) are:\n\n");
  for(int i=0; i<MSTlist.no_of_edges; i++) {
    printf("Edge between nodes (%d, %d) with weight = %d\n", MSTlist.edge[i].u, MSTlist.edge[i].v, MSTlist.edge[i].w);
    min_cost = min_cost + MSTlist.edge[i].w;
  }

  printf("\nThe minimum cost of MST are: %d\n", min_cost);
}