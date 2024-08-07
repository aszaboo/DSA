# Binary Search Tree (BST)

## What is a BST?

A Binary Search Tree (BST) is a special type of binary tree where each node follows the properties:
- The left subtree of a node contains only nodes with values less than the node's key.
- The right subtree of a node contains only nodes with values greater than the node's key.

This property allows for efficient search, insertion, and deletion operations with an average time complexity of O(log n).

## Visualization

![BST Visualization](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221215114732/bst-21.png "Binary Search Tree")

## BST Code

### Node Struct

```cpp
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};
```

### Tree Class

```cpp
class BST {

private:
    Node* root;

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    bool insert(int val, Node*& node) {
        if (node == nullptr) {
            node = new Node(val);
            return true;
        }

        if (val == node->val) return false;

        if (val < node->val) {
            return insert(val, node->left);
        } else {
            return insert(val, node->right);
        }
    }

    Node* deleteNode(int val, Node* node) {
        if (node == nullptr) return node;

        if (val < node->val) {
            node->left = deleteNode(val, node->left);
        } else if (val > node->val) {
            node->right = deleteNode(val, node->right);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(temp->val, node->right);
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    bool search(int val, Node* node) {
        if (node == nullptr) return false;
        if (node->val == val) return true;

        if (val < node->val) {
            return search(val, node->left);
        } else {
            return search(val, node->right);
        }
    }

public:
    BST() : root(nullptr) {}
    ~BST() {
        clear(root);
    }

    bool insert(int val) {
        return insert(val, root);
    }

    bool deleteNode(int val) {
        root = deleteNode(val, root);
        return root != nullptr;
    }

    bool search(int val) {
        return search(val, root);
    }
};
```

### Insertion in BST

**Steps**:

1. Start from the root node.
2. If the tree is empty, create a new node as the root.
3. If the value to insert is less than the current node's value, move to the left child.
4. If the value to insert is greater than the current node's value, move to the right child.
5. Repeat steps 3 and 4 until the correct position is found, then insert the new node.

**Code**:

```cpp
bool insert(int val, Node*& node) {
    if (node == nullptr) {
        node = new Node(val);
        return true;
    }

    if (val == node->val) return false;

    if (val < node->val) {
        return insert(val, node->left);
    } else {
        return insert(val, node->right);
    }
}
```

**Time Complexity**: 
- Average Case: O(log n)
- Worst Case: O(n)

### Deletion in BST

**Steps**:

1. Start from the root node.
2. If the tree is empty, return.
3. If the value to delete is less than the current node's value, move to the left child.
4. If the value to delete is greater than the current node's value, move to the right child.
5. If the value is found:
   - If the node has no children, delete it.
   - If the node has one child, replace the node with its child.
   - If the node has two children, find the in-order successor (minimum value node in the right subtree), replace the node's value with the successor's value, and delete the successor.

**Code**:

```cpp
Node* deleteNode(int val, Node* node) {
    if (node == nullptr) return node;

    if (val < node->val) {
        node->left = deleteNode(val, node->left);
    } else if (val > node->val) {
        node->right = deleteNode(val, node->right);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->val = temp->val;
        node->right = deleteNode(temp->val, node->right);
    }
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}
```

**Time Complexity**: 
- Average Case: O(log n)
- Worst Case: O(n)

### Search in BST

**Steps**:

1. Start from the root node.
2. If the tree is empty, return false.
3. If the current node's value matches the search value, return true.
4. If the search value is less than the current node's value, move to the left child.
5. If the search value is greater than the current node's value, move to the right child.
6. Repeat steps 3 to 5 until the value is found or the tree ends.

**Code**:

```cpp
bool search(int val, Node* node) {
    if (node == nullptr) return false;
    if (node->val == val) return true;

    if (val < node->val) {
        return search(val, node->left);
    } else {
        return search(val, node->right);
    }
}
```

**Time Complexity**: 
- Average Case: O(log n)
- Worst Case: O(n)

## Summary

- **Insertion**: O(log n) on average, O(n) in the worst case (skewed tree)
- **Deletion**: O(log n) on average, O(n) in the worst case
- **Search**: O(log n) on average, O(n) in the worst case

A Binary Search Tree allows for efficient search, insertion, and deletion operations, provided it remains balanced. For guaranteed balanced performance, consider using self-balancing BSTs like AVL trees or Red-Black trees.

## Time Complexity

### Recurrence Relation

For a balanced BST, the recurrence relation for the height (h) of the tree is:

\[ h = \log_2(n) \]

This is because, in a balanced tree, each level of the tree is filled, leading to a logarithmic relationship between the number of nodes (n) and the height (h).

### Complexity Table

| Operation | Average Case | Worst Case |
|-----------|--------------|------------|
| Insertion | O(log n)     | O(n)       |
| Deletion  | O(log n)     | O(n)       |
| Search    | O(log n)     | O(n)       |