#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

// Default constructor initializes stack with a default capacity of 16
DynamicStack::DynamicStack() {
    init_capacity_ = 16;
    capacity_ = init_capacity_;
    items_ = new StackItem[capacity_];
    size_ = 0;
}

// Constructor initializes stack with a user-defined capacity
DynamicStack::DynamicStack(unsigned int capacity) {
    init_capacity_ = capacity;
    capacity_ = init_capacity_;
    items_ = new StackItem[capacity_];
    size_ = 0;
}

// Destructor to clean up dynamically allocated memory
DynamicStack::~DynamicStack() {
    delete[] items_;
}

// Returns the current size of the stack
unsigned int DynamicStack::size() const {
    return size_;
}

// Checks if the stack is empty
bool DynamicStack::empty() const {
    return size_ == 0;
}

// Returns the top item of the stack without removing it
DynamicStack::StackItem DynamicStack::peek() const {
    if (empty()) return EMPTY_STACK;
    return items_[size_ - 1];
}

// Pushes a new item onto the stack, resizing if necessary
void DynamicStack::push(StackItem value) {
    if (size_ == capacity_) {
        // Double the capacity if the stack is full
        StackItem* newStack = new StackItem[capacity_ * 2];
        for (unsigned int i = 0; i < size_; ++i) {
            newStack[i] = items_[i];
        }

        delete[] items_;
        items_ = newStack;
        capacity_ *= 2;
    }

    items_[size_] = value;
    size_++;
}

// Pops the top item from the stack, resizing if necessary
DynamicStack::StackItem DynamicStack::pop() {
    if (empty()) return EMPTY_STACK;

    // Shrink the capacity if the size is less than a quarter of the capacity and greater than initial capacity
    if (size_ < capacity_ / 4 && capacity_ > init_capacity_) {
        StackItem* newStack = new StackItem[capacity_ / 2];
        for (unsigned int i = 0; i < size_; ++i) {
            newStack[i] = items_[i];
        }

        delete[] items_;
        items_ = newStack;
        capacity_ /= 2;
    }

    StackItem popped = items_[size_ - 1];
    size_--;
    return popped;
}

// Prints the stack from top to bottom
void DynamicStack::print() const {
    for (unsigned int i = size_; i > 0; --i) {
        std::cout << items_[i - 1] << " ";
    }
    std::cout << "end" << std::endl;
}
