# Dynamic Stack Assignment

## Function Outline

### Dynamic Stack Constants

```cpp
const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;
```

- **Purpose**: Defines a sentinel value to represent an empty stack. This is used for operations like `peek()` and `pop()` to indicate that the stack is empty.

### Default Constructor

```cpp
DynamicStack::DynamicStack() {
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    items_ = new StackItem[capacity_];
    size_ = 0;
}
```

- **Purpose**: Initializes a dynamic stack with a default capacity of 16. Allocates memory for the stack and sets the initial size to 0.
- **Steps**:
  1. Set `init_capacity_` and `capacity_` to 16.
  2. Allocate memory for `items_`.
  3. Initialize `size_` to 0.

### Parameterized Constructor

```cpp
DynamicStack::DynamicStack(unsigned int capacity){
    init_capacity_ = capacity;
    capacity_ = init_capacity_;
    items_ = new StackItem[capacity_];
    size_ = 0;
}
```

- **Purpose**: Initializes a dynamic stack with a user-defined capacity. Allocates memory for the stack and sets the initial size to 0.
- **Steps**:
  1. Set `init_capacity_` and `capacity_` to the provided capacity.
  2. Allocate memory for `items_`.
  3. Initialize `size_` to 0.

### Destructor

```cpp
DynamicStack::~DynamicStack() {
    delete[] items_;
}
```

- **Purpose**: Cleans up dynamically allocated memory when the stack is destroyed to prevent memory leaks.
- **Steps**:
  1. Deallocate memory for `items_`.

### Size

```cpp
unsigned int DynamicStack::size() const {
    return size_;
}
```

- **Purpose**: Returns the current size of the stack, representing the number of elements in the stack.

### Empty

```cpp
bool DynamicStack::empty() const {
    return size_ == 0;
}
```

- **Purpose**: Checks if the stack is empty. Returns `true` if the stack size is 0.

### Peek

```cpp
DynamicStack::StackItem DynamicStack::peek() const {
    if (empty()) return EMPTY_STACK;
    return items_[size_ - 1];
}
```

- **Purpose**: Returns the top item of the stack without removing it. If the stack is empty, returns the sentinel value `EMPTY_STACK`.
- **Steps**:
  1. Check if the stack is empty.
  2. If not empty, return the top item.

### Push

```cpp
void DynamicStack::push(StackItem value) {
    if (size_ == capacity_) {
        StackItem* newStack = new StackItem[capacity_ * 2];
        for (unsigned int i = 0; i < size_; ++i) {
            newStack[i] = items_[i];
        }

        delete[] items_;
        items_ = newStack;
        capacity_ *= 2;
    }

    items_[size_] = value;
    size_++;
}
```

- **Purpose**: Adds a new item to the top of the stack. If the stack is full, it resizes the underlying array to double its current capacity.
- **Steps**:
  1. Check if the stack is full.
  2. If full, allocate a new array with double the capacity.
  3. Copy existing items to the new array.
  4. Delete the old array and update `items_` to point to the new array.
  5. Add the new item to the top of the stack.
  6. Increment the stack size.

### Pop

```cpp
DynamicStack::StackItem DynamicStack::pop() {
    if (empty()) return EMPTY_STACK;

    if (size_ < capacity_ / 4 && capacity_ > init_capacity_) {
        StackItem* newStack = new StackItem[capacity_ / 2];
        for (unsigned int i = 0; i < size_; ++i) {
            newStack[i] = items_[i];
        }

        delete[] items_;
        items_ = newStack;
        capacity_ /= 2;
    }

    StackItem popped = items_[size_ - 1];
    size_--;
    return popped;
}
```

- **Purpose**: Removes and returns the top item from the stack. If the stack size falls below a quarter of its capacity, it resizes the array to half its current capacity, but not below the initial capacity.
- **Steps**:
  1. Check if the stack is empty.
  2. If the stack size is less than a quarter of the capacity and greater than the initial capacity, allocate a new array with half the capacity.
  3. Copy existing items to the new array.
  4. Delete the old array and update `items_` to point to the new array.
  5. Remove and return the top item.
  6. Decrement the stack size.

### Print

```cpp
void DynamicStack::print() const {
    for (unsigned int i = size_; i > 0; --i) {
        std::cout << items_[i - 1] << " ";
    }
    std::cout << "end" << std::endl;
}
```

- **Purpose**: Prints the elements of the stack from top to bottom, providing a visual representation of the stack's contents.
- **Steps**:
  1. Loop through the stack from top to bottom.
  2. Print each item.
  3. Mark the end of the stack with "end".

### Reflection

The Dynamic Stack implementation involves several key functions to manage a stack with dynamic resizing capabilities. The stack ensures efficient memory use by resizing the underlying array when necessary, either expanding it when the stack is full or shrinking it when the stack is too empty. This dynamic resizing maintains efficient average-case performance for stack operations.

- **Dynamic Resizing**: The stack resizes the array to maintain efficient space utilization and performance. Doubling the capacity when full ensures that the stack can handle more elements without frequent resizing. Halving the capacity when the stack is too empty prevents wasted memory but ensures the capacity does not fall below the initial capacity.

- **Efficiency**: The stack operations (push, pop, peek) are optimized for O(1) time complexity, ensuring fast and predictable performance. The resizing operations, though O(n) in complexity, are infrequent and ensure that the average time complexity remains efficient.

- **Memory Management**: The destructor ensures that dynamically allocated memory is properly released, preventing memory leaks. The implementation carefully manages memory allocation and deallocation during resizing operations.
