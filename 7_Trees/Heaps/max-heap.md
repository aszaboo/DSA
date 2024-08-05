Sure, let's complete and expand upon the explanation of Max Heaps, and break down each function in detail, especially focusing on `reheapUp` and `reheapDown`.

# Max Heaps (Priority Queue)

## What is a Max Heap?

A Max Heap is a data structure that represents a complete binary tree where each node's key is greater than or equal to the keys of its children, ensuring that the maximum value is always at the root of the tree. This property allows for quick access to the largest element. The completeness of the binary tree means that all levels of the tree are fully filled except possibly for the last level, which is filled from left to right.

## When is a Max Heap Used?

A Max Heap is used in scenarios where quick access to the maximum element is required. It is particularly useful in:

1. **Priority Queues**: Where elements with the highest priority need to be accessed and removed first.
2. **Heap Sort**: An efficient sorting algorithm that uses the heap data structure.
3. **Scheduling Algorithms**: Where tasks need to be processed based on their priority.

### Type of Problems that Use a Max Heap or Priority Queue

- **Finding the k-largest elements**: Quickly finding the largest elements in a dataset.
- **Merging multiple sorted arrays**: Efficiently merging arrays while maintaining order.
- **Event simulation**: Managing events based on priority.

## Heapify

Heapify is the algorithm that maintains the heap property after insertion or deletion of elements. It ensures that the max heap property is preserved, i.e., the key of each node is greater than or equal to the keys of its children.

### Insertion

Upon insertion, an element is added at the next available position in the tree (maintaining the completeness of the tree). Then the heapify algorithm, specifically `reheapUp`, is called to restore the heap property by comparing the inserted node with its parent and swapping if necessary. This process continues until the correct position is found.

### Deletion

When the root node (the maximum element) is removed, the last inserted element is moved to the root position. The heapify algorithm, specifically `reheapDown`, is then called to restore the heap property by comparing the moved node with its children and swapping with the larger child if necessary. This ensures the largest node is at the root and the tree remains complete.

## Array Implementation of a Tree

A tree can be represented in an array using the following structure:

```
Index:   0  1  2  3  4  5  6  7
Array: [_, 1, 2, 3, 4, 5, 6, 7]
```

Here:

- `0` is a non-filled value for simplicity.
- `1` is the root of the tree.
- `2` is the left child of the root.
- `3` is the right child of the root.
- `4` is the left child of the node at index 2.
- `5` is the right child of the node at index 2.
- `6` is the left child of the node at index 3.

### Abstraction of Representation

#### Root

The root of the heap is at index 1 for simplicity.

#### Left Child of a Node

The left child of a node at index `i` is located at index `2*i`.

#### Right Child of a Node

The right child of a node at index `i` is located at index `2*i + 1`.

## Max Heap Implementation

### Node Structure

```cpp
template <typename T> 
class HeapNode {
private:
    int key;
    T data;

public:
    HeapNode();
    HeapNode(int key_, T data_);
    
    // Getters
    int getKey(); // Get item priority
    T getData(); // Get item data

    // Setters
    void setKey(int key_); // Set item priority
    void setData(T data_); // Set item data
};

// Constructors
template <typename T>
HeapNode<T>::HeapNode() : key(0), data(T()) {}

template <typename T>
HeapNode<T>::HeapNode(int key_, T data_) : key(key_), data(data_) {}

// Getters
template <typename T>
int HeapNode<T>::getKey() {
    return key;
}

template <typename T>
T HeapNode<T>::getData() {
    return data;
}

// Setters
template <typename T>
void HeapNode<T>::setKey(int key_) {
    key = key_;
}

template <typename T>
void HeapNode<T>::setData(T data_) {
    data = data_;
}
```

### MaxHeap Class

