# Binary Trees

## What is a Binary Tree (BT)?

A binary tree is a special type of tree where each parent node has two or fewer children. These trees are fundamental in computer science and are used to implement various data structures such as binary search trees, heaps, and syntax trees.

## Visualization

![BT Visualization](https://media.geeksforgeeks.org/wp-content/cdn-uploads/binary-tree-to-DLL.png "Binary Tree")

## When are Binary Trees Used?

Binary trees are used in numerous applications, including:

- **Binary Search Trees (BSTs)**: Used for fast lookups, insertions, and deletions.
- **Heaps**: Used in priority queues and for efficient sorting algorithms like heap sort.
- **Syntax Trees**: Used in compilers to parse expressions and programming languages.
- **Huffman Coding Trees**: Used in data compression algorithms.

## Binary Tree Code

### BT Node Implementation

```cpp
struct Node {
    DataType val;
    Node* left;
    Node* right;

    Node(DataType value) : val(value), left(nullptr), right(nullptr) {}
};
```
