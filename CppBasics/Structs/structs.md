# Structs In C++

### Definition
Structs or Structures in C++ are essentially a container where related variables can be stored. **The access to all members in the struct is public by default.**

### Struct Use Case
Though in C++ structs have the same functionality as classes they are typically not used in the same way.

**A struct is typically used for creating passive data structures, with public data members, and do not include member functions.**


### Members
Each variable stored in the struct is called a member.

#### Typical Struct Members:
1. **Data Members:** Variables of any data type, inlcuding fundamental (int, float, char, etc.) or user-defined types (other stucts or classes), arrays, pointers, etc.

```cpp
struct Apple {
    // another struct for the dimentions of the apple
    Size dimentions;
    unsigned int num_seeds;
    string color;

    // default constructor
    Apple();
    // custom constructor
    Apple(Size dim, int num_seeds, string color);
};
```

2. **Static Members:** Can either be static data members or functions. These static data members are common among all instances of the struct.

```cpp
struct Apple {
    // another struct for the dimentions of the apple
    Size dimentions;
    unsigned int num_seeds;
    string color;

    // type variable always Honey Crisp and cannot be changed
    static string type = "Honey Crisp";

};
```

3. **Enumerations:** Enumerations (enum) in C++ are a way to define a set of named integral constants. Within a struct, enums are used to represent a fixed set of related values with meaningful names, improving code readability and maintainability.

```cpp
struct Device {
    enum State { OFF, ON, SLEEP }; // Enumeration for device states

    State currentState; // Data member of type State

    void setState(State s) {
        currentState = s;
    }
};
```

4. **Typedefs and Using Declarations:** C++ allows you to create type aliases within a struct using typedef or using. This is useful for simplifying complex type definitions or giving more descriptive names to existing types, which can make code easier to read and maintain.

```cpp
struct Network {
    using IPAddress = std::string; // Type alias using 'using'

    IPAddress ip;

    void setIP(IPAddress address) {
        ip = address;
    }
};
```

#### Non-Typical Class Members:
1. **Member Functions:** functions that operate on the data members, constructors, destructors, overloaded parameters (=, +, etc.)

```cpp
struct Library {
    unsigned int num_books;
    std::vector<Book> book_list;

    // Default constructor
    Library() : num_books(0) {}

    // Parameterized constructor
    Library(const std::vector<Book>& books) : num_books(books.size()), book_list(books) {}

    // Copy constructor
    Library(const Library& other)
        : num_books(other.num_books), book_list(other.book_list) {}

    // Assignment operator overload
    Library& operator=(const Library& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }

        num_books = other.num_books;
        book_list = other.book_list;
        return *this;
    }

    void addBook(const Book& book) {
        book_list.push_back(book);
        num_books = book_list.size();
    }

    void display() const {
        std::cout << "Number of books: " << num_books << std::endl;
        for (const auto& book : book_list) {
            std::cout << "Title: " << book.title << ", Author: " << book.author << std::endl;
        }
    }
};
```

2. **Constructors and Destructors:** Various types of constructors (init, copy move) and destructor (if dynamic memory allocation is used)

3. **Nested Types in Structs:** A struct in C++ can contain other structs, classes, or unions either as members or defined within the struct itself. This is useful for grouping related types together and organizing code more logically.

4. **Access Specifiers in Structs:** Access specifiers (public, protected, private) control the visibility and accessibility of members within a struct. They determine whether members can be accessed from outside the struct or from derived classes.
- **public:** Members are accessible from anywhere where the object is visible.
- **protected:** Members are accessible within the struct and its derived classes, but not from outside.
- **private:** Members are accessible only within the struct and not from derived classes or outside.


### Declaration and Initialization

#### Declaration
struct StructName {
    member vars
};

Example:
```cpp
// syntax struct StructName {};
struct SomeStruct {
    int memberVar1;
    char memberVar2;
    string memberVar3;
};
```
