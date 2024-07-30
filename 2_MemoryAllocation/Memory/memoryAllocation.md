### Static vs. Dynamic Memory Allocation in C++

#### Static Memory Allocation (Automatic)

- **Definition:** Memory allocated at compile time on the stack. The size and lifetime are fixed and determined at compile time.
- **Characteristics:** Fast allocation/deallocation, limited flexibility, automatic memory management.
- **Example:**

  ```cpp
  int arr[100]; // Fixed-size array, statically allocated
  ```

#### Dynamic Memory Allocation (Manual)

- **Definition:** Memory allocated at runtime on the heap using operators like `new` and `new[]`, which must be manually managed.
- **Characteristics:** Flexible size, manual memory management required, slower allocation/deallocation due to heap management.
- **Example:**

  ```cpp
  int* ptr = new int;       // Allocates a single int
  int* arr = new int[100];  // Allocates an array of 100 ints
  ```

### Memory Management Operators

1. **Pointer Declaration:**
   - **Definition:** Pointers store the address of variables. Declared with an asterisk (`*`).
   - **Example:**

     ```cpp
     int* p; // Pointer to an int
     ```

2. **Address-of Operator (`&`):**
   - **Definition:** Retrieves the memory address of a variable.
   - **Example:**

     ```cpp
     int value = 42;
     int* p = &value; // p stores the address of value
     ```

3. **Dereferencing Operator (`*`):**
   - **Definition:** Accesses the value at the address stored in a pointer.
   - **Example:**

     ```cpp
     int value = 42;
     int* p = &value;
     int deref = *p; // deref is now 42
     ```

### `new` vs `new[]` and `delete` vs `delete[]`

- **`new` and `delete`:**
  - **Purpose:** `new` allocates a single object; `delete` deallocates it.
  - **Example:**

    ```cpp
    int* ptr = new int(5); // Allocates a single int initialized to 5
    delete ptr;            // Deallocates the int
    ```

- **`new[]` and `delete[]`:**
  - **Purpose:** `new[]` allocates an array of objects; `delete[]` deallocates it.
  - **Example:**

    ```cpp
    int* arr = new int[100]; // Allocates an array of 100 ints
    delete[] arr;            // Deallocates the array
    ```

**Key Points:**

- **Memory Leaks:** Occur if allocated memory is not properly deallocated.
- **Dangling Pointers:** Pointers that reference deallocated memory should be set to `nullptr` after deletion to prevent undefined behavior.
- **Smart Pointers:** Use `std::unique_ptr` or `std::shared_ptr` to manage dynamic memory automatically, preventing memory leaks and dangling pointers.

### Best Practices for Memory Management

- **Always pair `new` with `delete` and `new[]` with `delete[]`.**
- **Use smart pointers (`std::unique_ptr`, `std::shared_ptr`) for automatic memory management.**
- **Avoid dynamic memory allocation when stack allocation is sufficient.**
- **Regularly check for memory leaks and dangling pointers in your code.**

### C++ Memory Management Exercise

Examine the following C++ program:

```cpp
#include <iostream>
using namespace std;

int** create2DArray(int rows, int cols) {
    int** arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    return arr;
}

void initialize2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = i * cols + j;
        }
    }
}

void print2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void delete2DArray(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    int rows = 3, cols = 4;

    int** my2DArray = create2DArray(rows, cols);
    initialize2DArray(my2DArray, rows, cols);
    print2DArray(my2DArray, rows, cols);

    int* leakedPtr = new int(42);

    int* uninitializedPtr;

    int value = 10;
    int* ptr = &value;
    int** ptrToPtr = &ptr;

    cout << "Value: " << value << endl;
    cout << "Pointer to value: " << *ptr << endl;
    cout << "Pointer to pointer to value: " << **ptrToPtr << endl;

    delete2DArray(my2DArray);

    return 0;
}
```

### Questions

1. **Dynamic Memory Allocation:**
   - Describe how the 2D array is allocated in the `create2DArray` function. What does the function return?

   - ANS: The function creates a dynamically allocated 2D array, and return a pointer to the memory address of that array

