# Graph implementation using matrix

## Graph used on tests

![Graph](input_graph.png)

## Adjacency matrix

Adjacency matrix of an non-oriented graph

| 0   | 1   | 2   | 3   | 4   |
| --- | --- | --- | --- | --- |
| 0   | 10  | 0   | 30  | 100 |
| 10  | 0   | 50  | 0   | 0   |
| 0   | 50  | 0   | 20  | 10  |
| 30  | 0   | 20  | 0   | 60  |
| 100 | 0   | 10  | 60  | 0   |

## Minimum Spanning Tree (MST)

Implemented on Kruskal's algorithm

(0,1) = 10 + (2,4) = 10 + (2,3) = 20 + (0,3) = 30

**Path**: 4 -(10)-> 2 -(20)-> 3 -(30)-> 0 -(10)-> 1

**Minimum cost**: 70
