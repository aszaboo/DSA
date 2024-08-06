#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &graph) {
    // Initialize a queue and push the starting node
    queue<int> q;
    q.push(start);

    // To keep track of the seen nodes
    vector<bool> seen(graph.size(), false);
    seen[start] = true;

    // Loop until the queue is empty
    while(!q.empty()) {
        // Get the value of the current node
        int node = q.front();
        // Print the node (process the node)
        cout << node << " ";
        // Pop the node from the queue
        q.pop();

        // Iterate through all adjacent nodes
        for (int i = 0; i < graph[node].size(); i++) {
            // If the node is connected and not seen, push it to the queue
            if (graph[node][i] != 0 && !seen[i]) {
                q.push(i);
                seen[i] = true; // Mark the node as seen
            }
        }
    }
    cout << endl;
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    // Perform BFS starting from node 0
    bfs(0, graph);

    return 0;
}