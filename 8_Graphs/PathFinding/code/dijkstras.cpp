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
            shortestPath[i] = to_string(startNode) + "->" + to_string(i); // Add the paths to the path array
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
                    shortestPath[i] = shortestPath[shortNodeIndex] + "->" + to_string(i);
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
        {MAX, MAX, MAX, MAX, 0, 7},
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
