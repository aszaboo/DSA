# Doubly Linked List Assignment

## Function Outline

### Node Constructor

```cpp
DoublyLinkedList::Node::Node(DataType data) 
    : value(data), prev(nullptr), next(nullptr) {}
```

- **Purpose**: Initializes a node with the given data, setting `prev` and `next` pointers to `nullptr`. This setup is necessary because the node is initially unconnected to any other nodes in the list.

### Linked List Constructor

```cpp
DoublyLinkedList::DoublyLinkedList() 
    : head_(nullptr), tail_(nullptr), size_(0) {}
```

- **Purpose**: Initializes an empty linked list by setting `head_` and `tail_` pointers to `nullptr` and `size_` to 0. This setup signifies an empty list with no elements.

### Linked List Destructor

```cpp
DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head_;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head_ = tail_ = nullptr;
}
```

- **Steps**:
  1. Set `current` to the head of the list.
  2. Iterate through the list, deleting each node.
  3. After deleting, move `current` to the next node.
  4. Set `head_` and `tail_` to `nullptr` to avoid dangling pointers.

- **Purpose**: Ensures that all dynamically allocated memory for nodes is properly freed when the list is destroyed. This prevents memory leaks and ensures that all resources are released.

### Size / Capacity

```cpp
unsigned int DoublyLinkedList::size() const {
    return size_;
}

unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}
```

- **Purpose**: Provides access to the current size of the list and its maximum capacity. This is crucial for managing the list's state and understanding its limits.

### Empty / Full

```cpp
bool DoublyLinkedList::empty() const {
    return size_ == 0;
}

bool DoublyLinkedList::full() const {
    return size_ == CAPACITY;
}
```

- **Purpose**: Checks whether the list is empty or full. This is useful for determining when operations like insertions or deletions are appropriate.

### Select

```cpp
DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    if (size_ == 0) return DataType(-999);  // List is empty, return sentinel value
    if (index >= size_) return tail_ ? tail_->value : DataType(-999);  // Return last element or sentinel

    Node* current;
    if (index < size_ / 2) {
        current = head_;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        current = tail_;
        for (unsigned int i = size_ - 1; i > index; --i) {
            current = current->prev;
        }
    }

    return current->value;
}
```

- **Steps**:
  1. Check if the list is empty; return a sentinel value if true.
  2. Check if the index is out of bounds; return the last element's value if true.
  3. Use the index to determine the closer end (head or tail) to start traversal.
  4. Traverse from the chosen end to the specified index.
  5. Return the value of the node at the specified index.

- **Optimization**: The doubly linked list's bidirectional traversal capability allows faster access to nodes by starting the traversal from the nearest end (either head or tail). This minimizes the traversal time compared to a singly linked list, which can only be traversed from the head.

### Search

```cpp
unsigned int DoublyLinkedList::search(DataType value) const {
    Node* current = head_;
    unsigned int index = 0;

    while (current != nullptr) {
        if (current->value == value) {
            return index;  // Value found, return the index
        }
        current = current->next;
        index++;
    }

    return size_;  // Value not found, return size_ as an indicator
}
```

- **Steps**:
  1. Start from the head of the list.
  2. Traverse the list, checking each node's value.
  3. If the value is found, return its index.
  4. If not found, return `size_` as an indicator.

- **Purpose**: Allows for locating the index of a specific value in the list. While the traversal itself doesn't benefit from bidirectional traversal, the doubly linked structure still facilitates efficient node manipulation once the target is found.

### Print

```cpp
void DoublyLinkedList::print() const {
    Node* current = head_;

    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " <-> "; // Bidirectional link indication
        }
        current = current->next;
    }
    std::cout << " -> nullptr" << std::endl; // Clearly mark the end of the list
}
```

- **Steps**:
  1. Start from the head of the list.
  2. Traverse through each node, printing the value.
  3. Print a separator for each node except the last.
  4. Mark the end of the list with "-> nullptr".

- **Purpose**: Provides a visual representation of the list's contents, showing both the values and the structure (connections between nodes).

### Get Node

```cpp
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    if (index >= size_) {
        return nullptr; // Index out of bounds, return nullptr
    }

    Node* current;
    if (index < size_ / 2) {
        current = head_;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        current = tail_;
        for (unsigned int i = size_ - 1; i > index; --i) {
            current = current->prev;
        }
    }

    return current;
}
```

