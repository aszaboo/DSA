#include <cstring>
#include <iostream>

class String {

private:
    int length; // Length of the string
    char* str;  // Pointer to the dynamically allocated character array

public:
    // Default Constructor
    // Initializes the string with an empty value
    String() : length(0), str(new char[1]) {
        str[0] = '\0'; // Null-terminate the empty string
    }

    // Parameterized Constructor
    // Initializes the string with a C-style string (const char*)
    String(const char* strVal) : length(strlen(strVal)) {
        str = new char[length + 1]; // Allocate memory including null terminator
        strcpy(str, strVal); // Copy the input string
    }

    // Copy Constructor
    // Creates a deep copy of another String object
    String(const String &strVal) : length(strVal.length) {
        str = new char[length + 1]; // Allocate memory for the new string
        strcpy(str, strVal.str); // Copy the content from the source object
    }

    // Destructor
    // Cleans up dynamically allocated memory to prevent memory leaks
    ~String() {
        delete[] str; // Deallocate the memory used for the string
    }

    // Assignment Operator
    // Allows assigning one String object to another with deep copy
    String& operator=(const String &strVal) {
        if (this == &strVal) return *this; // Self-assignment check
        delete[] str; // Free existing memory
        length = strVal.length;
        str = new char[length + 1]; // Allocate new memory
        strcpy(str, strVal.str); // Deep copy the string content
        return *this; // Return reference to the current object
    }

    // Addition Operator (Concatenation)
    // Concatenates two String objects and returns a new String object
    String operator+(const String &strVal) {
        String newString;
        newString.length = length + strVal.length; // Calculate new length
        newString.str = new char[newString.length + 1]; // Allocate memory
        strcpy(newString.str, str); // Copy the first string
        strcat(newString.str, strVal.str); // Append the second string
        return newString;
    }

    // Equality Operator
    // Compares two String objects for equality
    bool operator==(const String &strVal) {
        return strcmp(str, strVal.str) == 0; // Compare strings using strcmp
    }

    // Get the length of the string
    int getLength() const {
        return length;
    }

    // Return the C-style string
    const char* C_Str() const {
        return str;
    }

    // Clear the string
    // Resets the string to an empty state
    void clear() {
        delete[] str; // Free the current string
        str = new char[1]; // Allocate memory for an empty string
        str[0] = '\0'; // Null-terminate the empty string
        length = 0; // Reset the length
    }
};

int main() {
    String str1("Hello"); // Uses parameterized constructor
    String str2 = str1;   // Uses copy constructor
    String str3;
    str3 = str2;          // Uses assignment operator

    String str4 = str1 + " World!"; // Uses addition operator for concatenation

    std::cout << "str1: " << str1.C_Str() << std::endl;
    std::cout << "str2: " << str2.C_Str() << std::endl;
    std::cout << "str3: " << str3.C_Str() << std::endl;
    std::cout << "str4: " << str4.C_Str() << std::endl;

    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 == str4: " << (str1 == str4) << std::endl;

    str4.clear(); // Clears the content of str4
    std::cout << "After clear, str4: " << str4.C_Str() << std::endl;

    return 0;
}
