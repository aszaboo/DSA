# Binary Search Tree

## What is a BST?

A BST is a special type of binary tree where the left subtree is always smaller than the root and the right subtree is always larger than the root. This property allows for efficient search and insertion operations O(log n).

## Visualization

![BT Visualization](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20221215114732/bst-21.png "Binary Search Tree")

## BST Code


### Node Struct

```cpp
struct Node {
    DataType val
    Node* left;
    Node* right;
    Node(Datatype val) : val(val), left(nullptr), right(nullptr) {}
};
```
### Tree Class

```cpp
class BST {

private:
    Node* root;

public:
    BST() : root(nullptr);
    BST(DataType val) : Node(val) {}
    ~BST() {
        clear(root);
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

    bool insert(Datatype val, Node* node) {

        if(node->val == val) return false;

        if(node == nullptr) {
            node = new Node(val);
            return true;
        }

        if (val < node->val) {
            insert(val, node->left);
        } else {
            insert(val, node->right);
        }
    }

    bool deleteNode(DataType val, Node* node) {

        if (node == nullptr) return false;

        if (val < node->val) {
            deleteNode(val, node->left);
        }
        else if (val > node->val) {
            deleteNode(val, node->right);
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
        }
    }
}
```
