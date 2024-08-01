# Sequential List Assignment

## Function Outline

### List Constructor

```cpp
SequentialList::SequentialList(unsigned int cap) 
    : capacity_(cap >= 20 ? cap : 20), data_(new DataType[capacity_]), size_(0) {}
```

- **Purpose**: Initializes a sequential list with a specified capacity. Ensures a minimum capacity of 20. Allocates dynamic memory for the data array based on the capacity and initializes the size to 0.
- **Initialization**:
  - `capacity_`: Set to the provided `cap` if it is greater than or equal to 20, otherwise set to 20.
  - `data_`: Dynamically allocates an array of `DataType` with size `capacity_`.
  - `size_`: Initialized to 0, indicating an empty list.

### List Destructor

```cpp
SequentialList::~SequentialList() {
    delete[] data_;
    data_ = nullptr;
}
```

- **Purpose**: Ensures that all dynamically allocated memory for the data array is properly freed when the list is destroyed. This prevents memory leaks and releases resources.
- **Steps**:
  1. Deletes the dynamically allocated data array.
  2. Sets `data_` to `nullptr` to avoid dangling pointers.

### Size / Capacity

```cpp
unsigned int SequentialList::size() const {
    return size_;
}

unsigned int SequentialList::capacity() const {
    return capacity_;
}
```

- **Purpose**: Provides access to the current size of the list and its capacity.
- **Usage**:
  - `size()`: Returns the number of elements in the list.
  - `capacity()`: Returns the maximum number of elements the list can hold without resizing.

### Empty / Full

```cpp
bool SequentialList::empty() const {
    return size_ == 0;
}

bool SequentialList::full() const {
    return size_ == capacity_;
}
```

- **Purpose**: Checks whether the list is empty or full.
- **Usage**:
  - `empty()`: Returns `true` if the list has no elements, `false` otherwise.
  - `full()`: Returns `true` if the list has reached its capacity, `false` otherwise.

### Select

```cpp
SequentialList::DataType SequentialList::select(unsigned int index) const {
    if (index >= size_) return DataType(-999); // Ensure index is not negative since it's unsigned

    return data_[index];
}
```

- **Steps**:
  1. Check if the index is within bounds; return a sentinel value (-999) if not.
  2. Return the value at the specified index.
- **Purpose**: Retrieves the value at the specified index, providing access to list elements by index.

### Search

```cpp
unsigned int SequentialList::search(DataType val) const {
    for (unsigned int i = 0; i < size_; ++i) {
        if (data_[i] == val) return i;  // Value found, return the index
    }
    return size_;  // Value not found, return size_ as an indicator
}
```

- **Steps**:
  1. Iterate through the list.
  2. Return the index if the value is found.
  3. If not found, return `size_` as an indicator.
- **Purpose**: Finds the index of the specified value in the list. Returns the size of the list if the value is not found.

### Print

```cpp
void SequentialList::print() const {
    for (unsigned int i = 0; i < size_; ++i) {
        std::cout << data_[i] << " ";
    }
    std::cout << "\n";
}
```

- **Steps**:
  1. Iterate through the list.
  2. Print each element.
  3. Print a newline at the end.
- **Purpose**: Provides a visual representation of the list's contents.

### Insert

```cpp
bool SequentialList::insert(DataType val, unsigned int index) {
    if (index > size_) return false; // index cannot be larger than size

    // Resize if full
    if (full()) {
        DataType* newData = new DataType[capacity_ * 2];
        for (unsigned int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ *= 2;
    }

    // Shift elements to the right
    for (unsigned int i = size_; i > index; --i) {
        data_[i] = data_[i - 1];
    }

    // Insert new value
    data_[index] = val;
    ++size_;
    return true;    
}
```

- **Steps**:
  1. Check if the index is within bounds.
  2. If the list is full, allocate a new array with double the capacity, copy elements, and update `capacity_`.
  3. Shift elements to the right to make space for the new element.
  4. Insert the new value at the specified index.
  5. Increment the size.
- **Purpose**: Adds a new element at the specified index. Resizes the array if necessary to accommodate the new element.
- **Optimization**: Resizing the array by doubling the capacity ensures amortized constant time for insertions, minimizing the number of resizes needed.

- **Notes**: This order of operations is optimal as by first doubling the array (if needed), then moving all the elements after the insertion index to the right we avoid needing needing multiple instances of the shift operation.

### Insert Front / Back

```cpp
bool SequentialList::insert_front(DataType val) {
    return insert(val, 0);
}

bool SequentialList::insert_back(DataType val) {
    return insert(val, size_);
}
```

- **Purpose**: Specialized versions of the `insert` function to add elements at the front or back of the list.
- **Optimization**: Simplifies the process of adding elements to the start or end of the list by calling `insert` with the appropriate index.

### Remove

```cpp
bool SequentialList::remove(unsigned int index) {
    if (empty() || index >= size_) return false;

    // Shift elements to the left
    for (unsigned int i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }

    --size_;

    // Shrink the array if necessary
    if (size_ < capacity_ / 4 && capacity_ > 20) {
        unsigned int newCapacity = capacity_ / 2;
        newCapacity = newCapacity < 20 ? 20 : newCapacity;
        DataType* newData = new DataType[newCapacity];
        for (unsigned int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

    return true;
}
```

- **Steps**:
  1. Check if the list is empty or the index is out of bounds.
  2. Shift elements to the left to remove the element at the specified index.
  3. Decrement the size.
  4. Shrink the array if the size is less than a quarter of the capacity and the capacity is greater than 20.
- **Purpose**: Removes the element at the specified index, adjusting the size and capacity as needed.
- **Optimization**: Shifting elements ensures the list remains contiguous. Shrinking the array prevents wasted memory, maintaining efficiency.

- **Notes**: Note that the shifting of elements is done first as after the shifting we then look at the new size of the array and determine if a smaller one is needed. This saves excessive checks before and after.

### Remove Front / Back

```cpp
bool SequentialList::remove_front() {
    return remove(0);
}

bool SequentialList::remove_back() {
    return remove(size_ - 1);
}
```

- **Purpose**: Simplifies the removal of elements at the front or back of the list by calling the `remove` function with the appropriate index.

### Replace

```cpp
bool SequentialList::replace(unsigned int index, DataType val) {
    if (index >= size_) return false;
    data_[index] = val;
    return true;
}
```

- **Steps**:
  1. Check if the index is within bounds.
  2. Replace the value at the specified index with the new value.
- **Purpose**: Updates the value at the specified index. This function is useful for modifying data in the list without changing its structure.
- **Optimization**: Directly accesses the index to replace the value, ensuring constant time complexity.
