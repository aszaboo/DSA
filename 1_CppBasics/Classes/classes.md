# Classes in C++

### What is the primary difference between a struct and a class?
Structs: Members of a struct are **public by default** \
Classes: Members of a class are **private by default**

### When to use struct vs class

#### Structs
Used for passive data structures with public data members and no member functions

#### Classes
Used to define objects with both data members and member functions, encapsulating data and providing methods to operate on the data.
- Note: Classes generally also used when encapsulation, inheritance and or polymorphism used.

### Members
In C++, a class can contain various members that define its properties and behaviors. Here’s an in-depth look at the types of members that can be included in a class:

#### 1. **Data Members**
Data members are variables that hold the data associated with a class. They can be of any type, including fundamental types, user-defined types (such as other structs or classes), arrays, pointers, and more.

**Example:**
```cpp
class Car {
public:
    int year;               // Fundamental type
    std::string model;      // Standard library type
    double engineSize;      // Fundamental type
    static int totalCars;   // Static data member

    Car(int y, std::string m, double e) : year(y), model(m), engineSize(e) {}
};

int Car::totalCars = 0; // Definition of the static member
```

#### 2. **Member Functions**
Member functions (methods) define the behaviors or operations that can be performed on or by the data members of the class. These include constructors, destructors, and any other function that operates on the class data.

**Example:**
```cpp
class Car {
public:
    int year;
    std::string model;

    // Constructor
    Car(int y, std::string m) : year(y), model(m) {}

    // Destructor
    ~Car() {}

    // Member function
    void displayInfo() {
        std::cout << "Year: " << year << ", Model: " << model << std::endl;
    }
};
```

#### 3. **Static Members**
Static members belong to the class rather than any particular instance. This means they are shared among all instances of the class. Static members can be data members or member functions.

**Example:**
```cpp
class Car {
public:
    int year;
    std::string model;
    static int totalCars; // Static data member

    // Constructor
    Car(int y, std::string m) : year(y), model(m) {
        totalCars++;
    }

    // Static member function
    static int getTotalCars() {
        return totalCars;
    }
};

int Car::totalCars = 0; // Definition of the static member
```

#### 4. **Const Member Functions**
These functions do not modify any data members of the class and are marked with the `const` keyword. They can be called on const instances of a class.

**Example:**
```cpp
class Car {
public:
    int year;
    std::string model;

    Car(int y, std::string m) : year(y), model(m) {}

    // Const member function
    void displayInfo() const {
        std::cout << "Year: " << year << ", Model: " << model << std::endl;
    }
};
```

#### 5. **Friend Functions and Friend Classes**
Friend functions and classes have access to the private and protected members of the class where they are declared as friends. They are useful for functions that need to access the internals of the class without being member functions.

**Example:**
```cpp
class Car {
private:
    int year;
    std::string model;

public:
    Car(int y, std::string m) : year(y), model(m) {}

    // Friend function
    friend void printCarInfo(const Car& c);
};

void printCarInfo(const Car& c) {
    std::cout << "Year: " << c.year << ", Model: " << c.model << std::endl;
}
```

#### 6. **Nested Types**
A class can contain other types, such as enums, typedefs, and even other classes or structs, as nested types. These nested types are used to logically group related types together.

**Example:**
```cpp
class Car {
public:
    enum CarType { SEDAN, SUV, TRUCK }; // Nested enum

    CarType type;
    Car(CarType t) : type(t) {}
};
```

#### 7. **Operator Overloading**
Classes can overload operators to provide intuitive interaction with objects, such as adding two complex numbers or comparing two objects for equality.

**Example:**
```cpp
class Complex {
private:
    double real, imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Operator overloading for addition
    Complex operator + (const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};
```

#### 8. **Access Specifiers**
Access specifiers (`public`, `private`, `protected`) control the accessibility of class members. Public members are accessible from outside the class, private members are accessible only within the class, and protected members are accessible within the class and derived classes.

