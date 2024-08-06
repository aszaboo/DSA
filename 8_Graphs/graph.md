# Graphs

## What is a Graph?

A graph is a collection of nodes connected by edges.

- **Node (or Vertex)**: Represents an entity.
- **Edge**: Represents a connection between two nodes.

Unlike trees, nodes in a graph can be bi-directionally connected, directionally connected, or not connected at all.

## Types of Graphs

### Directed Graphs

Directed Graphs are a type of graph where edges have a direction associated with them, meaning that they can only be traversed in one direction. You can think of these connections like a one-way road.

![Directed Graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/SCC1.png)

### Undirected Graphs

Undirected Graphs are a type of graph where edges are non-directional, meaning that an edge can be traversed in both directions. You can think of these connections like a two-way road.

![Undirected Graph](https://media.geeksforgeeks.org/wp-content/cdn-uploads/undirectedgraph.png)

### Weighted Graphs

Weighted Graphs are a variation of a graph where the edge between two nodes has a value associated with it. Generally, the smaller the value, the more desirable the edge is to use for traversal. These graphs can be directed or undirected.

![Weighted Graph](https://media.geeksforgeeks.org/wp-content/uploads/graphhh.png)

### Labeled Graph

A graph where each node has a unique symbolic label.

![Labeled Graph](https://www.masaischool.com/blog/content/images/2022/07/Labelled-Graph.png)

## Degree of a Node

### Undirected Graph

**Degree**: The number of distinct edges where the node is an endpoint.

#### Example:

Input: `N = 4, edges[][] = { { 1, 2 }, { 1, 3 }, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 3, 4 } }`

Output: `12`

Explanation:

Below is the graph for the above information:  

![Graph Example](https://media.geeksforgeeks.org/wp-content/uploads/20200430220447/Graph15.jpg)

Node -> Degree 
1 -> 3 
2 -> 3 
3 -> 3 
4 -> 3

Sum of degrees = 3 + 3 + 3 + 3 = 12

Input: `N = 5, edges[][] = { { 1, 2 }, { 1, 3 }, { 2, 4 }, { 2, 5 } }`

Output: `4`

### Directed Graph

**In-Degree**: The number of distinct edges where the node is the endpoint.

**Out-Degree**: The number of distinct edges where the node is the starting point.

#### Example:

Input:

![Directed Graph Example](https://media.geeksforgeeks.org/wp-content/uploads/graphexample-4.png)

Output:

```
Vertex    In    Out
0         1    2
1         2    1
2         2    3
3         2    2
4         2    2
5         2    2
6         2    1
```

## Adjacency of Nodes

Two nodes are adjacent if there exists an edge that connects them.

## Graph Representations 

### Linked Representation

**Adjacency List**: Series of linked lists where each list represents a node and its adjacent nodes.

![Adjacency List](https://media.geeksforgeeks.org/wp-content/uploads/20230727154843/Graph-Representation-of-Undirected-graph-to-Adjacency-List.png)

**C++ Implementation of Adjacency List**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Add an edge to the graph
    void printGraph(); // Print the graph
};

Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
}

void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w); // Add w to v’s list
    adjList[w].push_back(v); // Add v to w's list (for undirected graph)
}

void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "\nAdjacency list of vertex " << v << "\nhead ";
        for (auto x : adjList[v])
            cout << "-> " << x;
        cout << endl;
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
```

### Adjacency Matrix

The adjacency matrix representation is a way of representing a graph's connectivity. This matrix shows if nodes are connected to one another and, in the case of weighted graphs, the weight associated with the edge between the two nodes.

#### Unweighted

**Undirected:**

![Unweighted Undirected Graph](https://media.geeksforgeeks.org/wp-content/uploads/20200604170814/add-and-remove-edge-in-adjacency-matrix-representation-initial1.jpg)

**Directed:**

![Unweighted Directed Graph](https://www.cs.mtsu.edu/~xyang/3080/images/adjDirectedGraph.png)

#### Weighted

![Weighted Graph](https://media.geeksforgeeks.org/wp-content/uploads/20240424142833/Adjacency-Matrix-for-Directed-and-Weighted-graph.webp)

**C++ Implementation of Adjacency Matrix**

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Add an edge to the graph
    void printGraph(); // Print the graph
};

Graph::Graph(int V) {
    this->V = V;
    adjMatrix.resize(V, vector<int>(V, 0));
}

void Graph::addEdge(int v, int w) {
    adjMatrix[v][w] = 1; // Add edge from v to w
    adjMatrix[w][v] = 1; // Add edge from w to v (for undirected graph)
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
```

## Sequential Array vs. Linked Node

| Representation       | Storage Size | Query Performance |
|----------------------|--------------|-------------------|
| **Adjacency Matrix** | O(n^2)       | Faster query      |
| **Adjacency List**   | O(n + e)     | Slower query      |

### When to Choose

- **Sequential Array (Adjacency Matrix)**: Best when most nodes are connected and querying is frequent.
- **Linked Node (Adjacency List)**: Best when few nodes are connected and querying is not as frequent.

## Relationship Between Graph, Tree, and List

A graph is a generalized data structure that includes trees and lists as special cases:

- **Tree**: A connected acyclic graph. It has a hierarchical structure with a root and levels of nodes.
- **List**: A linear sequence of nodes. It can be considered as a simple graph with nodes connected in a single line without any cycles.