#include <iostream>
#include <chrono>

int factionalRecursive(int n) {
    // base case
    if (n == 0) return 1;

    // base case 2 (optional)
    if (n == 1) return 1;

    // recursive case
    return n * factionalRecursive(n -1);
}

int factorialIterative(int n) {
    int current = 1;

    for (int i = 1; i <= n; ++i) {
        current = i * current;
    }

    return current;
}

int main() {
    int n = 30; // Example input, adjust as needed

    // Measure time for recursive Fibonacci
    auto startRecursive = std::chrono::high_resolution_clock::now();
    int resultRecursive = factionalRecursive(n);
    auto endRecursive = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationRecursive = endRecursive - startRecursive;

    // Measure time for iterative Fibonacci
    auto startIterative = std::chrono::high_resolution_clock::now();
    int resultIterative = factorialIterative(n);
    auto endIterative = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> durationIterative = endIterative - startIterative;

    // Output the results
    std::cout << "Factorial(" << n << ") Recursive: " << resultRecursive << "\n";
    std::cout << "Time taken (Recursive): " << durationRecursive.count() << " seconds\n";

    std::cout << "Factorial(" << n << ") Iterative: " << resultIterative << "\n";
    std::cout << "Time taken (Iterative): " << durationIterative.count() << " seconds\n";

    return 0;
}