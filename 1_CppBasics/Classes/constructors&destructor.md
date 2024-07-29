# Constructors and Destructors in C++

## Constructors
- Constructors are special member functions used to initialize objects in C++.
- A class can have multiple constructors, including default, parameterized, and copy constructors.

### Default Constructor
- Initializes an object's member variables to default values.
- If not defined, the compiler provides a default constructor.

```cpp
class MyClass {
public:
    int* myVal;
    char myChar;

    // Default Constructor
    MyClass() : myVal(new int(5)), myChar('a') {}
};
```

### Parameterized Constructor
- Initializes an object's member variables with specific values.
- Must be defined by the user.

```cpp
class MyClass {
public:
    int* myVal;
    char myChar;

    // Parameterized Constructor
    MyClass(int val, char letter) : myVal(new int(val)), myChar(letter) {}
};
```

### Copy Constructor
- Creates a deep copy of an object to ensure that the original and the copy do not share the same memory space.

```cpp
class MyClass {
public:
    int* myVal;
    char myChar;

    // Copy Constructor
    MyClass(const MyClass &myObj) : myVal(new int(*myObj.myVal)), myChar(myObj.myChar) {}
};
```

## Destructors
- Destructors are special member functions that clean up when an object goes out of scope or is deleted.
- A class can have only one destructor.

### Default Destructor
- If not explicitly defined, the compiler generates a default destructor, which does not handle dynamic memory.

```cpp
class MyClass {
public:
    int* myVal;
    char myChar;

    ~MyClass() {} // Compiler-generated destructor would be similar, but it's important to define one when dynamic memory is used
};
```

### Custom Destructor
- Necessary when a class manages dynamic memory to avoid memory leaks.

```cpp
class MyClass {
public:
    int* myVal;
    char myChar;

    // Custom Destructor
    ~MyClass() {
        delete myVal; // Free the dynamically allocated memory
    }
};
```

### Key Points:
- **Dynamic Memory Management:** If a class allocates memory dynamically, it must implement a destructor to free that memory.
- **Copy Constructor and Assignment Operator:** When dynamic memory is involved, both should be implemented to ensure proper deep copying.
- **Rule of Three:** If a class requires a custom destructor, copy constructor, or copy assignment operator, it likely needs all three due to dynamic memory or resource management.