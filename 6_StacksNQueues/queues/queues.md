# Queue Data Structure

## What Is A Queue?

A queue is a sequential data structure with the special property that the first element added is the first to leave the data structure. This is referred to as First In First Out (FIFO).

### Queue Analogy

You can think of a queue like a line of people waiting at a bank; the first person to enter the bank will be served first, then the second, and once everyone before them has been helped, the last person in the line will be helped.

![Queue Visualization](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20230726165642/Queue-Data-structure1.png "Queue")

## Common Uses for Queues

Queues are commonly used in problems where elements need to be processed in the order they arrive, such as managing tasks in a printer, handling requests on a server, or implementing breadth-first search in algorithms.

## Queue Data Structure Implementation

The queue data structure can be implemented in two main ways: using a sequential list (array) and using a linked list.

### Sequential List Implementation

```cpp
template<typename DataType>
class Queue {
private:
    unsigned int capacity_;   // The capacity of the queue
    unsigned int size_;       // The current size of the queue
    unsigned int front_;      // The front index
    unsigned int rear_;       // The rear index
    DataType* data_;          // Pointer to the array holding the elements

    // Function to resize the queue when it's full
    void resize() {
        unsigned int newCapacity = capacity_ * 2;
        DataType* newData = new DataType[newCapacity];

        for (unsigned int i = 0; i < size_; i++) {
            newData[i] = data_[(front_ + i) % capacity_];
        }

        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
        front_ = 0;
        rear_ = size_;
    }

public:
    // Constructor
    Queue(unsigned int cap = 10) 
        : capacity_(cap), size_(0), front_(0), rear_(0), data_(new DataType[capacity_]) {}

    // Destructor
    ~Queue() {
        delete[] data_;  // Clear all dynamically allocated memory
    }

    // Get capacity
    unsigned int getCapacity() const {
        return capacity_;
    }

    // Get size
    unsigned int getSize() const {
        return size_;
    }

    // Check if full
    bool full() const {
        return size_ == capacity_;
    }

    // Check if empty
    bool empty() const {
        return size_ == 0;
    }

    // Enqueue an element into the queue
    bool enqueue(DataType val) {
        if (full()) {
            resize();  // Resize the array if full
        }

        data_[rear_] = val;
        rear_ = (rear_ + 1) % capacity_;
        size_++;
        return true;
    }

    // Dequeue an element from the queue
    bool dequeue() {
        if (empty()) return false;  // Queue empty

        front_ = (front_ + 1) % capacity_;
        size_--;
        return true;
    }

    // Peek at the front element
    DataType peek() const {
        if (empty()) return DataType(-999);  // Return sentinel value if empty

        return data_[front_];  // Return the front value
    }
};
```

The sequential list implementation must always enqueue and dequeue from opposite ends to ensure that the FIFO property is maintained. To improve efficiency and avoid O(n) time complexity for dequeue operations, a circular array can be used.

### Circular Array

A circular array, also known as a ring buffer, is an array that wraps around when it reaches the end. This allows both enqueue and dequeue operations to be performed in constant time, O(1).

### Singly Linked List Implementation

```cpp
template<typename DataType>
class SinglyQueue {
private:
    struct Node {
        DataType data;
        Node* next;
        Node(DataType val) : data(val), next(nullptr) {}
        ~Node() {}
    };

    Node* head_;          // Pointer to the head node
    Node* tail_;          // Pointer to the tail node
    unsigned int capacity_;
    unsigned int size_;

public:
    // Constructor
    SinglyQueue(unsigned int cap) 
        : head_(nullptr), tail_(nullptr), capacity_(cap), size_(0) {}

    // Destructor
    ~SinglyQueue() {
        while (head_ != nullptr) {
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
        }
    }

    // Get capacity
    unsigned int getCapacity() const {
        return capacity_;
    }

    // Get size
    unsigned int getSize() const {
        return size_;
    }

    // Check if empty
    bool empty() const {
        return size_ == 0;
    }

    // Enqueue an element into the queue
    bool enqueue(DataType val) {
        Node* newNode = new Node(val);

        if (empty()) {
            head_ = tail_ = newNode;
        } else { 
            tail_->next = newNode;
            tail_ = newNode;
        }
        size_++;
        return true;
    }

    // Dequeue an element from the queue
    bool dequeue() {
        if (empty()) return false;  // Queue empty

        Node* temp = head_->next;
        delete head_;
        head_ = temp;
        size_--;
        return true;
    }

    // Peek at the front element
    DataType peek() const {
        if (empty()) return DataType(-999);  // Return sentinel value if empty
        return head_->data;
    }
};
```

