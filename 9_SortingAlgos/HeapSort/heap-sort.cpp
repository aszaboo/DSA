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
    // use N / 2 - 1 as the tree relationship provides a O (log n) insertion time
    // which corresponds to N / 2 iterations for a loop
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
}

void heapSort(int arr[], int N) {
    // Build a max heap
    buildMaxHeap(arr, N);

    // One by one extract elements from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        // Reheaps new root downwards to restore heap property
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int N) {
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
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
    heapSort(arr, N);
    auto stop = high_resolution_clock::now(); // stop timer
    auto duration = duration_cast<microseconds>(stop - start); // calculate duration

    cout << "Sorted array: \n";
    printArray(arr, N);

    cout << "Time taken by heapSort: "
         << duration.count() << " microseconds" << endl;

    return 0;
}
