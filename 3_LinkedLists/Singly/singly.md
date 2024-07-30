# Linked Lists

## What is a linked list?
- A linked list is a type of abstract data structure the consists of nodes linked together through pointers.
- A node in this data structure consists of two members:
  - DataType val: the value being stored in the node
  - Node* next: a pointer to the next node in the chain

Visualization:
[(#)-->]: a node
(#): a val
-->: a pointer to a node (next)
----------------------------------------
[(9) -]->[(8) -]->[(7) -]->[(4) -]->nullptr

## Node Structure
- The node structure for a Linked List can either be defined as a struct or a class.

**Optimal Implementation**

```cpp
#include <iostream>
#include <memory>

template<typename T>
class LinkedNode {
public:
    T data;
    std::shared_ptr<ListNode<T>> next;

    // Constructor
    ListNode(const T& value, std::shared_ptr<ListNode<T>> nextNode = nullptr)
        : data(value), next(nextNode) {}
    
    // Destructor
    ~ListNode() {}
};
```

By using a template here you can adopt the LinkedNode to store any data type int the value and smart pointers will automatically clean up resources/

**Bare Bones Implementation**
```cpp
#include <iostream>

class LinkedNode {
public:
    int data;
    LinkedNode* next;

    // Constructor
    LinkedNode(int value, LinkedNode* nextNode = nullptr)
        : data(value), next(nextNode) {}

    ~LinkedNode() {}
};
```

## List Structure

```cpp
class LinkedList {
private:
    LinkedNode* head;

public:

    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    bool insert(int index, int value) {
        // index out of bounds
        if (index < 0) return false;

        if(index == 0) { // insert at front
            head = new LinkedNode(value, head);
            return true;
        }    

        // temp node for looping through list
        LinkedNode* current = head;

        // this will stop node before the insert value
        while(index > 1 && current != nullptr) {
            current = current->next;
            index--;
        }

        // index out of bounds
        if (current == nullptr) return false;

        LinkedNode* temp = new LinkedNode(value);
        temp->next = current->next;
        current->next = temp
        return true;
    }

    bool insertFront(int value) {
        insert(0, value);
    }

    bool insertEnd(int value) {
        if (head == nullptr) {
            head = new LinkedNode(value);
            return true;
        }

        LinkedNode* current = head;

        while(current->next != nullptr) {
            current = current->next;
        }

        current->next = new LinkedNode(value);
        return true;
    }

    bool deleteValue(int value) {
        LinkedNode* prev = nullptr;
        LinkedNode* current = head;

        while(current != nullptr && current->val != value) {
            prev = current;
            current = current->next;
        }

        // value not found
        if (current == nullptr) return false;

        // deleting head node
        if (prev == nullptr) {
            head = head->next;
        } else { // non head node
            prev->next = current->next;
        }
        // delete current node
        delete current;
        return true;
    }

    
    void printList() {
        LinkedNode* current = head;

        while(current != nullptr) {
            std::cout << current->val << "->";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void clear() {

        while(head != nullptr) {
            LinkedNode* current = head;
            head = head->next;
            delete current;
        }
    }
};
```

