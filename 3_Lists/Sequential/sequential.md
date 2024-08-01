# Sequential Lists

## What is a Sequential List?

A sequential list in C++ is akin to an array but with enhanced functionality. C++ provides a data structure called a `vector`, which serves as a dynamic array. A vector offers features such as variable size, insertions, deletions, and methods like `begin()` and `end()` to access the start and end of the list, respectively. These features abstract the complexities of manual memory management and provide a more user-friendly interface for list operations.

## Properties of a Sequential List

A sequential list, being based on an array, stores its elements contiguously in memory. This contiguous allocation (where each element is stored next to the previous one without gaps) typically occurs on the heap rather than the stack, particularly for dynamically sized lists. This is because the heap allows for the flexible allocation and deallocation of memory, which is essential for data structures where the size is not known at compile time.

## List Structure

```cpp
class SequentialList {

private:
    unsigned int capacity_; // Maximum number of elements the list can hold
    unsigned int size_;     // Current number of elements in the list
    DataType* data_;        // Pointer to the array holding the list elements

public:
    // Constructor
    SequentialList(unsigned int cap);

    // Destructor
    ~SequentialList();

    // Helper functions
};
```

### Key Properties

1. **Contiguous Memory Allocation**: All elements are stored in contiguous memory locations (each element is stored next to the previous one without gaps), which enhances cache performance and enables efficient indexing.

2. **Dynamic Sizing**: The list can grow or shrink dynamically, with memory allocation and deallocation managed automatically.

3. **Heap Storage**: By storing elements on the heap, sequential lists avoid the limitations of stack size and allow for large data structures.

## Performance Characteristics

1. **Quick Insert, Replace, and Search O(1)**:
   - These operations are efficient for accessing or modifying elements at specific positions, leveraging the array's ability to provide constant-time access via indexing.

2. **Slow Delete O(n)**:
   - Deleting an element, especially not at the end of the list, requires shifting all subsequent elements one position to the left to fill the gap. This shift operation is linear in complexity, making deletion relatively costly in terms of performance.

3. **Variable Size**:
   - The capacity of a sequential list can be increased or decreased dynamically. However, resizing (especially growing the list) can involve copying all elements to a new, larger memory block, which is an O(n) operation. Despite this, such resizes are amortized over multiple insertions, making the average time per insertion relatively low.

## Use Cases

- **When to Use**: Sequential lists are ideal when fast access, insertion, and deletion at the end are needed. They are commonly used for dynamic arrays, buffers, and other scenarios where elements need to be stored and accessed in sequence.

- **When Not to Use**: If frequent insertions and deletions at arbitrary positions are required, especially in large lists, other data structures like linked lists may be more efficient due to the cost of shifting elements in a vector.

## Memory Management

- **Resizing Strategies**: When the list reaches its capacity, resizing involves allocating a new, larger block of memory (often doubling the current capacity) and copying existing elements into it. This approach maintains efficient amortized time for insertion operations, as the number of resizing operations is minimized. A standard approach for shrinking the array is when the size of the array is 25% of the capacity a new array of 50% of the size is made and elements are copied over.
