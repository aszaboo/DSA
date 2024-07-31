#include "doubly-linked-list.h"

DoublyLinkedList::Node::Node(DataType data) 
    : value(data), prev(nullptr), next(nullptr) {}

DoublyLinkedList::DoublyLinkedList() 
    : head_(nullptr), tail_(nullptr), size_(0) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head_;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head_ = tail_ = nullptr;
}


unsigned int DoublyLinkedList::size() const {
    return size_;
}


unsigned int DoublyLinkedList::capacity() const {
    return CAPACITY;
}


bool DoublyLinkedList::empty() const {
    return size_ == 0;
}


bool DoublyLinkedList::full() const {
    return size_ == CAPACITY;
}


DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
    // Check if the list is empty
    if (size_ == 0) return DataType(-999);  // List is empty, return sentinel value

    // Check if the index is out of bounds
    if (index >= size_) return tail_->value;  // Return last element or sentinel

    Node* current;

    // Optimize traversal by choosing the closest end
    if (index < size_ / 2) {
        current = head_;
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        current = tail_;
        for (unsigned int i = size_ - 1; i > index; --i) {
            current = current->prev;
        }
    }

    // Return the node's value
    return current->value;
}

unsigned int DoublyLinkedList::search(DataType value) const {
    Node* current = head_;
    unsigned int index = 0;

    // Traverse the list to find the value
    while (current != nullptr) {
        if (current->value == value) {
            return index;  // Value found, return the index
        }
        current = current->next;
        index++;
    }

    // Value not found, return size_ as an indicator
    return size_;
}


void DoublyLinkedList::print() const {
    Node* current = head_;

    while (current != nullptr) {
        std::cout << current->value;
        if (current->next != nullptr) {
            std::cout << " <-> "; // Bidirectional link indication
        }
        current = current->next;
    }
    std::cout << " -> nullptr" << std::endl; // Clearly mark the end of the list
}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    // Check if the index is within the bounds of the list
    if (index >= size_) {
        return nullptr; // Index out of bounds, return nullptr
    }

    Node* current;

    // Decide whether to start from the head or the tail
    if (index < size_ / 2) {
        current = head_;
        // Traverse the list from the head to the desired index
        for (unsigned int i = 0; i < index; ++i) {
            current = current->next;
        }
    } else {
        current = tail_;
        // Traverse the list from the tail to the desired index
        for (unsigned int i = size_ - 1; i > index; --i) {
            current = current->prev;
        }
    }

    // Return the node at the specified index
    return current;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    // Index out of bounds or list at capacity
    if (index > size_ || size_ >= CAPACITY) return false;

    Node* newNode = new Node(value);

    // Inserting into an empty list
    if (head_ == nullptr) {
        head_ = tail_ = newNode;
    } 
    // Inserting at the head
    else if (index == 0) {
        newNode->next = head_;
        head_->prev = newNode;
        head_ = newNode;
    } 
    // Inserting at the tail
    else if (index == size_) {
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
    } 
    // Inserting in the middle
    else {
        Node* current = getNode(index);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
    }

    size_++;
    return true;
}


bool DoublyLinkedList::insert_front(DataType value) {
    return insert(value, 0);
}


bool DoublyLinkedList::insert_back(DataType value) {
    return insert(value, size_);
}


bool DoublyLinkedList::remove(unsigned int index) {
    // Check if index is out of bounds or list is empty
    if (index >= size_ || head_ == nullptr) return false;

    Node* toDelete = getNode(index);
    // Removing the only node in the list
    if (size_ == 1) {
        delete head_;
        head_ = tail_ = nullptr;
    }
    // Removing the head node
    else if (index == 0) {
        head_ = head_->next;
        head_->prev = nullptr;  // Set new head's prev to nullptr
        delete toDelete;
    }
    // Removing the tail node
    else if(index == size_ - 1) {
        tail_ = tail_->prev;
        tail_->next = nullptr;  // Set new tail's next to nullptr
        delete toDelete;
    }
    // Removing a middle node
    else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        delete toDelete;
    }
    size_--;
    return true;
}


bool DoublyLinkedList::remove_front() {
    return remove(0);
}


bool DoublyLinkedList::remove_back() {
    return remove(size_ - 1);
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if (index >= size_) return false;
    Node* current = getNode(index);
    current->value = value;
    return true;
}
