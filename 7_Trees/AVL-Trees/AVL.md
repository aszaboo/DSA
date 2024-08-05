# AVL Trees

## What is an AVL Tree

An AVL tree is a self-balancing binary search tree where the difference between the heights of left and right subtrees cannot be more than one for all nodes. Named after its inventors, Adelson-Velsky and Landis, an AVL tree maintains its height-balanced property through rotations during insertions and deletions.

### Properties of an AVL Tree

1. **Balance Factor**: The balance factor of any node in an AVL tree is the height difference between its left and right subtrees. It must be between -1 and 1 for all nodes.
2. **Height-Balanced**: The tree maintains a balance such that the height of the tree is always O(log N), where N is the number of nodes.
3. **Rotations**: Rotations (left, right, left-right, and right-left) are performed to maintain the balance factor within the acceptable range.

## AVL Tree Structure

An AVL tree node consists of:

- A key (or value).
- Pointers to left and right children.
- A height attribute to track the height of the node.

### Operations

#### Rotations

Rotations are fundamental operations in AVL trees that help maintain balance. There are four types of rotations:

1. **Left Rotation**
2. **Right Rotation**
3. **Left-Right Rotation**
4. **Right-Left Rotation**

**Left Rotation**
![Left Rotation](https://media.geeksforgeeks.org/wp-content/uploads/20221229131815/avl11-(1)-768.png)

**Right Rotation**
![Right Rotation](https://media.geeksforgeeks.org/wp-content/uploads/20231102165654/avl-tree.jpg)

**Left-Right Rotation**
![Left-Right Rotation](https://media.geeksforgeeks.org/wp-content/uploads/20221229131629/avl33-(1)-768.png)

**Right-Left Rotation**
![Right-Left Rotation](https://media.geeksforgeeks.org/wp-content/uploads/20221229131517/avl44-(1)-768.png)

### Code Implementation

#### Node Structure

```cpp
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};
```

#### Utility Functions

```cpp
int height(Node* N) {
    if (N == nullptr) return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
```

#### Rotations

```cpp
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(Node* N) {
    if (N == nullptr) return 0;
    return height(N->left) - height(N->right);
}
```

### Insert

The insertion operation in an AVL tree is similar to that in a binary search tree but with additional steps to maintain the balance.

**Image of Insertion Operation**
![Insertion Operation](https://media.geeksforgeeks.org/wp-content/uploads/AVL-Insertion-1.jpg)

**Code for Insertion**

```cpp
Node* insert(Node* node, int key) {
    // Perform the normal BST insertion
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get the balance factor of this ancestor node
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the (unchanged) node pointer
    return node;
}
```

#### Pre-order Traversal

Pre-order traversal is used to print the tree nodes in a depth-first manner.

```cpp
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
```

### Driver Code

```cpp
int main() {
    Node* root = nullptr;

    // Constructing tree given in the above figure
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // The constructed AVL Tree would be
    //        30
    //       /  \
    //     20   40
    //    /  \    \
    //  10  25   50

    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);

    return 0;
}
```

### Steps to Follow for Insertion

1. **Perform Standard BST Insert**: Insert the new node as you would in a regular BST.
2. **Update Heights**: Update the height of the ancestor nodes.
3. **Get Balance Factor**: Check the balance factor of the ancestor nodes.
4. **Rebalance if Needed**: Perform rotations to maintain the AVL tree balance. The rotations are:
   - **Left Left Case**: Right rotation.
   - **Right Right Case**: Left rotation.
   - **Left Right Case**: Left rotation followed by right rotation.
   - **Right Left Case**: Right rotation followed by left rotation.

### Deletion in an AVL Tree

Deletion in an AVL tree involves similar steps to maintain the tree's balance after the deletion. Here is a high-level summary:

1. **Perform Standard BST Delete**: Remove the node as in a regular BST.
2. **Update Heights**: Update the height of the ancestor nodes.
3. **Get Balance Factor**: Check the balance factor of the ancestor nodes.
4. **Rebalance if Needed**: Perform rotations to maintain the AVL tree balance.

**Code for Deletion**

```cpp
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
```

### Summary of AVL Trees

- **Self-Balancing**

: AVL trees maintain their height balance automatically.

- **Balancing Factor**: Ranges between -1, 0, and +1.
- **Rotations**: Four types of rotations ensure the tree remains balanced.
- **Operations**: Insert, delete, and search operations have a time complexity of O(log N).

### Advantages of AVL Trees

1. **Height Balanced**: Always maintains a balanced height, ensuring O(log N) height.
2. **Efficient Search**: Provides better search performance compared to unbalanced binary search trees.
3. **Self-Balancing**: Automatically balances after insertions and deletions.

AVL trees are ideal in scenarios where search operations are more frequent compared to insertions and deletions, ensuring efficient and balanced performance.
