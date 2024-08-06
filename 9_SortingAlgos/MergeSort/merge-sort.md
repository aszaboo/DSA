# Merge Sort

Merge Sort is a divide-and-conquer sorting algorithm. The premise behind this algorithm is to split the problem of sorting into smaller subproblems, where you break the array into smaller arrays, then sort those arrays, and finally piece the problem together after each sub-array has been sorted.

## Merge Sort Algorithm

**Inputs**:

- An array

**Outputs**:

- A sorted array

### Algorithm Steps

1. **Check if the left index is equal to the right index**. If they are equal, return because the array is already sorted.

    ```cpp
    if (left >= right)
        return;
    ```

2. **Determine the middle index** of the array using `(left + right) / 2`.

    ```cpp
    int middle = left + (right - left) / 2;
    ```

3. **Recursively call the function** for the left and right halves:
    - `mergeSort(array, left, middle)`
    - `mergeSort(array, middle + 1, right)`

    ```cpp
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
    ```

4. **Merge the sorted arrays** using a helper function:
    - Create temporary arrays for the left and right subarrays.
    - Use pointers to track the position in the left and right subarrays.
    - Merge the elements in sorted order.

### Example Code

```cpp
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to merge two subarrays
void merge(int array[], int leftIndex, int middleIndex, int rightIndex) {

    // Get sizes of subarrays
    int left_size = middleIndex - leftIndex + 1; // Size of the left subarray
    int right_size = rightIndex - middleIndex;   // Size of the right subarray

    // Create temporary subarrays to store the sorted values
    int L[left_size]; 
    int R[right_size];
    
    // Copy data into temporary subarrays

    // Copy elements from the main array into the left subarray
    for (int i = 0; i < left_size; ++i)
        L[i] = array[leftIndex + i];

    // Copy elements from the main array into the right subarray
    for (int j = 0; j < right_size; ++j)
        R[j] = array[middleIndex + 1 + j];

    // Initial indexes for the left (i), right (j) and merged subarray (k)
    int i = 0, j = 0;
    int k = leftIndex; // Start from the left index for merging

    // Merge the temporary subarrays back into the original array
    while (i < left_size && j < right_size) {
        if (L[i] <= R[j]) {
            array[k] = L[i]; // If current element in L is smaller or equal, add it to the merged array
            i++;
        } else {
            array[k] = R[j]; // If current element in R is smaller, add it to the merged array
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_array, if any
    while (i < left_size) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_array, if any
    while (j < right_size) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;

    // Calculate the middle index
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

    // Recursively sort the first and second halves
    mergeSort(array, leftIndex, middleIndex);
    mergeSort(array, middleIndex + 1, rightIndex);

    // Merge the sorted halves
    merge(array, leftIndex, middleIndex, rightIndex);
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 88, 67, 54, 34, 99};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: \n";
    printArray(arr, size);

    auto start = high_resolution_clock::now();
    mergeSort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array: \n";
    printArray(arr, size);

    cout << "Time taken by mergeSort: " << duration.count() << " microseconds" << endl;

    return 0;
}
```

## Time and Space Complexity

Merge Sort has a time complexity of \(O(n \log n)\) and a space complexity of \(O(n)\).

| Complexity    | Best Case         | Average Case       | Worst Case        |
|---------------|-------------------|--------------------|-------------------|
| Time          | \(O(n \log n)\)   | \(O(n \log n)\)    | \(O(n \log n)\)   |
| Space         | \(O(n)\)          | \(O(n)\)           | \(O(n)\)          |

### Explanation

- **Best Case, Average Case, and Worst Case**: \(O(n \log n)\)
  - In all cases, the algorithm divides the array into two halves and then merges them back in a sorted manner. This division step takes \(O(\log n)\) time, and the merging step takes \(O(n)\) time, resulting in a total time complexity of \(O(n \log n)\).

- **Space Complexity**: \(O(n)\)
  - Merge Sort is not an in-place sorting algorithm as it requires additional space to hold the left and right subarrays during the merging process. The space complexity is therefore \(O(n)\).

### Recurrence Relation

For Merge Sort, the recurrence relation is straightforward because each division splits the array into two equal halves, and the merging process takes linear time:

\[ T(n) = 2T\left(\frac{n}{2}\right) + O(n) \]

Solving this using the Master Theorem gives:

\[ T(n) = O(n \log n) \]

This recurrence holds for all cases (best, worst, and average) because Merge Sort always divides the array into two equal halves and the merge step is always linear.