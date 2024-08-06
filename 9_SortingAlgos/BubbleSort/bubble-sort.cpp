#include <iostream>
#include <chrono>
#include <cstdlib> // for rand() and srand()

using namespace std;
using namespace std::chrono;

// bubble sort
void bubbleSort(int array[], int size) {
    // iterate over n - 1 elements in array (don't need to iterate over all as comparing two values)
    for (unsigned int i = 0; i < size - 1; ++i) {
        // flag for early termination case
        bool swapped = false;
        // iterate over elements not already sorted (i indicates # of sorted elements)
        for (unsigned int j = 0; j < size - 1 - i; ++j) {
            // if right value greater than left swap
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                // set flag to true
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
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
    bubbleSort(arr, N);
    auto stop = high_resolution_clock::now(); // stop timer
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration

    cout << "Sorted array: \n";
    printArray(arr, N);

    cout << "Time taken by bubbleSort: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
