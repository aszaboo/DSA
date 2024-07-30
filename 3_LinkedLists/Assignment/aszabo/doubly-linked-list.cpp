#include "doubly-linked-list.h"

DoublyLinkedList::Node::Node(DataType data) {}


DoublyLinkedList::DoublyLinkedList() {
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}


DoublyLinkedList::~DoublyLinkedList() {
    // pointer for prev node
    Node* prev = nullptr;

    // delete nodes in list
    while(head_ != nullptr) {
        prev = head_;
        head_ = head_->next;
        delete prev;
    }
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
    // for optimizing search time
    Node* current;
    if(index < size_ / 2) {
        current = head_;
    } else {
        current = tail_;
    }

    if (current == head_) {
        while (current != nullptr && index != 0) {
            current = current->next;
            index--;
        }
        // return the node value
        return current->value;
        
    } else {
        int largest_index = size_ - 1;
        while (current != nullptr && (largest_index - index) != index) {
            current = current->prev;
            largest_index--;
        }
        // return node value
        return current->value;
    }
}

unsigned int DoublyLinkedList::search(DataType value) const {
    // pointer to current node
    Node* current = head_;
    // container for index value
    unsigned int index = 0;

    while(current != nullptr && current->value != value) {
        current = current->next;
        index++;
    }

    if(current == nullptr) {
        return INT_MAX;
    } else {
        return index;
    }
}


void DoublyLinkedList::print() const {
    Node* current = head_;

    while (current != nullptr) {
        std::cout << current->value << "-->";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}


DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
    // pointer to current node
    Node* current = head_;
    
    while (current != nullptr && index != 0) {
        current = current->next;
    }

    return current;
}

bool DoublyLinkedList::insert(DataType value, unsigned int index) {
    // index out of bounds
    if (index > size_) return false;
    
    // inserting into empty list
    if (head_ == nullptr) {
        head_ = new Node(value);
        size_++;
        return true;
    }

    if (index == 0) {
        head_->prev = new Node(value);
        head_->prev->next = head_;
        head_ = head_->prev;
    }

    // inserting at last position
    if (index == size_) {
        tail_->next = new Node(value);
        tail_ = tail_->next;
        size_++;
        return true;
    }

    Node* current = head_;

    while (index > 0) {
        current = current->next;
        index--;
    }

    Node* newNode = new Node(value);
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    size_++;
    return true; 
}


bool DoublyLinkedList::insert_front(DataType value) {
    insert(value, 0);
}


bool DoublyLinkedList::insert_back(DataType value) {
    insert(value, size_);
}


bool DoublyLinkedList::remove(unsigned int index) {
    if (index > size_ || head_ == nullptr) return false;

    if (index == 0) {
        head_ = head_->next;
        delete head_->prev;
        head_->prev = nullptr;
        size_--;
        return true;
    }

    if(index == size_ -1) {
        tail_ = tail_->prev;
        delete tail_->next;
        tail_->next = nullptr;
        size_--;
        return true;
    }

    Node* current;
    if (index < size_ / 2) {
        current = head_;

        while (index > 0) {
            current = current->next;
            index--;
        }
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size_--;
        return true;
    }
    
    else {
        int largest_index = size_ - 1;
        current = tail_;
        
        while(largest_index != index) {
            current = current->prev;
            largest_index--;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size_--;
        return true;
    }
}


bool DoublyLinkedList::remove_front() {
    remove(0);
}


bool DoublyLinkedList::remove_back() {
    remove(size_ - 1);
}


bool DoublyLinkedList::replace(unsigned int index, DataType value) {
    if (index > size_ - 1) return false;
    
    Node* current = getNode(index);
    current->value = value;
    return true;
}
