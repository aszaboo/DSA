# Hash Tables

## What are Hash Tables?

Hash tables are data structures used for quick inserts and lookups. They achieve this by creating key-value pairs, where the key is a hashed version of the original input. Hashing applies a transformation to an input to create a unique key. These keys are then used for lookups, inserts, and deletions of elements in a hash table, as the index is known, giving an O(1) best-case time complexity. Unlike arrays, you always know where an element is located since keys are unique (or at least somewhat unique).

## Hash Functions

### Idea

Map data of an arbitrary size to a fixed range of values.

### Simple Hash Function Example

E.g., What is the email address of the club member who has ID number 2001234 (when the ID number is used as a key)?

Given an array size of 2000:

The hash function could be:

```cpp
int hastFunction(int key) {
    return key % capacity;
}
```

The conversion process would look like:

```cpp
index = hashFunction(2001234) // index is 1234;
```

This function can then be used to query something like an email address:

```cpp
return A[index]->emailAddress;
```

## Conflict Resolution

When two hashed keys have the same index value, a conflict occurs. This phenomenon is generally resolved in two ways:

1. Separate Chaining
2. Open Addressing

### Separate Chaining

This method deals with conflict resolution by allowing multiple keys to have the same index, but chains these data entries together using an array of linked list head pointers.

### Separate Chaining Operations

#### Search Operation

**Steps**:

1. Calculate the hash index using the hash function.
2. Check if the key exists at the hash index.
3. If not found, traverse the chain until the key is found or the end of the chain is reached.

**Code**:

```cpp
Node* search(int num) {
    int hashIndex = hashFunction(num);
    if (table[hashIndex] == NULL)
        return NULL;
    else {
        Node* temp = table[hashIndex];
        while (temp != NULL && temp->idNumber != num) temp = temp->next;
        if (temp == NULL) return NULL;
        else return temp;
    }
}
```

#### Insert Operation

**Steps**:

1. Calculate the hash index using the hash function.
2. Check if the position at the hash index is occupied.
3. If not occupied, insert the key-value pair.
4. If occupied, traverse to the end of the chain and insert the new node.

**Code**:

```cpp
void insert(int num, string name, string email) {
    if (search(num)) {
        cout << "Cannot insert when the same key exists." << endl;
        return;
    }

    int hashIndex = hashFunction(num);

    if (table[hashIndex] == NULL) table[hashIndex] = new Node(num, name, email);
    else {
        Node* temp = table[hashIndex];
        while (temp->next != NULL) temp = temp->next;
        temp->next = new Node(num, name, email);
    }
}
```

#### Delete Operation

**Steps**:

1. Calculate the hash index using the hash function.
2. Search for the key.
3. If found, remove the key by adjusting the pointers to exclude the node.

**Code**:

```cpp
void remove(int num) {
    if (search(num) == NULL) {
        cout << "Cannot remove when the key does not exist." << endl;
        return;
    }

    int hashIndex = hashFunction(num);

    if (table[hashIndex] != NULL) {
        Node* prevNode = NULL;
        Node* temp = table[hashIndex];

        while (temp->idNumber != num && temp->next != NULL) {
            prevNode = temp;
            temp = temp->next;
        }

        if (temp->idNumber == num) {
            if (prevNode == NULL) {
                Node* nextNode = temp->next;
                delete temp;
                table[hashIndex] = nextNode;
            } else {
                Node* nextNode = temp->next;
                delete temp;
                prevNode->next = nextNode;
            }
        }
    }
}
```

### Separate Chaining Implementation

