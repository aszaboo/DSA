# Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted. It is named for the way smaller elements "bubble" to the top of the list.

## Bubble Sort Algorithm

**Inputs**:

- An array

**Outputs**:

- A sorted array

### Algorithm Steps

1. Initialize a for loop to iterate from the start of the array to the end (`i = 0` to `i = size - 1`):

    ```cpp
    for (int i = 0; i < size - 1; i++) {
    ```

2. Inside this loop, initialize another for loop to iterate through the array from the start to the unsorted section (`j = 0` to `j = size - 1 - i`):

    ```cpp
    for (int j = 0; j < size - 1 - i; j++) {
    ```

3. Compare adjacent elements. If the left element (`array[j]`) is greater than the right element (`array[j + 1]`), swap them:

    ```cpp
    if (array[j] > array[j + 1]) {
        // Swap array[j] and array[j + 1]
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
    }
    ```

4. Use a flag to check if any swaps were made during a pass. If no swaps were made, the array is already sorted, and the algorithm can terminate early.

### Example Code with Early Termination

```cpp
#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;  // Initialize a flag to check for swaps
        
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;  // Set the flag to true if a swap is made
            }
        }

        // If no swaps were made, the array is sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);
    
    bubbleSort(array, size);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}
```

## Time and Space Complexity

Bubble sort has a time complexity of \(O(n^2)\) and a space complexity of \(O(1)\).

| Complexity    | Best Case         | Average Case       | Worst Case        |
|---------------|-------------------|--------------------|-------------------|
| Time          | \(O(n)\)          | \(O(n^2)\)         | \(O(n^2)\)        |
| Space         | \(O(1)\)          | \(O(1)\)           | \(O(1)\)          |

### Explanation

- **Best Case**: \(O(n)\)
  - This occurs when the array is already sorted. The algorithm will only pass through the array once, making no swaps.

- **Average Case**: \(O(n^2)\)
  - In the average scenario, the algorithm will need to perform multiple passes and swaps to sort the array, resulting in a quadratic time complexity.

- **Worst Case**: \(O(n^2)\)
  - This happens when the array is sorted in reverse order. The algorithm will need to perform the maximum number of passes and swaps, resulting in the highest time complexity.

- **Space Complexity**: \(O(1)\)
  - Bubble sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional memory space regardless of the input size.
