# Quick Sort

Quick sort is a divide-and-conquer algorithm used for sorting a list of numbers. Quick sort uses a pivot value to determine where elements should be placed, with all elements less than the pivot value going to the left of it and all values above the pivot value going to the right of it. After this operation, the pivot value is in the correct location for the array, and each sub-array can have the quicksort function called on it to complete the same process.

### Importance of a Good Pivot Selection

A pivot value near the middle of the array is critical to reducing the number of comparisons. Poor pivot selection can result in worst-case performance, similar to selection sort.

## Implementation

### Steps

1. **Check if the low value is less than the high value**:
    - If it is not, the array is sorted, return.

    ```cpp
    if (low < high) {
    ```

2. **Call the partition function** to sort the elements around the pivot value and get the pivot index to be used to split the array into left and right sub-arrays.

    **Partition Function**:
    1. Get the pivot value for comparison, in this case, we are using `array[high]`, or the last element in the array.
    2. Create a variable `i` that acts as a pointer to the index of the most recent value seen that is smaller than the pivot value:
        - Initialize `i` to `low - 1` to signify that no values have been seen that are less than the pivot value.
    3. Use a for loop to iterate from `j = low` to `high - 1`:
        - If `array[j] < pivot`, iterate `i` by one to the right and swap `array[i]` with `array[j]`.
    4. After the loop exits, swap the first value greater than the pivot value with the pivot value:
        - `swap(array[i + 1], array[high])`.
    5. Return `i + 1` as the pivot index.

    ```cpp
    int partition(int array[], int low, int high) {
        int pivot = array[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; ++j) {
            if (array[j] < pivot) {
                i++;
                swap(array[i], array[j]);
            }
        }

        swap(array[i + 1], array[high]);
        return i + 1;
    }
    ```

3. **Using the new pivot index**, split the lists into two by calling quick sort on the left and right sub-arrays:
    - `quickSort(low, pivot - 1)` for the left side.
    - `quickSort(pivot + 1, high)` for the right side.

    ```cpp
    void quickSort(int array[], int low, int high) {
        if (low < high) {
            int pivot = partition(array, low, high);
            quickSort(array, low, pivot - 1);
            quickSort(array, pivot + 1, high);
        }
    }
    ```

## Time and Space Complexity

Quick Sort has an average time complexity of \(O(n \log n)\) and a worst-case time complexity of \(O(n^2)\). Its space complexity is \(O(\log n)\) due to the recursion stack.

| Complexity    | Best Case         | Average Case       | Worst Case        |
|---------------|-------------------|--------------------|-------------------|
| Time          | \(O(n \log n)\)   | \(O(n \log n)\)    | \(O(n^2)\)        |
| Space         | \(O(\log n)\)     | \(O(\log n)\)      | \(O(n)\)     |

### Explanation

- **Best Case and Average Case**: \(O(n \log n)\)
  - This occurs when the pivot selection divides the array into two nearly equal halves, resulting in balanced recursion trees.

- **Worst Case**: \(O(n^2)\)
  - This happens when the pivot selection is poor, such as always choosing the smallest or largest element as the pivot, resulting in highly unbalanced recursion trees.

- **Space Complexity**: \(O(\log n)\)
  - Quick Sort is an in-place sorting algorithm, but the recursion stack depth is \(O(\log n)\) in the average case due to the divide-and-conquer approach.

### Recurrence Relations

**Best Case**: This occurs when the pivot divides the array into two equal halves. The recurrence relation for this scenario is:

$$\[ T(n) = 2T\left(\frac{n}{2}\right) + O(n) \]$$

Solving this using the Master Theorem gives:

$$\[ T(n) = O(n \log n) \]$$

**Worst Case**: This occurs when the pivot is the smallest or largest element, resulting in one sub-array being empty and the other containing \(n-1\) elements. The recurrence relation for this scenario is:

$$\[ T(n) = T(n-1) + O(n) \]$$

Solving this recurrence relation gives:

$$\[ T(n) = O(n^2) \]$$