2. **Memory Leaks:**
   - Identify the line in the `main` function that leads to a memory leak. Explain why it causes a memory leak and how you would fix it.

   - ANS: the leakedPtr is initialized with dynamic memory but never deallocated creating a memory leak. To fix it delete should be called before the program exits.

3. **Uninitialized Pointers:**
   - What is the potential issue with the `uninitializedPtr` variable? Why is using it without initialization problematic?

   - ANS: If it is called it will lead to undefined behavior as it points to a memory address that has not been assigned.

4. **Pointer to Pointer:**
   - Explain the concept of a pointer to a pointer using the variables `ptr` and `ptrToPtr` in the `main` function. What do `ptr` and `ptrToPtr` each point to?

   - ANS: prt points to the memory address of the variable value, ptrToPtr points to the memory address of ptr.

5. **Memory Deallocation:**
   - The `delete2DArray` function deallocates the 2D array. What could happen if this function is not called, and why is it important to pair every `new[]` with `delete[]`?

   - ANS: If the function is not called the memory assigned to this array is not freed until after the execution of the program and thus cannot be used for other operations. The new[] and delete[] operators must be called together as new[] assigns a block of memory and delete[] deallocates that block of memory. If delete was used instead only the first memory address would be cleared, leading to a memory leak.

6. **General Memory Management:**
   - Discuss the difference between `new` and `new[]`, as well as `delete` and `delete[]`. Why is it crucial to use the correct form of `delete`?

   - ANS: new assigns a single memory address, new[] assigns a block of memory. delete clears a single memory address, delete[] clears a block of assigned memory. Pairing delete with new and delete[] with new[] is essential to make sure all memory is cleared, and preventing memory leaks.

7. **Program Modification:**
   - Modify the program to ensure that all dynamically allocated memory is properly managed, including fixing any identified memory leaks and ensuring the program does not attempt to access uninitialized memory.

```cpp
#include <iostream>
using namespace std;

int** create2DArray(int rows, int cols) { // Input: int, int -> Output: int pointer address
    int** arr = new int*[rows]; // dynamically allocate the memory for the rows
    for (int i = 0; i < rows; ++i) { // iterate over rows
        arr[i] = new int[cols]; // dynamically allocate the memory for the cols of each row
    }
    return arr; // return the address of the pointer to the array
}

void initialize2DArray(int** arr, int rows, int cols) { // Input: &pointer, int, int -> Output: void
    for (int i = 0; i < rows; ++i) { // loop over all the rows
        for (int j = 0; j < cols; ++j) { // loop over all the cols
            arr[i][j] = i * cols + j; // // update the values in the array
        }
    }
}

void print2DArray(int** arr, int rows, int cols) { // pass memory address of the pointer to array
    for (int i = 0; i < rows; ++i) { // loop over rows
        for (int j = 0; j < cols; ++j) { // loop over cols
            cout << arr[i][j] << " "; // print values
        }
        cout << endl;
    }
}

void delete2DArray(int** arr, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i]; // deallocates all memory for row[i] (col addresses)
    }
    delete[] arr; // deallocates all memory for rows
}

int main() {
    int rows = 3, cols = 4;

    int** my2DArray = create2DArray(rows, cols); // create a new array
    initialize2DArray(my2DArray, rows, cols); // init the array w/ values
    print2DArray(my2DArray, rows, cols); // print it

    int* leakedPtr = new int(42);  // new int ptr

    int* uninitializedPtr; // init ptr

    int value = 10;
    int* ptr = &value; // ptr hold address of value
    int** ptrToPtr = &ptr; // hold address of ptr

    cout << "Value: " << value << endl; // 10
    cout << "Pointer to value: " << *ptr << endl; //10
    cout << "Pointer to pointer to value: " << **ptrToPtr << endl; // 10

    delete2DArray(my2DArray); // deallocates all memory for array

    // leakedPtr never deallocated
    delete leakedPtr;
    leakedPtr = nullptr;
    // if uninitialized ptr called would crash program
    uninitializedPtr = nullptr;

    
    return 0;
}
```
