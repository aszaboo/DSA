# Graph Traversal

## Comparison to Trees

Graph traversal is very similar to tree traversal. This makes sense as a tree is a special case of a graph, where it is directional and each node only points to nodes below it in the tree, not vice versa. Like trees, common methods for traversing a graph are Breadth-First Search (BFS) and Depth-First Search (DFS). However, there are key differences:

- **Trees**: Have a hierarchical structure with a single root node. Each node has exactly one parent (except the root) and can have multiple children.
- **Graphs**: Are more general and can have cycles, multiple roots, and nodes that can point back to their ancestors or any other nodes.

## BFS

### Difference Between BFS in Trees and Graphs

In trees, BFS is straightforward as there are no cycles. In graphs, we need to keep track of visited nodes to avoid infinite loops caused by cycles.

### Steps for BFS

1. **Initialize**: Push the starting node into a queue and mark it as seen.
2. **Loop**:
   - Pop the front node from the queue.
   - Process the current node (e.g., print it).
   - Push all adjacent nodes that haven't been seen into the queue and mark them as seen.
3. **End**: The loop ends when the queue is empty.

### Implementation

```cpp
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
```

**Input**:

```
   0
  / \
 1 - 2
  \ /
   3
```

**Output**:

```
0 1 2 3
```

## DFS

### Difference Between DFS in Trees and Graphs

In trees, DFS is also straightforward as there are no cycles. In graphs, we need to keep track of visited nodes to avoid infinite loops caused by cycles. Additionally, there is no concept of "in-order" traversal in graphs as there is in binary trees.

### Pre-Order DFS

In pre-order DFS for graphs, nodes are processed as soon as they are first encountered.

#### Steps for Pre-Order DFS

1. **Initialize**: Push the starting node onto a stack and mark it as seen.
2. **Loop**:
   - Pop the top node from the stack.
   - Process the current node (e.g., print it).
   - Push all adjacent nodes that haven't been seen onto the stack and mark them as seen.
3. **End**: The loop ends when the stack is empty.

#### Pre-Order Implementation

```cpp
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
```

**Input**:

```
   0
  / \
 1 - 2
  \ /
   3
```

**Output**:

```
0 2 3 1 
```

### Post-Order DFS

In post-order DFS for graphs, nodes are processed after all their neighbors have been fully explored.

#### Steps for Post-Order DFS

1. **Initialize**: Push the starting node onto a stack and mark it as seen.
2. **Loop**:
   - Pop the top node from the stack.
   - Push all adjacent nodes that haven't been seen onto the stack and mark them as seen.
   - Push the current node to an output list.
3. **Process**: Print nodes from the output list in reverse order.
4. **End**: The loop ends when the stack is empty.

#### Post-Order Implementation

```cpp
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
```

**Input**:

```
   0
  / \
 1 - 2
  \ /
   3
```

**Output**:

```
1 3 2 0 
```

### No In-Order DFS in Graphs

In-order traversal, as defined in the context of binary trees, does not apply to graphs because graphs are not inherently hierarchical and can have more than two children for any node.

## Graph Cycles

Graphs can have cycles, which are paths that start and end at the same node. Detecting cycles is an important problem in graph theory and can be done using DFS or BFS with additional checks.