```cpp
template <typename T>
class maxHeap {
private:
    HeapNode<T>* elements;
    int size;
    int capacity;

public:
    maxHeap(int cap);
    ~maxHeap();

    // Insertion operations
    bool push(HeapNode<T> item); // Insert item
    void reheapUp(int index); // Reheap up to maintain heap property

    // Deletion operations
    HeapNode<T> pop(); // Remove item
    void reheapDown(int index); // Reheap down to maintain heap property

    // Getters
    int getSize(); // Get current size of heap

    // Print
    void print(); // Print heap elements
};

// Constructor
template <typename T>
maxHeap<T>::maxHeap(int cap) : capacity(cap), size(0), elements(new HeapNode<T>[capacity]) {}

// Destructor
template <typename T>
maxHeap<T>::~maxHeap() {
    delete[] elements; // Free allocated memory
}

// Push
template <typename T>
bool maxHeap<T>::push(HeapNode<T> item) {
    // Check if the heap is full
    if (size >= capacity) return false;

    // Insert the new item at the end of the heap
    elements[size + 1] = item;
    reheapUp(size + 1); // Restore heap property
    size++; // Increase size
    return true;
}

template <typename T>
void maxHeap<T>::reheapUp(int index) {
    // Node is already at root position
    if (index == 1) return;
    
    // Get the parent node
    int parent = index / 2;

    // Check if inserted node's priority is greater than parent's
    if (elements[parent].getKey() < elements[index].getKey()) {
        // Swap the nodes
        swap(elements[parent], elements[index]);

        // Recursive call to check next level
        reheapUp(parent);
    }
}

template <typename T>
HeapNode<T> maxHeap<T>::pop() {
    // Check if heap is empty
    if (size == 0) throw runtime_error("Heap is empty");

    // Store the root node to return
    HeapNode<T> temp = elements[1];

    // Replace root with the last element
    elements[1] = elements[size];

    // Decrease size
    size--;

    // Restore heap property
    reheapDown(1);

    return temp; // Return the root node
}

template <typename T>
void maxHeap<T>::reheapDown(int index) {
    // At max index in tree
    if (2 * index > size) return;

    int chosenChild;

    // Only left child in subtree, must be left child
    if (2 * index == size) {
        chosenChild = size;
    } else {
        // Check if the left or right child is larger
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        chosenChild = (elements[leftChild].getKey() > elements[rightChild].getKey()) ? leftChild : rightChild;
    }

    // If child is larger than parent, swap
    if (elements[chosenChild].getKey() > elements[index].getKey()) {
        swap(elements[index], elements[chosenChild]);
        reheapDown(chosenChild);
    }
}

template <typename T>
int maxHeap<T>::getSize() {
    // Return the current size of the heap
    return size;
}

template <typename T>
void maxHeap<T>::print() {
    if (size == 0) {
        cout << "EMPTY" << endl;
    } else {
        for (int i = 1; i <= size; ++i) {
            cout << "Heap element " << i << ". key = " << elements[i].getKey() << ", data = " << elements[i].getData() << endl;
        }
    }
}

// Main function
int main() {
    maxHeap<string> theHeap(20); // Create a heap with capacity of 20

    theHeap.push(HeapNode<string>(10, "a"));
    theHeap.push(HeapNode<string>(5, "b"));
    theHeap.push(HeapNode<string>(7, "c"));
    theHeap.push(HeapNode<string>(4, "d"));
    theHeap.push(HeapNode<string>(2, "e"));
    theHeap.push(HeapNode<string>(1, "f"));

    theHeap.print(); // Print all heap elements

    cout << "Dequeue data: " << theHeap.pop().getData() << endl;
    theHeap.print(); // Print all heap elements

    cout << "Enqueue 7 (g)" << endl;
    theHeap.push(HeapNode<string>(7, "g"));
    theHeap.print(); // Print all heap elements

    cout << "Enqueue 5 (h)" << endl;
    theHeap.push(HeapNode<string>(5, "h"));
    theHeap.print(); // Print all heap elements

   

 // Dequeue all elements
    while (theHeap.getSize() > 0) {
        cout << "Dequeue data: " << theHeap.pop().getData() << endl;
        theHeap.print(); // Print all heap elements
    }

    return 0;
}
```

### Explanation of Each Function

#### reheapUp

The `reheapUp` function restores the heap property after an insertion. Starting from the inserted node, it compares the node with its parent. If the inserted node's key is greater than its parent's key, they are swapped. This process repeats recursively until the node is in the correct position or it reaches the root.

```cpp
template <typename T>
void maxHeap<T>::reheapUp(int index) {
    // Node is already at root position
    if (index == 1) return;
    
    // Get the parent node
    int parent = index / 2;

    // Check if inserted node's priority is greater than parent's
    if (elements[parent].getKey() < elements[index].getKey()) {
        // Swap the nodes
        swap(elements[parent], elements[index]);

        // Recursive call to check next level
        reheapUp(parent);
    }
}
```

#### reheapDown

The `reheapDown` function restores the heap property after a deletion. Starting from the root node (where the last element was moved), it compares the node with its children. The larger child is chosen for comparison. If the chosen child's key is greater than the node's key, they are swapped. This process repeats recursively until the node is in the correct position or it reaches a leaf.

```cpp
template <typename T>
void maxHeap<T>::reheapDown(int index) {
    // At max index in tree
    if (2 * index > size) return;

    int chosenChild;

    // Only left child in subtree, must be left child
    if (2 * index == size) {
        chosenChild = size;
    } else {
        // Check if the left or right child is larger
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        chosenChild = (elements[leftChild].getKey() > elements[rightChild].getKey()) ? leftChild : rightChild;
    }

    // If child is larger than parent, swap
    if (elements[chosenChild].getKey() > elements[index].getKey()) {
        swap(elements[index], elements[chosenChild]);
        reheapDown(chosenChild);
    }
}
```

By understanding these functions and their implementation, you can see how a max heap efficiently maintains its properties during insertion and deletion operations. This ensures that the maximum element is always quickly accessible, making max heaps very useful in priority queue implementations and other applications where quick access to the largest element is required.
