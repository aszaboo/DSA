# Dijkstra's Path Finding Algorithm

## What is Dijkstra's Path Finding Algorithm?

Dijkstra's algorithm is a famous algorithm used for finding the shortest paths between nodes in a weighted graph. This algorithm is widely used in network routing protocols and geographic mapping applications.

### Conditions for the Algorithm

- Non-negative graph weights.
- The distance from a node to itself is 0.

## Pseudo Code

### Inputs

- A Graph
- A Start Node
- An End Node

### Output

1. Shortest Path from start node to end node.
2. No path exists from start node to end node.

### Pseudo Code Steps

1. **Check if the startNode and endNode are the same**:
    - If they are, print out that the distance is 0 and return.

    ```cpp
    if (startNode == endNode) {
        cout << "From startNode to itself is zero distance." << endl;
        return;
    }
    ```

2. **Initialize arrays for storing information**:
    - **shortestDistFound**: A boolean array that indicates if the shortest distance to a node has been found.
    - **shortestDist**: An array that stores the shortest known distance from the start node to each node.
    - **shortestPath**: An array that stores a string representation of the shortest path from the start node to each node.

    ```cpp
    bool shortestDistFound[SIZE]; 
    int shortestDist[SIZE];       
    string shortestPath[SIZE];  
    ```

3. **Populate shortestDistFound, shortestDist, and shortestPath arrays**:
    - Set `shortestDistFound[startNode] = true` because we are starting at this node and the shortest distance from the start node to itself is 0.
    - Loop through the adjacency matrix to initialize the distances and paths for nodes directly connected to the start node.
    - Check if any of these nodes are the endNode; if so, return the shortest distance immediately.

    ```cpp
    for (int i = 0; i < SIZE; i++) {
        // Fill starting row with distances to directly connected nodes
        shortestDist[i] = adjMatrix[startNode][i];
        
        // Initialize the paths for directly connected nodes
        if (shortestDist[i] < MAX) {
            shortestPath[i] = to_string(startNode) + "->" + to_string(i);
        }
        
        // Mark the start node as processed, others as unprocessed
        if (i == startNode) {
            shortestDistFound[i] = true;
        } else {
            shortestDistFound[i] = false;
        }
    }
    ```

4. **While loop** continues until one of two conditions is met:
    1. The end node is found.
    2. All nodes have been checked, and there is no path from the start node to the end node.

    - Inside the while loop, each iteration performs the following steps:
      1. Initialize variables to store the shortest distance (`shortNodeDist = MAX`) and the index of the node with this distance (`shortNodeIndex = -1`).

      ```cpp
      int shortNodeIndex = -1;
      int shortNodeDistance = MAX;
      ```

      2. Use a for loop to update these values, considering only unprocessed nodes.

      ```cpp
      for (int i = 0; i < SIZE; ++i) {
          if (shortestDist[i] < shortNodeDistance && !shortestDistFound[i]) {
              shortNodeDistance = shortestDist[i];
              shortNodeIndex = i;
          }
      }
      ```

      3. If `shortNodeIndex` is still `-1`, no further path is possible; return that the node can't be reached from the start node.

      ```cpp
      if (shortNodeIndex == -1) {
          cout << "No path from start node " + to_string(startNode) + " to endNode " + to_string(endNode) << endl;
          return;
      }
      ```

      4. Mark the node with the shortest distance as processed.

      ```cpp
      shortestDistFound[shortNodeIndex] = true;
      ```

      5. If the index corresponds to the endNode, return the shortest distance and path.

      ```cpp
      if (shortNodeIndex == endNode) {
          cout << "Found shortest path from " << startNode << " to " << endNode << ". Path: " << shortestPath[endNode]
               << ", total distance: " << shortestDist[endNode] << endl;
          return;
      }
      ```

      6. For other cases, check if the path to each connected node can be improved via the current node and update distances and paths accordingly.

      ```cpp
      for (int i = 0; i < SIZE; ++i) {
          if (!shortestDistFound[i]) {
              if (adjMatrix[shortNodeIndex][i] != MAX && shortNodeDistance + adjMatrix[shortNodeIndex][i] < shortestDist[i]) {
                  // Update the shortest distance
                  shortestDist[i] = shortNodeDistance + adjMatrix[shortNodeIndex][i];
                  // Update the string path to include the new node
                  shortestPath[i] = shortestPath[shortNodeIndex] + "->" + to_string(i);
              }
          }
      }
      ```

