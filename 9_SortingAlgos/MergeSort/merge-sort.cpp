#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void merge(int array[], int leftIndex, int middleIndex, int rightIndex) {

    // Get sizes of subarrays
    int left_size = middleIndex - leftIndex + 1; // Size of the left subarray
    int right_size = rightIndex - middleIndex;   // Size of the right subarray

    // Create temporary subarrays to store the sorted values
    int L[left_size]; 
    int R[right_size];
    
    // Copy data into temporary subarrays
    for (int i = 0; i < left_size; ++i)
        L[i] = array[leftIndex + i]; // Copy elements from the left subarray

    for (int j = 0; j < right_size; ++j)
        R[j] = array[middleIndex + 1 + j]; // Copy elements from the right subarray

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

    // Copy remaining elements from L[], if any
    while (i < left_size) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements from R[], if any
    while (j < right_size) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex) {
    
    // Base case: If the subarray has only one element, it's already sorted
    if (leftIndex >= rightIndex) return;

    // Find the middle point to divide the array into two halves
    int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

    // Recursively sort the two halves
    mergeSort(array, leftIndex, middleIndex);
    mergeSort(array, middleIndex + 1, rightIndex);

    // Merge the sorted halves
    merge(array, leftIndex, middleIndex, rightIndex);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];
    cout << endl;
}

int main() {
    const int N = 1000;
    int arr[N];

    // Fixed seed for random number generation to ensure reproducibility
    srand(42);

    // Generate an array with 1000 random integers
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000; // Random number between 0 and 999
    }

    cout << "Unsorted array: \n";
    printArray(arr, N);

    auto start = high_resolution_clock::now(); // start timer
    mergeSort(arr, 0, N - 1);
    auto stop = high_resolution_clock::now(); // stop timer
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration

    cout << "Sorted array: \n";
    printArray(arr, N);

    cout << "Time taken by mergeSort: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
