#include <iostream>
#include <string>

using namespace std;

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

// maxHeap Class
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
// Initialize size to 0 and allocate memory for heap elements
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
