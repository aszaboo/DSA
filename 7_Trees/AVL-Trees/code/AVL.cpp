#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    int avlBalance;

    Node(int value) : key(value), left(nullptr), right(nullptr), height(1), avlBalance(0) {}
};

int height(Node* N) {
    if (N == nullptr) return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void updateHeightAndBalance(Node* node) {
    if (node != nullptr) {
        node->height = 1 + max(height(node->left), height(node->right));
        node->avlBalance = height(node->left) - height(node->right);
    }
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights and balances
    updateHeightAndBalance(y);
    updateHeightAndBalance(x);

    // Return new root
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights and balances
    updateHeightAndBalance(x);
    updateHeightAndBalance(y);

    // Return new root
    return y;
}

Node* insert(Node* node, int key) {
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // Update height and balance factor of this ancestor node
    updateHeightAndBalance(node);

    // Balance the node if it has become unbalanced
    if (node->avlBalance > 1 && key < node->left->key)
        return rightRotate(node);

    if (node->avlBalance < -1 && key > node->right->key)
        return leftRotate(node);

    if (node->avlBalance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (node->avlBalance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

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
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr) return root;

    updateHeightAndBalance(root);

    if (root->avlBalance > 1 && root->left->avlBalance >= 0)
        return rightRotate(root);

    if (root->avlBalance > 1 && root->left->avlBalance < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (root->avlBalance < -1 && root->right->avlBalance <= 0)
        return leftRotate(root);

    if (root->avlBalance < -1 && root->right->avlBalance > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);
    cout << endl;

    root = deleteNode(root, 10);
    cout << "Preorder traversal after deletion of 10 \n";
    preOrder(root);
    cout << endl;

    return 0;
}
