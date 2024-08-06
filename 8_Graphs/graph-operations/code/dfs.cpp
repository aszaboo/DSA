#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void preOrder(int start, vector<vector<int>> &graph) {
    // Create a stack for storing nodes
    stack<int> s;
    s.push(start);

    // Create a list of seen nodes
    vector<bool> seen(graph.size(), false);
    seen[start] = true;

    // Loop until the stack is empty
    while(!s.empty()) {
        // Get the value of the current node
        int node = s.top();
        s.pop();

        // Print the node (process the node)
        cout << node << " ";

        // Iterate through all adjacent nodes
        for (int i = 0; i < graph[node].size(); ++i) {
            // If the node is connected and not seen, push it to the stack
            if (graph[node][i] != 0 && !seen[i]) {
                s.push(i);
                seen[i] = true; // Mark the node as seen
            }
        }
    }
    cout << endl;
}

void postOrder(int start, vector<vector<int>> &graph) {
    // Create a stack for storing nodes
    stack<int> s;
    s.push(start);

    // Create a list of seen nodes
    vector<bool> seen(graph.size(), false);
    vector<int> output; // Output list for post-order processing
    seen[start] = true;

    // Loop until the stack is empty
    while(!s.empty()) {
        int node = s.top();
        s.pop();

        output.push_back(node); // Add node to output list

        // Iterate through all adjacent nodes
        for (int i = 0; i < graph[node].size(); ++i) {
            // If the node is connected and not seen, push it to the stack
            if (graph[node][i] != 0 && !seen[i]) {
                s.push(i);
                seen[i] = true; // Mark the node as seen
            }
        }
    }

    // Print nodes from the output list in reverse order
    for (auto it = output.rbegin(); it != output.rend(); ++it) {
        cout << *it << " ";
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

    // Perform Pre-Order DFS starting from node 0
    cout << "preOrder Traversal" << endl;
    preOrder(0, graph);

    // Perform Post-Order DFS starting from node 0
    cout << "postOrder Traversal" << endl;
    postOrder(0, graph);

    return 0;
}