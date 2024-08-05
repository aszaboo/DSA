#include "binary-search-tree.h"
#include <stack>
#include <queue>
#include <iostream>

BinarySearchTree::Node::Node(DataType newval) {
    val = newval;
    left = nullptr;
    right = nullptr;
    avlBalance = 0;
}

int BinarySearchTree::getNodeDepth(Node* n) const {
    // tree empty or invalid input node n
    if (root_ == nullptr || n == nullptr) return -1;

    // current level
    int level = 0;

    // stack for BFS
    std::queue<std::pair<Node*, int>> queue;
    // push the first value
    queue.push(std::make_pair(root_, 0));

    while (!queue.empty())
    {
        Node* current = queue.front().first;
        int depth = queue.front().second;
        queue.pop();

        // found node
        if (current == n) return level;
        
        // push the left and right children with implemented depth
        if (current->right != nullptr) queue.push(std::make_pair(current->right, level + 1));
        if (current->left != nullptr) queue.push(std::make_pair(current->left, level + 1));
        level++;
    }

    // n not found
    return -1;

}

BinarySearchTree::BinarySearchTree() {
    root_ = nullptr;
    size_ = 0;
}

BinarySearchTree::~BinarySearchTree() {
    if (root_ == nullptr) return;

    // create a stack for BFS
    std::queue<Node*> queue;
    queue.push(root_);
    
    // travel through tree
    while(!queue.empty()) {
        // store node address to be deleted
        Node* current = queue.front();
        // pop the front node
        queue.pop();
        // push children if not null
        if (current->right != nullptr) queue.push(current->right);
        if (current->left != nullptr) queue.push(current->left);
        // delete current node
        delete current;
    }
}

unsigned int BinarySearchTree::size() const {
    return size_;
}

BinarySearchTree::DataType BinarySearchTree::max() const {
    if (root_ == nullptr) return DataType(-999);
    // traverse to right most child
    Node* current = root_;

    while(current->right != nullptr) {
        current = current->right;
    }

    return current->val;
}

BinarySearchTree::DataType BinarySearchTree::min() const {
    if (root_ == nullptr) return DataType(-999);
    // traverse to left most child
    Node* current = root_;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current->val;
}

unsigned int BinarySearchTree::height() const {
    if (root_ == nullptr) return -1;

    unsigned int height = 0;
    Node* current = root_;
    
    // create a stack for BFS
    std::stack<Node*> stack;
    stack.push(current);

    return height;
}

void BinarySearchTree::print() const {
    if (root_ == nullptr) {
        std::cout << "The tree is empty." << std::endl;
        return;
    }

    // Create a queue for BFS
    std::queue<Node*> queue;
    queue.push(root_);

    while (!queue.empty()) {
        // Get the current node and print its value
        Node* current = queue.front();
        queue.pop();
        std::cout << current->val << std::endl;

        // Push left and right children if they exist
        if (current->left != nullptr) queue.push(current->left);
        if (current->right != nullptr) queue.push(current->right);
    }
}

bool BinarySearchTree::exists(DataType val) const {
    if (root_ == nullptr) return false;

    // create a queue for BFS
    std::queue<Node*> queue;
    queue.push(root_);

    while(!queue.empty()) {
        Node* current = queue.front();
        DataType curr = queue.front()->val;
        if (curr == val) return true;
        queue.pop();

        // push children
        if (current->left != nullptr) queue.push(current->left);
        if (current->right != nullptr) queue.push(current->right);
    }

    return false;
}

BinarySearchTree::Node* BinarySearchTree::getRootNode() {
    return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress() {
    return &root_;
}

// Right Rotation (LL case)
void BinarySearchTree::rotateRight(Node* &root) {
    // newRoot will be the current root's left child
    Node* newRoot = root->left;

    // The current root's left subtree becomes newRoot's right subtree
    root->left = newRoot->right;

    // newRoot's right child becomes the current root
    newRoot->right = root;

    // Update root to be newRoot
    root = newRoot;

    // Update balance factors

    // Update balance factor of the right child (old root)
    // Decrease by 1 for the new subtree level
    // Adjust by the maximum value between 0 and old root's balance factor
    root->right->avlBalance = root->right->avlBalance - 1 - std::max(0, root->avlBalance);

    // Update balance factor of the new root
    // Decrease by 1 for the new subtree level
    // Adjust by the minimum value between 0 and the right child's new balance factor
    root->avlBalance = root->avlBalance - 1 + std::min(0, root->right->avlBalance);
}

// Left Rotation (RR case)
void BinarySearchTree::rotateLeft(Node* &root) {
    // newRoot will be the current root's right child
    Node* newRoot = root->right;

    // The current root's right subtree becomes newRoot's left subtree
    root->right = newRoot->left;

    // newRoot's left child becomes the current root
    newRoot->left = root;

    // Update root to be newRoot
    root = newRoot;

    // Update balance factors

    // Update balance factor of the left child (old root)
    // Increase by 1 for the new subtree level
    // Adjust by the maximum value between 0 and old root's balance factor
    root->left->avlBalance = root->left->avlBalance + 1 - std::max(0, root->avlBalance);

    // Update balance factor of the new root
    // Increase by 1 for the new subtree level
    // Adjust by the maximum value between 0 and the left child's new balance factor
    root->avlBalance = root->avlBalance + 1 + std::max(0, root->left->avlBalance);
}

// Left-Right Rotation (LR case)
void BinarySearchTree::rotateLeftRight(Node* &root) {
    // Perform left rotation on the left child
    rotateLeft(root->left);

    // Perform right rotation on the root
    rotateRight(root);
}

// Right-Left Rotation (RL case)
void BinarySearchTree::rotateRightLeft(Node* &root) {
    // Perform right rotation on the right child
    rotateRight(root->right);

    // Perform left rotation on the root
    rotateLeft(root);
}

BinarySearchTree::Node* BinarySearchTree::getParent(Node* root, Node* node) {
    if (root == nullptr || root == node) {
        return nullptr;
    }

    if (root->left == node || root->right == node) {
        return root;
    }

    if (node->val < root->val) {
        return getParent(root->left, node);
    } else {
        return getParent(root->right, node);
    }
}

bool BinarySearchTree::insert(DataType val) {

    // empty tree
    if (root_ == nullptr) {
        root_ = new Node(val);
        size_++;
        return true;
    }
    
    Node* parent = nullptr;
    Node* current = root_;

    while (current != nullptr) {
        if (val == current->val) return false;

        // update parent
        parent = current;
        if (val < current->val) current = current->left;
        if (val > current->val) current = current->right;
    }

    // insert new node
    Node* newNode = new Node(val);
    if (val < parent->val) parent->left = newNode;
    if (val > parent->val) parent->right = newNode;
    size_++;

    // check balance of tree using bfs

    // keep a pointer for lowest unbalanced node
    current = newNode;

    // iterate through tree
    while (parent != nullptr) {
        
        // check where node was inserted
        if (current == parent->left) {
            parent->avlBalance++;
        } else {
            parent->avlBalance--;
        }

        // check if already balanced
        if (parent->avlBalance == 0) {
            break;
        } else if (parent->avlBalance > 1 || parent->avlBalance < -1) {
            // rotate
            if (parent->avlBalance > 1) {
                if (current->val < parent->left->val) {
                    // LL case
                    rotateRight(parent);
                } else {
                    // LR case
                    rotateLeftRight(parent);
                }
            } else {
                if(current->val > parent->right->val) {

                }
            }
        }

    current = parent;
    parent = getParent(root_, parent);

    }

    return true;
}

bool BinarySearchTree::remove(DataType val) {
    
}
