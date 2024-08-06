# Selection Sort

Selection Sort is a simple sorting algorithm that sorts a list by repeatedly finding the smallest (or largest, depending on the sorting order) element from the unsorted portion of the list and swapping it with the first element in the unsorted array. This process is repeated until the entire list is sorted.

## Selection Sort Algorithm

**Input**:

- An array

**Output**:

- A sorted array

### Algorithm Steps

1. **Initialize a for loop** to iterate through the array from the start to the end (`i = 0` to `i = size - 1`):

    ```cpp
    for (int i = 0; i < n - 1; i++) {
    ```

    **Explanation**:
    - The outer loop runs from the first element to the second-to-last element (`n - 1`). This is because, by the time the algorithm reaches the last element, the rest of the array will already be sorted, making the final element automatically the largest remaining element.

2. **Set the current position as the minimum index**:

    ```cpp
    int min_idx = i;
    ```

    **Explanation**:
    - This initializes the minimum index to the current position of the outer loop. It assumes that the smallest element in the unsorted portion of the array is at this position until proven otherwise.

3. **Iterate through the unsorted portion of the array** using a for loop (`j = i + 1` to `j = n - 1`):

    ```cpp
    for (int j = i + 1; j < n; j++) {
    ```

    **Explanation**:
    - The inner loop starts from the element right after the current element (`i + 1`) and goes to the end of the array. This loop is used to find the smallest element in the unsorted portion of the array.

4. **If a smaller element is found**, update the minimum index:

    ```cpp
    if (arr[j] < arr[min_idx]) {
        min_idx = j;
    }
    ```

    **Explanation**:
    - If the current element in the inner loop is smaller than the element at the `min_idx`, update `min_idx` to the current position `j`.

5. **Swap the smallest element found with the first element of the unsorted portion**:

    ```cpp
    if (min_idx != i) {
        swap(arr[min_idx], arr[i]);
    }
    ```

    **Explanation**:
    - After the inner loop finishes, the smallest element in the unsorted portion is at `min_idx`. If `min_idx` is not equal to `i`, swap this element with the first element of the unsorted portion, which is at position `i`.

6. Repeat steps 1-5 until the entire array is sorted.

### Example Code

```cpp
#include <iostream>

using namespace std;

// Function for Selection sort
void selectionSort(int arr[], int n)
{
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in
        // unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
```
