# Breadth-First Traversal (BFS)

## What is Breadth-First Traversal?

Breadth-First Traversal, also known as Level Order Traversal, is a method of traversing the nodes in a graph or tree by visiting each node at the present level before moving on to the nodes at the next level. BFS is an effective way to traverse a tree or graph when all nodes need to be visited, ensuring that nodes closer to the root are processed first.

### Key Characteristics of BFS

1. **Layer-by-Layer Traversal**: Nodes are visited level by level.
2. **Uses a Queue**: A queue is used to keep track of nodes to be visited next.
3. **Guaranteed Shortest Path**: In unweighted graphs, BFS guarantees the shortest path from the starting node to any other node.

## When to Use BFS

BFS is particularly useful in scenarios where:

1. **Shortest Path**: You need to find the shortest path in an unweighted graph.
2. **Level Order Information**: You want to process or collect data level by level.
3. **Connected Components**: You need to check if a graph is connected or find all connected components.
4. **Path Existence**: You need to determine if there is a path between two nodes.

## BFS Implementation for a Binary Tree

Here's a C++ implementation of BFS for a binary tree. The function `printBST` prints the values of nodes in a binary tree level by level.

```cpp
#include <iostream>
#include <queue>

using namespace std;

// Define the structure for a binary tree node
struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

void printBST(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;

    // Push the root node into the queue
    q.push(root);

    // Iterate over the tree until the queue is empty
    // This indicates all nodes have been seen
    while (!q.empty()) {
        // Get the front node from the queue
        Node* current = q.front();

        // Print the value of the current node
        cout << current->value << endl;

        // Remove the front node from the queue
        q.pop();

        // Push the left child into the queue if it exists
        if (current->left != nullptr) q.push(current->left);

        // Push the right child into the queue if it exists
        if (current->right != nullptr) q.push(current->right);
    }
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform BFS on the binary tree
    printBST(root);

    return 0;
}
```

## Explanation of the Code

1. **Node Structure**: Defines a simple binary tree node structure with a value and pointers to left and right children.
2. **Queue Initialization**: Initializes an empty queue to keep track of nodes to visit.
3. **Push Root**: The root node is pushed onto the queue to start the traversal.
4. **While Loop**: The loop continues until the queue is empty:
   - **Front Node**: Retrieves the front node from the queue.
   - **Print Value**: Prints the value of the current node.
   - **Pop Front**: Removes the current node from the queue.
   - **Push Children**: Pushes the left and right children of the current node to the queue if they exist.

## Big O Complexity of BFS

### Time Complexity

- **O(V + E)**: In the worst case, BFS will visit all vertices (`V`) and edges (`E`) in the graph. For a binary tree, this simplifies to **O(N)**, where `N` is the number of nodes, as each node is visited once.

### Space Complexity

- **O(V)**: The space complexity is determined by the maximum size of the queue, which in the worst case can be all the nodes at the deepest level. For a binary tree, this also simplifies to **O(N)**.

## Summary

Breadth-First Traversal is a fundamental algorithm used in various applications, such as finding the shortest path in an unweighted graph, level-order processing, and more. The provided C++ implementation demonstrates how to perform BFS on a binary tree, ensuring an intuitive and efficient traversal of all nodes.
