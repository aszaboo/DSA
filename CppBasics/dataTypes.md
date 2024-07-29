# Data Types in C++

## Fundamental Data Types

### Integer Types

**int:**
- **Definition:** Represents standard integer values. The size and range are platform-dependent but typically 32 bits.
- **Use:** Storing whole numbers.
- **Size:** Typically 4 bytes

```cpp
int a = 5;
```

**short:**
- **Definition:** A shorter version of the integer type, typically used to save memory in large arrays of numbers.
- **Use:** Storing smaller integers.
- **Size:** Typically 2 bytes

```cpp
short b = 100;
```

**long:**
- **Definition:** A longer version of the integer type, used for larger numbers. It can store a wider range of values than `int`.
- **Use:** Storing larger integers.
- **Size:** Typically 4 bytes or more

```cpp
long c = 1000000L;
```

**long long:**
- **Definition:** Provides even greater range for integer values, ensuring at least 64-bit storage.
- **Use:** Storing very large integers.
- **Size:** Typically 8 bytes or more

```cpp
long long d = 1000000000000000LL;
```

### Character Types

**char:**
- **Definition:** Represents a single character or small integer. The size is always 1 byte, but the range can vary based on whether it is signed or unsigned.
- **Use:** Storing individual characters.
- **Size:** Typically 1 byte

```cpp
char e = 'A';
```

**unsigned char:**
- **Definition:** Similar to `char`, but only for non-negative values, often used for raw data.
- **Use:** Storing small non-negative integers or characters.
- **Size:** Typically 1 byte

```cpp
unsigned char f = 255;
```

**wchar_t:**
- **Definition:** A wide character type, used to represent characters from larger character sets like Unicode.
- **Use:** Storing wide characters.
- **Size:** Platform-dependent (often 2 or 4 bytes)

```cpp
wchar_t g = L'Ω';
```

**char16_t and char32_t:**
- **Definition:** Fixed-width character types for storing Unicode characters, introduced in C++11.
- **Use:** Storing 16-bit or 32-bit Unicode characters.
- **Size:** 2 bytes (char16_t) and 4 bytes (char32_t)

```cpp
char16_t h = u'あ'; // Japanese Hiragana character
char32_t i = U'𠜎'; // Rare Chinese character
```

### Floating-Point Types

**float:**
- **Definition:** Represents single-precision floating-point numbers. Typically used for saving memory in large arrays where double's precision is not necessary.
- **Use:** Storing floating-point numbers with single precision.
- **Size:** Typically 4 bytes

```cpp
float j = 3.14f;
```

**double:**
- **Definition:** Represents double-precision floating-point numbers. It provides more precision than `float`.
- **Use:** Storing floating-point numbers with double precision.
- **Size:** Typically 8 bytes

```cpp
double k = 3.141592653589793;
```

**long double:**
- **Definition:** Extended-precision floating-point number. It provides even more precision than `double`.
- **Use:** Storing floating-point numbers with extended precision.
- **Size:** Platform-dependent, typically more precise than `double`

```cpp
long double l = 3.141592653589793238L;
```

### Boolean Type

**bool:**
- **Definition:** Represents a Boolean value, which can either be `true` or `false`.
- **Use:** Storing truth values.
- **Size:** Typically 1 byte

```cpp
bool m = true;
```

### Void Type

**void:**
- **Definition:** Indicates the absence of any type. It is used as the return type for functions that do not return a value or for pointers that point to data of unknown type.
- **Use:** Representing no value or used in generic pointers.
- **Size:** Not applicable

```cpp
void functionName();
void* pointer; // Generic pointer
```

## Compound Data Types

### Pointers

- **Definition:** Variables that store memory addresses, typically pointing to another variable.
- **Use:** Dynamic memory management, arrays, and complex data structures.
- **Example:**

```cpp
int n = 42;
int* ptr = &n; // Pointer to an integer
```

### References

- **Definition:** An alias for another variable, providing an alternative name for the same memory location.
- **Use:** Passing large structures to functions efficiently, avoiding copies.
- **Example:**

```cpp
int o = 50;
int& ref = o; // Reference to o
```

### Arrays

- **Definition:** Collections of elements of the same type stored in contiguous memory locations.
- **Use:** Storing multiple items of the same type together.
- **Example:**

```cpp
int arr[5] = {1, 2, 3, 4, 5};
```

### Functions

- **Definition:** Blocks of code that perform a specific task and can be reused.
- **Use:** Encapsulating and organizing code into logical units.
- **Example:**

```cpp
int add(int x, int y) {
    return x + y;
}
```

### Enumerations

- **Definition:** A distinct type consisting of a set of named integral constants, called enumerators.
- **Use:** Creating named values for a set of related constants, improving code clarity.
- **Example:**

```cpp
enum Color { RED, GREEN, BLUE };
Color c = RED;
```

## User-Defined Types

### Structs

- **Definition:** User-defined types that group related variables under a single name.
- **Use:** Organizing data into a logical structure, especially for complex data.
- **Example:**

```cpp
struct Point {
    int x;
    int y;
};
Point p = {10, 20};
```

### Classes

- **Definition:** User-defined types that encapsulate data and functions that operate on the data. They are the foundation of object-oriented programming in C++.
- **Use:** Defining complex data structures with methods and attributes, supporting encapsulation, inheritance, and polymorphism.
- **Example:**

```cpp
class Rectangle {
private:
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() { return width * height; }
};
Rectangle rect(5, 10);
```

### Unions

- **Definition:** Similar to structs but store different data types in the same memory location, meaning only one member can be active at a time.
- **Use:** Storing a variable that may hold one of several different, but logically related, types.
- **Example:**

```cpp
union Data {
    int i;
    float f;
    char str[20];
};
Data data;
data.i = 10;
```

### Typedefs and Using Declarations

- **Definition:** Create new names for existing types, improving code readability and maintainability.
- **Use:** Simplifying complex type names or creating more readable type names.
- **Example:**

```cpp
typedef unsigned long ulong;
using ulong = unsigned long;
```

### Enums and Enum Classes (Scoped Enums)

- **Definition:** Enum classes provide a scoped enumeration, meaning the enumerator names are local to the enumeration and their values do not implicitly convert to other types.
- **Use:** Providing strong type checking and avoiding naming conflicts in larger projects.
- **Example:**

```cpp
enum class Direction { NORTH, SOUTH, EAST, WEST };
Direction dir = Direction::NORTH;
```

### Templates

- **Definition:** Templates allow functions and classes to operate with generic types, enabling code reuse for any data type.
- **Use:** Creating generic, reusable functions and classes.
- **Example:**

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

### Bit Fields

- **Definition:** Allow the packing of data in a struct by specifying the exact number of bits used for each member. This is useful in low-level programming where memory usage is critical.
- **Use:** Packing data into a compact form, controlling the number of bits used.
- **Example:**

```cpp
struct Flags {
    unsigned int a : 1;
    unsigned int b : 3;
    unsigned int c : 4;
};
```