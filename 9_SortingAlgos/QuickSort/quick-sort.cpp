#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to partition the array and return the pivot index
int partition(int array[], int low, int high) {
    // Get the pivot value
    int pivot = array[high];

    // i is the boundary between elements less than pivot and greater than pivot
    // Start i at low - 1 so the boundary is empty initially
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        // If the current element is less than the pivot
        if (array[j] < pivot) {
            i++; // Move the boundary to the right
            swap(array[i], array[j]); // Swap the current element to the left of the boundary
        }
    }

    // Swap the pivot element to its correct position in the array
    swap(array[i + 1], array[high]);

    // Return the index of the pivot element
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivot = partition(array, low, high);

        // Recursively apply Quick Sort to the left and right sub-arrays
        quickSort(array, low, pivot - 1); // Left sub-array
        quickSort(array, pivot + 1, high); // Right sub-array
    }
}

// Helper function to print the array
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

    auto start = high_resolution_clock::now(); // Start timer
    quickSort(arr, 0, N - 1);
    auto stop = high_resolution_clock::now(); // Stop timer
    auto duration = duration_cast<microseconds>(stop - start); // Calculate duration

    cout << "Sorted array: \n";
    printArray(arr, N);

    cout << "Time taken by quickSort: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
