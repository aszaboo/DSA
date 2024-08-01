# Recursion

## What is recusion?

Recursion is the process of breaking a computational problem into individual subproblems, where solving each one leads to a partial solution, combined these partial solutions can be combined to create the whole solution to the problem.

## When to use recursion

A recursive algorithm should be used in scenarios where a problem can be broken down into smaller, similar subproblems, making the solution easier to express and understand. Here are some specific situations where recursion is particularly useful:

1. **Divide and Conquer Problems**: Problems that can be divided into smaller subproblems of the same type, solved independently, and then combined to form the solution to the original problem. Examples include merge sort and quick sort.

2. **Tree and Graph Traversal**: Recursion is a natural fit for traversing tree structures or graphs. For example, depth-first search (DFS) in a tree or graph is typically implemented using recursion.

3. **Problems Defined Recursively**: When the problem itself is defined in a recursive manner, using a recursive algorithm often leads to a more intuitive and straightforward solution. Examples include calculating factorials, Fibonacci numbers, and the Tower of Hanoi problem.

4. **Backtracking Algorithms**: These algorithms explore all possible solutions to a problem by building a solution incrementally, removing solutions that fail to satisfy the constraints of the problem at any point. Examples include solving puzzles like Sudoku, finding all permutations of a set, and the n-queens problem.

5. **Dynamic Programming with Memoization**: In cases where subproblems overlap, recursion combined with memoization (caching the results of subproblems) can be effective. Examples include the Fibonacci sequence and the knapsack problem.

6. **Expression Parsing and Evaluation**: Recursive algorithms are used to parse and evaluate mathematical expressions, as the structure of expressions naturally lends itself to recursive decomposition.

### Example: Factorial Calculation

A classic example of a problem suitable for a recursive algorithm is the calculation of the factorial of a number \( n \):

\[ n! = n \times (n-1)! \]

Here's a simple recursive implementation in Python:

```cpp
int factorial(int n) {
    if (n == 0 or n == 1) return 1;
    else return n * factorial(n - 1);
}
```

### When Not to Use Recursion

- **Performance Constraints**: Recursive solutions can lead to high memory usage due to the call stack. Iterative solutions might be more efficient in such cases.
- **Stack Overflow Risk**: Deep recursion can cause stack overflow errors. In such cases, an iterative approach or tail recursion (if supported by the language) may be better.
- **Simple Iterative Solutions**: If the problem can be solved more easily and clearly with an iterative approach, it might be better to avoid recursion.

## Recursion vs Iteration

- In theory recursive algorithms can be represented non-recursively, through the implementation may be very complex.

### Comparison Table

|                         | Recursion                             | Iteration                             |
|-------------------------|---------------------------------------|---------------------------------------|
| **Space**               | Generally uses more memory due to call stack overhead for each recursive call | Generally uses less memory as it doesn't rely on the call stack |
| **Time**                | Can be slower due to function call overhead; however, with memoization, it can be optimized for some problems | Generally faster as it doesn't have function call overhead |
| **Implementation Complexity** | Often simpler and more intuitive for problems that have a recursive nature (e.g., tree traversal, divide and conquer) | Can be more complex for problems that naturally fit a recursive approach but simpler for straightforward loops |

### Additional Notes

- **Recursion**:
  - Pros: Easier to write and understand for problems that are inherently recursive.
  - Cons: Higher risk of stack overflow and increased memory usage.

- **Iteration**:
  - Pros: More efficient in terms of memory and often faster due to reduced overhead.
  - Cons: May require additional data structures (like stacks or queues) to mimic recursion, which can increase implementation complexity for certain problems.

## Designing Recursive Algorithms

### Advice for Designing Recursive Algorithms

When designing recursive algorithms, it is essential to address the following questions:

1. **How can the problem be represented as smaller sub-problems?**
   - **Advice**: Look for a way to express the main problem in terms of one or more smaller instances of the same problem. This often involves identifying a pattern or rule that reduces the problem size at each step. For example, in sorting algorithms like merge sort, the problem of sorting an array is broken down into sorting two halves of the array.

2. **What are the solutions to these sub-problems?**
   - **Advice**: Identify the base cases, which are the simplest instances of the problem that can be solved directly without further recursion. Base cases are crucial as they provide the stopping point for the recursion, ensuring that the algorithm does not run indefinitely. For example, in computing the factorial of a number, the base case is when the number is 0 or 1, where the factorial is 1.

3. **How do I know when all sub-problems have been solved?**
   - **Advice**: Clearly define the base cases and ensure they are correctly implemented. The base cases should cover all possible scenarios where the problem can no longer be broken down further. This helps in preventing infinite recursion and stack overflow errors. For instance, in the Fibonacci sequence, the base cases are typically defined for the first two numbers (0 and 1).

4. **What is the flow of the recursive process, and what subproblem do I move onto next after solving the current one?**
   - **Advice**: Establish the recursive relation or step, which determines how the solution to the current sub-problem leads to the next sub-problem. Ensure that each recursive call progresses towards a base case. The recursive step should combine the results of the sub-problems to form the final solution. For example, in a tree traversal algorithm, after visiting the current node, the algorithm moves to its child nodes recursively.

### Example: Recursive Algorithm for Factorial Calculation

1. **Representing the Problem:**
   - The factorial of \( n \) can be represented as \( n \times (n-1)! \).

2. **Base Case:**
   - \( 0! = 1 \) and \( 1! = 1 \).

3. **Termination Condition:**
   - The recursion stops when \( n \) is 0 or 1.

4. **Recursive Step:**
   - After solving for \( (n-1) \), multiply the result by \( n \) to get \( n! \).

## Recursive vs. Iterative Time Complexity  

| Algorithm         | Approach   | Time Complexity | Actual Time Taken (seconds) |
|-------------------|------------|-----------------|-----------------------------|
| **Fibonacci(30)** | Recursive  | \(O(2^n)\)      | 0.00944803                  |
|                   | Iterative  | \(O(n)\)        | 9.8e-08                     |
| **Factorial(30)** | Recursive  | \(O(n)\)        | 6.75e-07                    |
|                   | Iterative  | \(O(n)\)        | 3.01e-07                    |

### Analysis

- **Fibonacci Recursive vs. Iterative**:
  - The recursive approach for Fibonacci has exponential time complexity \(O(2^n)\), making it significantly slower as \(n\) increases.
  - The iterative approach has linear time complexity \(O(n)\), making it much faster for the same input.

- **Factorial Recursive vs. Iterative**:
  - Both approaches for calculating factorial have linear time complexity \(O(n)\).
  - The actual time taken for both approaches is very close, with the iterative approach being slightly faster.