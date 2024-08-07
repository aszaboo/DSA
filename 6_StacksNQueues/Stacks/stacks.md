# Stack Data Structure

## What Is A Stack?

A stack is a sequential data structure with the special property that the first element added is the last to leave the data structure. This is referred to as First In Last Out (FILO).

### Stack Analogy

You can think of a stack like plates stacked on top of one another; the first plate in the stack will be the last one to be removed from the pile.

![Stack Visualization](https://media.geeksforgeeks.org/wp-content/uploads/20230116192305/stack-768.png "Stack")

## Common Uses for Stacks

Stacks are commonly used in problems where you need to manage function calls, reverse strings, check for balanced parentheses, or implement algorithms like depth-first search.

## Stack Data Structure Implementation

The stack data structure can be implemented in two main ways: using a sequential list (array) and using a linked list.

### Sequential List Implementation

```cpp
template<typename DataType>
class Stack {
private:
    unsigned int capacity_;   // The capacity of the stack
    unsigned int size_;       // The current size of the stack
    DataType* data_;          // Pointer to the array holding the elements

    // Function to resize the stack when it's full
    void resize() {
        unsigned int newCapacity = capacity_ * 2;
        DataType* newData = new DataType[newCapacity];

        for (unsigned int i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }

        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

    // Function to shrink the stack when it's too empty
    void shrink() {
        if (capacity_ <= 1) return; // Avoid shrinking if capacity is already at minimum (1)

        unsigned int newCapacity = capacity_ / 2;
        DataType* newData = new DataType[newCapacity];

        for (unsigned int i = 0; i < size_; i++) {
            newData[i] = data_[i];
        }

        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

public:
    // Constructor
    Stack(unsigned int cap = 10) : capacity_(cap), size_(0), data_(new DataType[capacity_]) {}

    // Destructor
    ~Stack() {
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

    // Push an element onto the stack
    bool push(DataType val) {
        if (full()) {
            resize();  // Resize the array if full
        }

        data_[size_] = val;  // Insert at end for O(1) insertion time
        size_++;
        return true;
    }

    // Pop an element from the stack
    bool pop() {
        if (empty()) return false;  // Stack empty

        size_--;  // Not empty
        if (size_ <= capacity_ / 4) {
            shrink();  // Shrink the array if too empty
        }
        return true;
    }

    // Peek at the top element
    DataType peek() const {
        if (empty()) return DataType(-999);  // Return sentinel value if empty

        return data_[size_ - 1];  // Return last value in array
    }
};
```

The sequential list implementation should always push and pop from the end of the list. This guarantees O(1) insertion (push) and deletion (pop) as the list never needs to be reformatted to fill in gaps, which would occur if popping from the front of the list.

### Singly Linked List Implementation

```cpp
template<typename DataType>
class StackLinked {
private:
    struct Node {
        DataType data;
        Node* next;
        Node(DataType val) : data(val), next(nullptr) {}
        ~Node() {}
    };

    Node* head_;          // Pointer to the head node
    unsigned int capacity_;
    unsigned int size_;

public:
    // Constructor
    StackLinked(unsigned int cap) : head_(nullptr), capacity_(cap), size_(0) {}

    // Destructor
    ~StackLinked() {
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

    // Check if full
    bool full() const {
        return size_ == capacity_;
    }

    // Check if empty
    bool empty() const {
        return size_ == 0;
    }

    // Push an element onto the stack
    bool push(DataType val) {
        if (full()) return false;  // Stack full

        Node* newNode = new Node(val);
        newNode->next = head_;
        head_ = newNode;
        size_++;
        return true;
    }

    // Pop an element from the stack
    bool pop() {
        if (empty()) return false;  // Stack empty

        Node* temp = head_->next;
        delete head_;
        head_ = temp;
        size_--;
        return true;
    }

    // Peek at the top element
    DataType peek() const {
        if (empty()) return DataType(-999);  // Return sentinel value if empty
        return head_->data;
    }
};
```

Note that for a singly linked implementation of a stack, data entries should always be pushed (inserted) and popped (deleted) from the head to maintain O(1) time complexity for these operations.

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
| Push      | O(1)               | O(1)               | O(1) (amortized)         |
| Pop       | O(1)               | O(1)               | O(1)                     |
| Peek      | O(1)               | O(1)               | O(1)                     |

### Space Overhead Comparison

| Data Structure         | Overhead Memory per Node/Element |
|------------------------|----------------------------------|
| Singly Linked List     | 1 pointer (next)                |
| Doubly Linked List     | 2 pointers (next, prev)         |
| Sequential (Array-based)| No per-node overhead           |

#### Explanation

- **Singly Linked List**:
  - **Push**: Constant time because it just involves adding a node at the head.
  - **Pop**: Constant time because it just involves removing the node from the head.
  - **Peek**: Constant time because it just involves accessing the data at the head.
  - **Space Overhead**: Each node requires additional memory for one pointer (to the next node).

- **Doubly Linked List**:
  - **Push**: Constant time because it involves adding a node at the head and updating two pointers.
  - **Pop**: Constant time because it involves removing the node from the head and updating two pointers.
  - **Peek**: Constant time because it just involves accessing the data at the head.
  - **Space Overhead**: Each node requires additional memory for two pointers (to the next and previous nodes).

- **Sequential (Array-based)**:
  - **Push**: Amortized constant time. When the array is full, the array is resized (doubled in size), which is an O(n) operation. However, over a series of pushes, the average time is O(1).
  - **Pop**: Constant time because it just involves reducing the size and potentially shrinking the array (which can be an O(n) operation but is less frequent).
  - **Peek**: Constant time because it just involves accessing the last element.
  - **Space Overhead**: No per-node overhead, but there can be unused allocated memory if the capacity is

 larger than the size.

### Summary

- **Singly Linked List** is space-efficient with constant time operations but has per-node overhead for storing the next pointer.
- **Doubly Linked List** offers bidirectional traversal with constant time operations but has higher per-node overhead for storing both next and prev pointers.
- **Sequential (Array-based)** provides fast average-case operations and no per-node overhead, but resizing can be costly and there can be unused allocated memory.
