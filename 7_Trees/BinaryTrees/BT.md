# Binary Trees

## What is a Binary Tree (BT)?

A binary tree is a special type of tree where each parent node has two or fewer children. These trees are fundamental in computer science and are used to implement various data structures such as binary search trees, heaps, and syntax trees.

## Differences Between Binary Trees, General Trees, and Binary Search Trees

- **General Tree**: A tree data structure where each node can have an arbitrary number of children. It is a more flexible structure compared to binary trees but can be less efficient for certain operations.
- **Binary Tree**: A tree where each node has at most two children, referred to as the left child and the right child. It provides a more structured and efficient way to represent hierarchical data.
- **Binary Search Tree (BST)**: A binary tree with the additional property that for each node, all values in the left subtree are smaller, and all values in the right subtree are larger. This property allows for efficient search, insertion, and deletion operations.

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
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};
```

### Binary Tree Class

```cpp
class BinaryTree {

private:
    Node* root;

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        clear(root);
    }

    bool insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return true;
        }
        return insert(val, root);
    }

    bool insert(int val, Node* node) {
        if (val == node->val) return false;

        if (val < node->val) {
            if (node->left == nullptr) {
                node->left = new Node(val);
                return true;
            }
            return insert(val, node->left);
        } else {
            if (node->right == nullptr) {
                node->right = new Node(val);
                return true;
            }
            return insert(val, node->right);
        }
    }

    Node* deleteNode(int val, Node* node) {
        if (node == nullptr) return nullptr;

        if (val < node->val) {
            node->left = deleteNode(val, node->left);
        } else if (val > node->val) {
            node->right = deleteNode(val, node->right);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->val = temp->val;
            node->right = deleteNode(temp->val, node->right);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool search(int val) {
        return search(val, root);
    }

    bool search(int val, Node* node) {
        if (node == nullptr) return false;
        if (val == node->val) return true;
        if (val < node->val) return search(val, node->left);
        return search(val, node->right);
    }
};
```

## Binary Tree Operations

### Insert Operation

**Steps**:

1. If the tree is empty, create a new node as the root.

    ```cpp
    if (root == nullptr) {
        root = new Node(val);
        return true;
    }
    ```

2. Recursively find the correct position to insert the new value.

    ```cpp
    bool insert(int val, Node* node) {
        if (val == node->val) return false;

        if (val < node->val) {
            if (node->left == nullptr) {
                node->left = new Node(val);
                return true;
            }
            return insert(val, node->left);
        } else {
            if (node->right == nullptr) {
                node->right = new Node(val);
                return true;
            }
            return insert(val, node->right);
        }
    }
    ```

### Delete Operation

**Steps**:

1. Find the node to be deleted.

    ```cpp
    Node* deleteNode(int val, Node* node) {
        if (node == nullptr) return nullptr;

        if (val < node->val) {
            node->left = deleteNode(val, node->left);
        } else if (val > node->val) {
            node->right = deleteNode(val, node->right);
        }
    ```

2. If the node has one or no children, replace the node with its child.

    ```cpp
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
    ```

3. If the node has two children, replace it with its in-order successor (smallest node in the right subtree).

    ```cpp
            Node* temp = findMin(node->right);
            node->val = temp->val;
            node->right = deleteNode(temp->val, node->right);
        }
        return node;
    }
    ```

### Search Operation

**Steps**:

1. Start at the root and compare the value to be searched with the current node's value.

    ```cpp
    bool search(int val, Node* node) {
        if (node == nullptr) return false;
        if (val == node->val) return true;
    ```

2. If the value is less, search in the left subtree. If the value is greater, search in the right subtree.

    ```cpp
        if (val < node->val) return search(val, node->left);
        return search(val, node->right);
    }
    ```

## Time Complexity

### Recurrence Relation

For a balanced binary tree, the height (h) of the tree is:

\[ h = \log_2(n) \]

This is because, in a balanced tree, each level of the tree is filled, leading to a logarithmic relationship between the number of nodes (n) and the height (h).

### Complexity Table

| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Insertion | O(log n)     | O(n)       |
| Deletion  | O(log n)     | O(n)       |
| Search    | O(log n)     | O(n)       |

In conclusion, binary trees are versatile data structures with various applications. Their efficiency depends on their balance, and understanding their operations and properties is fundamental to leveraging their power in computer science.