- **Steps**:
  1. Check if the index is within bounds; return `nullptr` if not.
  2. Use the index to determine the closer end (head or tail) to start traversal.
  3. Traverse from the chosen end to the specified index.
  4. Return the node at the specified index.

- **Purpose**: Retrieves a pointer to the node at the specified index, facilitating operations like insertion, deletion, and value retrieval.

- **Optimization**: The bidirectional traversal capability allows starting from the head or tail, depending on the index's proximity, optimizing the time complexity of node access.

### Insert

```cpp
bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    if (index > size_ || size_ >= CAPACITY) return false;

    Node* newNode = new Node(value);

    if (head_ == nullptr) {
        head_ = tail_ = newNode;
    } else if (index == 0) {
        newNode->next = head_;
        head_->prev = newNode;
        head_ = newNode;
    } else if (index == size_) {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    } else {
        Node* current = getNode(index);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    size_++;
    return true;
}
```

- **Steps**:
  1. Check if the index is out of bounds or if the list is at capacity.
  2. Create a new node with the specified value.
  3. If the list is empty, set the new node as both the head and tail.
  4. If inserting at the head, update pointers to insert the new node at the beginning.
  5. If inserting at the tail, update pointers to insert the new node at the end.
  6. For inserting in the middle, use `getNode` to find the insertion point, and update the relevant pointers to insert the new node.
  7. Increment the size of the list.

- **Purpose**: Allows for inserting new elements at any position in the list. This function leverages the doubly linked list's properties to efficiently update pointers for both preceding and succeeding nodes.

- **Optimization**: The ability to traverse the list from both ends ensures that the insertion operation is as efficient as possible, particularly for large lists where the position is near the tail.

### Insert Front / Back

```cpp
bool DoublyLinkedList::insert_front(DataType value) {
    return insert(value, 0);
}

bool DoublyLinkedList::insert_back(DataType value) {
    return insert(value, size_);
}
```

- **Purpose**: These functions are specialized versions of the `insert` function, designed to insert elements specifically at the front or back of the list.

- **Optimization**: By directly

 calling `insert` with the appropriate index, these functions streamline the process of adding elements to the start or end of the list.

### Remove

```cpp
bool DoublyLinkedList::remove(unsigned int index) {
    if (index >= size_ || head_ == nullptr) return false;

    Node* toDelete = getNode(index);
    if (size_ == 1) {
        delete head_;
        head_ = tail_ = nullptr;
    } else if (index == 0) {
        head_ = head_->next;
        head_->prev = nullptr;
        delete toDelete;
    } else if (index == size_ - 1) {
        tail_ = tail_->prev;
        tail_->next = nullptr;
        delete toDelete;
    } else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        delete toDelete;
    }

    size_--;
    return true;
}
```

- **Steps**:
  1. Check if the index is out of bounds or if the list is empty.
  2. Use `getNode` to locate the node to be deleted.
  3. If the list has only one node, delete it and set head and tail to `nullptr`.
  4. If deleting the head node, update the head pointer and delete the node.
  5. If deleting the tail node, update the tail pointer and delete the node.
  6. If deleting a middle node, update the pointers of adjacent nodes and delete the node.
  7. Decrement the size of the list.

- **Purpose**: Removes a node at a specified index, adjusting pointers as needed to maintain the integrity of the list.

- **Optimization**: The doubly linked list's bidirectional pointers allow for efficient removal of nodes, as both the previous and next nodes can be easily updated without additional traversal.

### Remove Front / Back

```cpp
bool DoublyLinkedList::remove_front() {
    return remove(0);
}

bool DoublyLinkedList::remove_back() {
    return remove(size_ - 1);
}
```

- **Purpose**: These functions simplify the removal of nodes at the front or back of the list by calling the `remove` function with the appropriate index.

### Replace

```cpp
bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if (index >= size_) return false;
    Node* current = getNode(index);
    current->value = value;
    return true;
}
```

- **Steps**:
  1. Check if the index is within bounds.
  2. Use `getNode` to locate the node at the specified index.
  3. Replace the node's value with the new value.

- **Purpose**: Allows for updating the value of a node at a specific index. This function is useful for modifying the data stored in the list without changing its structure.

- **Optimization**: By using `getNode`, this function efficiently locates the node to be updated, leveraging the doubly linked list's structure for faster access.
