# Depth First Search (DFS)

## What is Depth First Search?

Depth First Search (DFS) is an algorithm that traverses a tree or graph by exploring as far along a branch as possible before backtracking. This means that it will visit the deepest node in a branch before moving to the next branch. DFS is generally implemented using recursion due to its naturally recursive structure, although it can also be implemented iteratively using a stack.

### Key Characteristics of DFS

1. **Depth-Oriented Traversal**: Explores a branch as deep as possible before backtracking.
2. **Uses Stack or Recursion**: Can be implemented using recursion (implicitly using the call stack) or an explicit stack.
3. **Backtracking**: Retraces steps when a dead end is reached, exploring new paths.

## When to Use DFS

DFS is particularly useful in scenarios where:

1. **Path Finding**: You need to find a path between two nodes in a graph.
2. **Topological Sorting**: Used in Directed Acyclic Graphs (DAG) for ordering tasks.
3. **Cycle Detection**: Helps in detecting cycles in graphs.
4. **Solving Mazes and Puzzles**: Efficient for scenarios where the solution is deep within the search space.

## DFS Implementations

Here's the structure of a binary tree node and implementations of DFS in C++ for pre-order, in-order, and post-order traversals.

### Node Structure

```cpp
struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};
```

### Pre-Order Traversal (Recursive)

In Pre-Order traversal, the node is processed before its children. The order is:

1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

```cpp
void preOrder(Node* root) {
    if (root == nullptr) return;

    cout << root->val << endl;  // Visit the root
    preOrder(root->left);       // Traverse left subtree
    preOrder(root->right);      // Traverse right subtree
}
```

### Pre-Order Traversal (Iterative using Stack)

An iterative approach using a stack can also be employed for Pre-Order traversal:

```cpp
#include <stack>

void preOrderIterative(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();

        cout << current->val << endl;  // Visit the root

        // Push right child first so that left is processed first
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}
```

### In-Order Traversal

In In-Order traversal, the node is processed between its children. The order is:

1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.

```cpp
void inOrder(Node* root) {
    if (root == nullptr) return;

    inOrder(root->left);        // Traverse left subtree
    cout << root->val << endl;  // Visit the root
    inOrder(root->right);       // Traverse right subtree
}
```

### Post-Order Traversal

In Post-Order traversal, the node is processed after its children. The order is:

1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root node.

```cpp
void postOrder(Node* root) {
    if (root == nullptr) return;

    postOrder(root->left);      // Traverse left subtree
    postOrder(root->right);     // Traverse right subtree
    cout << root->val << endl;  // Visit the root
}
```

### Intuition on Selection of DFS Implementation

- **Pre-Order**: Useful for creating a copy of the tree or evaluating prefix expressions.
- **In-Order**: Commonly used for binary search trees (BSTs) as it retrieves nodes in non-decreasing order.
- **Post-Order**: Useful for deleting trees or evaluating postfix expressions.

## Time and Space Complexity of DFS

### Time Complexity

- **O(V + E)**: In the worst case, DFS will visit all vertices (`V`) and edges (`E`) in the graph. For a binary tree, this simplifies to **O(N)**, where `N` is the number of nodes.

### Space Complexity

- **O(H)**: The space complexity is determined by the maximum depth of the recursion stack, which is the height (`H`) of the tree. In the worst case (a skewed tree), the space complexity can be **O(N)**. For a balanced tree, it is **O(log N)**.

## DFS vs. BFS

### DFS (Depth First Search)

- **Traversal Order**: Explores as far down a branch as possible before backtracking.
- **Data Structure**: Uses a stack (implicit via recursion or explicit).
- **Use Cases**: Path finding, topological sorting, cycle detection, solving puzzles/mazes.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(H)

### BFS (Breadth First Search)

- **Traversal Order**: Explores all nodes at the present depth level before moving on to nodes at the next depth level.
- **Data Structure**: Uses a queue.
- **Use Cases**: Finding the shortest path in unweighted graphs, level-order traversal, checking connectivity.
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)

In summary, DFS is a powerful algorithm for exploring the depths of a tree or graph, with various applications in computer science. Its recursive nature makes it intuitive to implement, while its versatility allows it to solve a wide range of problems efficiently. The iterative implementation using a stack provides an alternative for environments where recursion depth is a concern.
