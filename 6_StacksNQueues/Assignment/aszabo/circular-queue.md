# Circular Queue Assignment

## Function Outline

### Circular Queue Constants

```cpp
const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;
```

- **Purpose**: Defines a sentinel value to represent an empty queue. This is used for operations like `peek()` and `dequeue()` to indicate that the queue is empty.

### Default Constructor

```cpp
CircularQueue::CircularQueue() {
    capacity_ = 16;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
    size_ = 0;
}
```

- **Purpose**: Initializes a circular queue with a default capacity of 16. Allocates memory for the queue and sets the initial size to 0.
- **Steps**:
  1. Set `capacity_` to 16.
  2. Allocate memory for `items_`.
  3. Initialize `head_`, `tail_`, and `size_` to 0.

### Parameterized Constructor

```cpp
CircularQueue::CircularQueue(unsigned int capacity) {
    capacity < 16 ? capacity_ = 16 : capacity_ = capacity;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
    size_ = 0;
}
```

- **Purpose**: Initializes a circular queue with a user-defined capacity, ensuring a minimum capacity of 16. Allocates memory for the queue and sets the initial size to 0.
- **Steps**:
  1. Set `capacity_` to the provided capacity if it's 16 or more; otherwise, set it to 16.
  2. Allocate memory for `items_`.
  3. Initialize `head_`, `tail_`, and `size_` to 0.

### Destructor

```cpp
CircularQueue::~CircularQueue() {
    delete[] items_;
}
```

- **Purpose**: Cleans up dynamically allocated memory when the queue is destroyed to prevent memory leaks.
- **Steps**:
  1. Deallocate memory for `items_`.

### Resize

```cpp
void CircularQueue::resize() {
    QueueItem* newQueue = new QueueItem[capacity_ * 2];

    unsigned int index = head_;
    for (unsigned int i = 0; i < size_; ++i) {
        newQueue[i] = items_[index];
        index = (index + 1) % capacity_;
    }

    delete[] items_;
    items_ = newQueue;
    head_ = 0;
    tail_ = size_;
    capacity_ *= 2;
}
```

- **Purpose**: Doubles the capacity of the queue when it is full. Copies existing elements to a new array with the updated capacity.
- **Steps**:
  1. Allocate a new array with double the current capacity.
  2. Copy elements from the old array to the new array, respecting the circular indexing.
  3. Deallocate the old array and update pointers.
  4. Reset `head_` to 0 and `tail_` to the current size.
  5. Double the capacity.

### Shrink

```cpp
void CircularQueue::shrink() {
    if (capacity_ <= 16) return;

    QueueItem* newQueue = new QueueItem[capacity_ / 2];

    unsigned int index = head_;
    for (unsigned int i = 0; i < size_; ++i) {
        newQueue[i] = items_[index];
        index = (index + 1) % capacity_;
    }

    delete[] items_;
    items_ = newQueue;
    head_ = 0;
    tail_ = size_;
    capacity_ /= 2;
}
```

- **Purpose**: Halves the capacity of the queue when it is less than or equal to a quarter full and greater than the minimum capacity of 16. Copies existing elements to a new array with the reduced capacity.
- **Steps**:
  1. Check if the capacity is already at or below the minimum threshold; if so, return.
  2. Allocate a new array with half the current capacity.
  3. Copy elements from the old array to the new array, respecting the circular indexing.
  4. Deallocate the old array and update pointers.
  5. Reset `head_` to 0 and `tail_` to the current size.
  6. Halve the capacity.

### Size

```cpp
unsigned int CircularQueue::size() const {
    return size_;
}
```

- **Purpose**: Returns the current size of the queue, representing the number of elements in the queue.

### Empty

```cpp
bool CircularQueue::empty() const {
    return size_ == 0;
}
```

- **Purpose**: Checks if the queue is empty. Returns `true` if the queue size is 0.

### Full

```cpp
bool CircularQueue::full() const {
    return size_ == capacity_;
}
```

- **Purpose**: Checks if the queue is full. Returns `true` if the queue size is equal to the capacity.

### Peek

```cpp
CircularQueue::QueueItem CircularQueue::peek() const {
    if (empty()) return EMPTY_QUEUE;
    return items_[head_];
}
```

- **Purpose**: Returns the front item of the queue without removing it. If the queue is empty, returns the sentinel value `EMPTY_QUEUE`.
- **Steps**:
  1. Check if the queue is empty.
  2. If not empty, return the front item.

### Enqueue

```cpp
bool CircularQueue::enqueue(QueueItem value) {
    if (full()) {
        resize();
    }

    items_[tail_] = value; 
    tail_ = (tail_ + 1) % capacity_;
    size_++;
    return true;
}
```

- **Purpose**: Adds a new item to the back of the queue. If the queue is full, it resizes the underlying array to double its current capacity.
- **Steps**:
  1. Check if the queue is full.
  2. If full, call `resize()` to double the capacity.
  3. Add the new item to the position pointed by `tail_`.
  4. Increment `tail_` and use modulo operation to wrap around if necessary.
  5. Increment the queue size.

### Dequeue

```cpp
CircularQueue::QueueItem CircularQueue::dequeue() {
    if (empty()) return EMPTY_QUEUE;

    QueueItem value = items_[head_];
    head_ = (head_ + 1) % capacity_;
    size_--;

    if (size_ > 0 && size_ <= capacity_ / 4) {
        shrink();
    }

    return value;
}
```

- **Purpose**: Removes and returns the front item from the queue. If the queue size falls below a quarter of its capacity and the capacity is greater than the minimum threshold, it shrinks the array to half its current capacity.
- **Steps**:
  1. Check if the queue is empty.
  2. Remove and store the front item.
  3. Increment `head_` and use modulo operation to wrap around if necessary.
  4. Decrement the queue size.
  5. If necessary, call `shrink()` to reduce the capacity.

### Print

```cpp
void CircularQueue::print() const {
    unsigned int index = head_;
    for (unsigned int i = 0; i < size_; ++i) {
        std::cout << items_[index] << " ";
        index = (index + 1) % capacity_;
    }
    std::cout << "end" << std::endl;
}
```

- **Purpose**: Prints the elements of the queue from front to back, providing a visual representation of the queue's contents.
- **Steps**:
  1. Loop through the queue from front to back.
  2. Print each item.
  3. Mark the end of the queue with "end".

### Reflection

The Circular Queue implementation involves several key functions to manage a queue with dynamic resizing capabilities. The circular nature of the queue allows efficient use of space and ensures that both enqueue and dequeue operations are performed in constant time, O(1).

- **Circular Indexing**: The use of modulo operations ensures that the indices wrap around when they reach the end of the array, maintaining the circular nature of the queue. This logic is crucial for efficient enqueue and dequeue operations without shifting elements.

- **Dynamic Resizing**: The queue resizes the array to maintain efficient space utilization and performance. Doubling the capacity when full ensures that the queue can handle more elements without frequent resizing. Halving the capacity when the queue is too empty prevents wasted memory but ensures the capacity does not fall below the minimum threshold of 16.

- **Efficiency**: The queue operations (enqueue, dequeue, peek) are optimized for O(1) time complexity, ensuring fast and predictable performance. The resizing operations, though O(n) in complexity, are infrequent and ensure that the average time complexity remains efficient.

- **Memory Management**: The destructor ensures that dynamically allocated memory is properly released, preventing memory leaks. The implementation carefully manages memory allocation and deallocation during resizing operations.