#include <iostream>
#include <chrono>
#include <cstdlib> // for rand() and srand()
using namespace std;
using namespace std::chrono;

void selectionSort(int array[], int size) {
    // loop for size - 1 as know after sorting second last element
    // the last element is sorted
    for (unsigned int i = 0; i < size - 1; ++i) {
        // stores the smallest index
        int smallestIndex = i;
        // here loop until j < size as want to see every element
        for (unsigned int j = i + 1; j < size; ++j) {
            // update smallest index
            if (array[j] < array[smallestIndex]) smallestIndex = j;
        }

        // swap if needed
        if (smallestIndex != i) {
            swap(array[i], array[smallestIndex]);
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver program
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
    selectionSort(arr, N);
    auto stop = high_resolution_clock::now(); // stop timer
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration

    cout << "Sorted array: \n";
    printArray(arr, N);

    cout << "Time taken by selectionSort: "
         << duration.count() << " microseconds" << endl;

    return 0;
}