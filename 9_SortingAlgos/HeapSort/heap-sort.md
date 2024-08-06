# Heap Sort

Heap Sort utilizes the properties of a max heap to sort an array. First, the array is transformed into a heap using the heapify algorithm, ensuring that the root of any subtree is larger than all its children. After the heap is created, the root node is repeatedly popped from the tree and placed at the end of the array. The heapify algorithm is then called on the remaining elements until the heap is empty, resulting in a sorted array.

## Heap Sort Algorithm

**Inputs**:
- An array

**Outputs**:
- A sorted array

### Heapify Steps

**Inputs**:
- `N`: Size of the heap
- `i`: The root index of the heap

**Steps**:

1. Initialize `largest` as the root (`i`).
2. Calculate the indices of the left (`l = 2*i + 1`) and right (`r = 2*i + 2`) children.

    ```cpp
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
    ```

3. If the left child is within bounds and its value is greater than the root, update `largest`.

    ```cpp
    if (l < N && arr[l] > arr[largest])
        largest = l;
    ```

4. If the right child is within bounds and its value is greater than the current `largest`, update `largest`.

    ```cpp
    if (r < N && arr[r] > arr[largest])
        largest = r;
    ```

5. If `largest` is not the root, swap the root with the largest value and recursively heapify the affected subtree.

    ```cpp
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
    ```

### Build Max Heap Steps

1. Iterate over the array from `N/2 - 1` to `0`, calling heapify on each index.
   - This corresponds to the non-leaf nodes of the heap.
   - The array only needs to be iterated over `N/2` times because each iteration processes both the root and child nodes.

    ```cpp
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    ```

### Heap Sort Steps

1. Build the max heap using `buildMaxHeap(array, N)`.
2. Use a for loop from `N - 1` to `0`:
    - Swap the root of the heap with the last element.
    - Call heapify on the new root (with reduced heap size) to maintain the heap property.

    ```cpp
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    ```

### Example Code

```cpp
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapify(int arr[], int N, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // Left child exists and is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;

    // Right child exists and is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }
}

void buildMaxHeap(int arr[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
}

void heapSort(int arr[], int N) {
    buildMaxHeap(arr, N);

    for (int i = N - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11, 90, 88, 67, 54, 34, 99};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: \n";
    printArray(arr, size);

    auto start = high_resolution_clock::now();
    heapSort(arr, size);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Sorted array: \n";
    printArray(arr, size);

    cout << "Time taken by heapSort: " << duration.count() << " microseconds" << endl;

    return 0;
}
```

## Time and Space Complexity

Heap Sort has a time complexity of \(O(n \log n)\) and a space complexity of \(O(1)\).

| Complexity    | Best Case         | Average Case       | Worst Case        |
|---------------|-------------------|--------------------|-------------------|
| Time          | \(O(n \log n)\)   | \(O(n \log n)\)    | \(O(n \log n)\)   |
| Space         | \(O(1)\)          | \(O(1)\)           | \(O(1)\)          |

### Explanation

- **Best Case, Average Case, and Worst Case**: \(O(n \log n)\)
  - In all cases, the algorithm builds a max heap and then repeatedly extracts the maximum element, resulting in a consistent \(O(n \log n)\) time complexity.

- **Space Complexity**: \(O(1)\)
  - Heap Sort is an in-place sorting algorithm, requiring no additional storage other than the input array.

### Recurrence Relation

For Heap Sort, the recurrence relation is:

$$\[ T(n) = T\left(\frac{n}{2}\right) + O(n) \]$$

This reflects the process of building the heap and then extracting elements while maintaining the heap property. The overall time complexity is \(O(n \log n)\).