**Example:**
```cpp
class Car {
private:
    int year;             // Private data member
    std::string model;    // Private data member

public:
    Car(int y, std::string m) : year(y), model(m) {}

    // Public member function
    void displayInfo() {
        std::cout << "Year: " << year << ", Model: " << model << std::endl;
    }
};
```


### Key Object-Oriented Concepts in C++

#### 1. **Encapsulation**

**Definition:**
Encapsulation is the concept of bundling data (attributes) and methods (functions) that operate on the data into a single unit, or class. It also involves restricting access to certain components to prevent unintended interference and misuse, which is typically achieved through access specifiers (`public`, `private`, `protected`).

**Purpose:**
Encapsulation helps in maintaining the integrity of an object's internal state and allows for a controlled interface for interacting with the object.

**Example:**

```cpp
class BankAccount {
private:
    double balance; // Private data member

public:
    // Constructor
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Public method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Public method to withdraw money
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Public method to get the current balance
    double getBalance() const {
        return balance;
    }
};
```

In this example, `balance` is encapsulated within the `BankAccount` class and can only be modified through the public methods `deposit` and `withdraw`. This control prevents direct modification of the `balance` attribute, which could otherwise lead to invalid states (like a negative balance).

#### 2. **Abstraction**

**Definition:**
Abstraction involves hiding the complex implementation details of a system and exposing only the necessary and relevant features. In C++, this is often achieved through classes and interfaces, allowing users to interact with an object without needing to understand its internal workings.

**Purpose:**
Abstraction simplifies the use of complex systems, promotes a cleaner and more understandable interface, and separates implementation from usage.

**Example:**

```cpp
class Shape {
public:
    virtual void draw() const = 0; // Pure virtual function
    virtual double area() const = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Drawing a circle with radius " << radius << std::endl;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        std::cout << "Drawing a rectangle of " << width << "x" << height << std::endl;
    }

    double area() const override {
        return width * height;
    }
};
```

In this example, `Shape` is an abstract base class with pure virtual functions `draw` and `area`. `Circle` and `Rectangle` are derived classes that provide specific implementations for these functions. Users of these classes can work with the `Shape` interface, focusing on what the shape does (e.g., drawing and calculating area) rather than how these operations are implemented.

#### 3. **Inheritance**

**Definition:**
Inheritance is a mechanism by which one class (derived class) can inherit attributes and methods from another class (base class). This allows the derived class to reuse code, extend existing functionalities, and maintain a hierarchical relationship between classes.

**Purpose:**
Inheritance promotes code reuse, logical hierarchy, and easier maintenance by enabling modifications in the base class to be propagated to derived classes.

**Example:**

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        std::cout << "Meowing..." << std::endl;
    }
};
```

In this example, `Animal` is the base class with a common method `eat`. `Dog` and `Cat` are derived classes that inherit from `Animal`, allowing them to use the `eat` method, while also adding specific methods like `bark` and `meow`. This demonstrates how inheritance enables shared behavior and specialized extensions.

#### 4. **Polymorphism**

**Definition:**
Polymorphism allows functions and methods to process objects differently based on their data type or class. It is often implemented through function overloading, operator overloading, and more commonly in C++, through the use of virtual functions which enable dynamic dispatch.

**Purpose:**
Polymorphism provides flexibility and interoperability, allowing a single interface to control access to a general class of actions. This enables code to be more general and reusable.

**Example:**

```cpp
class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!" << std::endl;
    }
};

void playSound(const Animal& animal) {
    animal.makeSound();
}

int main() {
    Dog dog;
    Cat cat;
    playSound(dog); // Outputs: Woof! Woof!
    playSound(cat); // Outputs: Meow!
    return 0;
}
```

In this example, the `Animal` class has a virtual method `makeSound`, which is overridden by the `Dog` and `Cat` classes. The function `playSound` takes a reference to an `Animal` and calls the `makeSound` method. Due to polymorphism, the appropriate `makeSound` method is called depending on the actual object type passed to `playSound`, demonstrating dynamic behavior at runtime.