Note that for a singly linked implementation of a queue, data entries should always be enqueued (inserted) at the tail and dequeued (deleted) from the head to maintain O(1) time complexity for these operations.

### Use Cases

- **When to Use:** Sequential lists are ideal when fast access, insertion, and deletion at the end are needed. They are commonly used for dynamic arrays, buffers, and other scenarios where elements need to be stored and accessed in sequence.
- **When Not to Use:** If frequent insertions and deletions at arbitrary positions are required, especially in large lists, other data structures like linked lists may be more efficient due to the cost of shifting elements in a sequential list.

### Memory Management

- **Capacity vs. Size:** Distinguish between `capacity_` (the total number of elements that can be stored without resizing) and `size_` (the current number of elements in the list). It's important to manage these carefully to avoid unnecessary resizing operations, which can be costly.
- **Resizing Strategies:** When the list reaches its capacity, resizing often involves allocating a new, larger block of memory (typically doubling the current capacity) and copying existing elements. This strategy helps maintain efficient amortized time for insertion operations.
- **Shrinking Strategies:** When the list becomes significantly under-utilized (e.g., less than 25% full), resizing to a smaller capacity (typically half of the current capacity) helps reclaim unused memory, maintaining efficiency.

### Operation Time Complexity Comparison

| Operation | Singly Linked List | Doubly Linked List | Sequential (Array-based) |
|-----------|--------------------|--------------------|--------------------------|
| Enqueue   | O(1)               | O(1)               | O(1) (amortized)         |
| Dequeue   | O(1)               | O(1)               | O(1)                     |
| Peek      | O(1)               | O(1)               | O(1)                     |

### Space Overhead Comparison

| Data Structure         | Overhead Memory per Node/Element |
|------------------------|----------------------------------|
| Singly Linked List     | 1 pointer (next)                |
| Doubly Linked List     | 2 pointers (next, prev)         |
| Sequential (Array-based)| No per-node overhead           |

#### Explanation

- **Singly Linked List**:
  - **Enqueue**: Constant time because it just involves adding a node at the tail.
  - **Dequeue**: Constant time because it just involves removing the node from the head.
  - **Peek**: Constant time because it just involves accessing the data at the head.
  - **Space Overhead**: Each node requires additional memory for one pointer (to the next node).

- **Doubly Linked List**:
  - **Enqueue**: Constant time because it involves adding a node at the tail and updating two pointers.
  - **Dequeue**: Constant time because it involves removing the node from the head and updating two pointers.
  - **Peek**: Constant time because it just involves accessing the data at the head.
  - **Space Overhead**: Each node requires additional memory for two pointers (to the next and previous nodes).

- **Sequential (Array-based)**:
  - **Enqueue**: Amortized constant time. When the array is full, the array is resized (doubled in size), which is an O(n) operation. However, over a series of enqueues, the average time is O(1).
  - **Dequeue**: Constant time because it just involves reducing the size and potentially shrinking the array (which can be an O(n) operation but is less frequent).
  - **Peek**: Constant time because it just involves accessing the first element.


  - **Space Overhead**: No per-node overhead, but there can be unused allocated memory if the capacity is larger than the size.

### Summary

- **Singly Linked List** is space-efficient with constant time operations but has per-node overhead for storing the next pointer.
- **Doubly Linked List** offers bidirectional traversal with constant time operations but has higher per-node overhead for storing both next and prev pointers.
- **Sequential (Array-based)** provides fast average-case operations and no per-node overhead, but resizing can be costly and there can be unused allocated memory.