## Code Implementation

```cpp
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Used for representing non-connected nodes
const int MAX = numeric_limits<int>::max();
const int SIZE = 6; // Total number of nodes

// Function prototype
void dijkstra(int adjMatrix[SIZE][SIZE], int startNode, int endNode);

void dijkstra(int adjMatrix[SIZE][SIZE], int startNode, int endNode) {
    // Check for valid inputs
    if (startNode == endNode) {
        cout << "From startNode to itself is zero distance." << endl;
        return;
    }

    // Initialize arrays for storage
    bool shortestDistFound[SIZE]; // Determines whether node processed yet (shortest dist found)
    int shortestDist[SIZE];       // Holds the shortest distance from start node to node i
    string shortestPath[SIZE];    // Holds the string of the shortest path from start node to node i

    // Populate arrays
    for (int i = 0; i < SIZE; i++) {
        shortestDist[i] = adjMatrix[startNode][i]; // Fill starting row with connected nodes
        if (shortestDist[i] < MAX) 
            shortestPath[i] = to_string(startNode) + " -> " + to_string(i); // Add the paths to the path array
        if (i == startNode) 
            shortestDistFound[i] = true; // Mark startNode as processed
        else 
            shortestDistFound[i] = false;
    }

    while (true) {
        // Initialize variables to find the node with the smallest distance
        int shortNodeIndex = -1;   // Holds index of node with shortest distance from the current node
        int shortNodeDistance = MAX; // Holds distance from current node to shortNodeIndex (shortest distance of connected paths not already processed)
        
        // Find the node with the smallest distance from the current node to connected nodes
        for (int i = 0; i < SIZE; ++i) {
            if (shortestDist[i] < shortNodeDistance && !shortestDistFound[i]) {
                shortNodeDistance = shortestDist[i];
                shortNodeIndex = i;
            }
        }

        // If shortNodeIndex is -1, no further path can be explored
        if (shortNodeIndex == -1) {
            cout << "No path from start node " << to_string(startNode) << " to endNode " << to_string(endNode) << endl;
            return;
        }

        // Mark the node with the shortest distance as processed
        shortestDistFound[shortNodeIndex] = true;

        // If the end node is reached, print the shortest path and distance
        if (shortNodeIndex == endNode) {
            cout << "Found shortest path from " << startNode << " to " << endNode << ". Path: " << shortestPath[endNode]
                 << ", total distance: " << shortestDist[endNode] << endl;
            return;
        }

        // Update the shortest distances and paths for each connected node
        for (int i = 0; i < SIZE; ++i) {
            if (!shortestDistFound[i]) {
                if (adjMatrix[shortNodeIndex][i] != MAX && shortNodeDistance + adjMatrix[shortNodeIndex][i] < shortestDist[i]) {
                    // Update the shortest distance
                    shortestDist[i] = shortNodeDistance + adjMatrix[shortNodeIndex][i];
                    // Update the string path to include the new node
                    shortestPath[i] = shortestPath[shortNodeIndex] + " -> " + to_string(i);
                }
            }
        }
    }
}

int main() {
    // Adjacency matrix representation
    int m[6][6] = {
        {0, 3, MAX, MAX, MAX, 5},
        {MAX, 0, 7, MAX, MAX, 10},
        {MAX, MAX, 0, 5, 1, MAX},
        {MAX, MAX, MAX, 0, 6, MAX},
        {MAX, MAX, MAX, MAX, 0, 

7},
        {MAX, MAX, 8, 2, MAX, 0}
    };

    dijkstra(m, 0, 0);
    dijkstra(m, 0, 1);
    dijkstra(m, 0, 2);
    dijkstra(m, 0, 3);
    dijkstra(m, 0, 4);
    dijkstra(m, 0, 5);
    dijkstra(m, 1, 0);
    dijkstra(m, 3, 0);

    return 0;
}
```

**Output**:

```cpp
From startNode to itself is zero distance.
Found shortest path from 0 to 1. Path: 0->1, total distance: 3
Found shortest path from 0 to 2. Path: 0->1->2, total distance: 10
Found shortest path from 0 to 3. Path: 0->5->3, total distance: 7
Found shortest path from 0 to 4. Path: 0->1->2->4, total distance: 11
Found shortest path from 0 to 5. Path: 0->5, total distance: 5
No path from start node 1 to endNode 0
No path from start node 3 to endNode 0
```
