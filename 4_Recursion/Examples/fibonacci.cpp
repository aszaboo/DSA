#include <iostream>
#include <chrono>

// Recursive Fibonacci function
int fibonacciRecursive(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative Fibonacci function
int fibonacciIterative(int n) {
    int prev = 0;
    int current = 1;
    for (int i = 0; i < n; ++i) {
        int temp = prev + current;
        prev = current;
        current = temp;
    }
    return current;
}

int main() {
    int n = 30; // Example input, adjust as needed

    // Measure time for recursive Fibonacci
    auto startRecursive = std::chrono::high_resolution_clock::now();
    int resultRecursive = fibonacciRecursive(n);
    auto endRecursive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationRecursive = endRecursive - startRecursive;

    // Measure time for iterative Fibonacci
    auto startIterative = std::chrono::high_resolution_clock::now();
    int resultIterative = fibonacciIterative(n);
    auto endIterative = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationIterative = endIterative - startIterative;

    // Output the results
    std::cout << "Fibonacci(" << n << ") Recursive: " << resultRecursive << "\n";
    std::cout << "Time taken (Recursive): " << durationRecursive.count() << " seconds\n";

    std::cout << "Fibonacci(" << n << ") Iterative: " << resultIterative << "\n";
    std::cout << "Time taken (Iterative): " << durationIterative.count() << " seconds\n";

    return 0;
}