```cpp
#include <iostream>
#include <string>
using namespace std;

const int CAPACITY = 2000;

class Node {
public:
    int idNumber;
    string idName;
    string emailAddress;
    Node* next;

    Node(int num, string name, string email) : idNumber(num), idName(name), emailAddress(email), next(NULL) {};
};

class HashTable {
public:
    Node** table;

    HashTable() {
        table = new Node*[CAPACITY];
        for (int i = 0; i < CAPACITY; i++)
            table[i] = NULL;
    }

    ~HashTable() {
        for (int i = 0; i < CAPACITY; i++)
            if (table[i] != NULL) {
                Node* prevNode = NULL;
                Node* temp = table[i];
                while (temp != NULL) {
                    prevNode = temp;
                    temp = temp->next;
                    delete prevNode;
                }
            }
        delete[] table;
    }

    int hashFunction(int key) {
        return key % CAPACITY;
    }

    // Insert, search, and remove operations defined above
};
```

### Open Addressing

Open addressing solves conflicts by inserting a value at the next open slot. This process is called linear probing, which involves trying to insert at the index corresponding to the hash function output of the key and iterating over the array until an open spot is found or fails if no available positions are found.

### Open Addressing Operations

#### Insert Operation

**Steps**:

1. Calculate the hash index using the hash function.
2. Check if the position at the hash index is occupied.
3. If occupied, move to the next index and repeat until an open slot is found.
4. Insert the key-value pair at the found position.

**Code**:

```cpp
void insert(int key) {
    int hashIndex = hashFunction(key);
    while (occupied[hashIndex]) {
        hashIndex = (hashIndex + 1) % CAPACITY;
    }
    table[hashIndex] = key;
    occupied[hashIndex] = true;
}
```

#### Search Operation

**Steps**:

1. Calculate the hash index using the hash function.
2. Check if the key exists at the hash index.
3. If not found, move to the next index and repeat until the key is found or the table ends.

**Code**:

```cpp
int search(int key) {
    int hashIndex = hashFunction(key);
    while (occupied[hashIndex]) {
        if (table[hashIndex] == key)
            return hashIndex;
        hashIndex = (hashIndex + 1) % CAPACITY;
    }
    return -1;
}
```

#### Delete Operation

**Steps**:

1. Calculate the hash index using the hash function.
2. Search for the key.
3. If found, mark the slot as unoccupied.

**Code**:

```cpp
void remove(int key) {
    int hashIndex = search(key);
    if (hashIndex != -1) {
        occupied[hashIndex] = false;
    }
}
```

### Open Addressing Implementation

```cpp
#include <iostream>
#include <string>
using namespace std;

const int CAPACITY = 2000;

class HashTable {
public:
    int* table;
    bool* occupied;

    HashTable() {
        table = new int[CAPACITY];
        occupied = new bool[CAPACITY];
        for (int i = 0; i < CAPACITY; i++)
            occupied[i] = false;
    }

    ~HashTable() {
        delete[] table;
        delete[] occupied;
    }

    int hashFunction(int key) {
        return key % CAPACITY;
    }

    // Insert, search, and remove operations defined above
};
```

## Time Complexity

### Separate Chaining

- **Insertion**:
  - Best Case: O(1)
  - Worst Case: O(N)
  - Average Case: O(1)
- **Deletion**:
  - Best Case: O(1)
  - Worst Case: O(N)
  - Average Case: O(1)
- **Search**:
  - Best Case: O(1)
  - Worst Case: O(N)
  - Average Case: O(1)

### Open Addressing

- **Insertion**:
  - Best Case: O(1)
  - Worst Case: O(N)
  - Average Case: O(1)
- **Deletion**:
  - Best Case: O(1)
  - Worst Case: O(N)
  - Average Case: O(1)
- **Search**:
  - Best Case: O(1)
  - Worst Case: O(N)
  - Average Case: O(1)

### Comparison of Separate Chaining vs. Open Addressing

| Operation | Separate Chaining | Open Addressing |
|-----------|-------------------|-----------------|
| Insertion | O(1) / O(N)       | O(1) / O(N)     |
| Deletion  | O(1) / O(N)       | O(1) / O(N)     |
| Search    | O(1) / O(N)       | O(1) / O(N)     |
| Space     | More (due to links) | Less (linear probing) |
