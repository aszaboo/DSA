class String {

private:
    int length; // default size
    char* str;


public:
    // Constructors

    // Default
    String() : length(0), str(new char[1]) {
        str[0] = '\0'; // init w empty string
    };

    // Param Constructor
    String(const char* strVal) : length(strlen(strVal)) {
        str = new char[length + 1];
        strcpy(str, strVal); // Copy the input
    };

    // Copy Constructor
    String(const String &strVal) : length(strVal.length) {
        str = new char[length + 1];

        strcpy(str, strVal.str);
    }

    ~String() {
        delete[] str;
    }


    // Overload Operators

    String& operator=(const String &strVal) {
        if (this == &strVal) return *this;
        delete[] str;
        length = stringVal.length;
        str = new char[length + 1];
        strcpy(str, strVal.str); // deep copy
        return *this;
    }

    String& operator+(const String &strVal) {
        String* newString;
        newString.length = length + strVal.length;
        newString.str = new char[newString.length];
        strcpy(newString.str, str);
        strcpy(newString.str, stringVal.str);
        return newString;
    }

    bool operator==(const String &strVal) {
        return strcmp(str, strVal.str) == 0;
    }

    int getSize() {
        return size;
    }

    char* C_Str() {
        return str;
    }

    void clear() {
        delete[] str;
        str = new char[1];
        str[0] = '\0';
        size = 0;
    }
};

int main() {
    String str1("Hello");
    String str2 = str1;
    String str3;
    str3 = str2;

    String str4 = str1 + " World!";

    std::cout << "str1: " << str1.C_Str() << std::endl;
    std::cout << "str2: " << str2.C_Str() << std::endl;
    std::cout << "str3: " << str3.C_Str() << std::endl;
    std::cout << "str4: " << str4.C_Str() << std::endl;

    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 == str4: " << (str1 == str4) << std::endl;

    str4.clear();
    std::cout << "After clear, str4: " << str4.C_Str() << std::endl;

    return 0;
}