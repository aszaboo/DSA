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
