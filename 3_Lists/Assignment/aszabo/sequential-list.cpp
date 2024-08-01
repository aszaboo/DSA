#include "sequential-list.h"

SequentialList::SequentialList(unsigned int cap) 
    : capacity_(cap >= 20 ? cap : 20), data_(new DataType[capacity_]), size_(0) {}

SequentialList::~SequentialList() {
    delete[] data_;
    data_ = nullptr;
}


unsigned int SequentialList::size() const {
    return size_;
}


unsigned int SequentialList::capacity() const {
    return capacity_;
}


bool SequentialList::empty() const {
    return size_ == 0;
}


bool SequentialList::full() const {
    return size_ == capacity_;
}


SequentialList::DataType SequentialList::select(unsigned int index) const {
    if (index >= size_ || index < 0) return DataType(-999);

    return data_[index];
}


unsigned int SequentialList::search(DataType val) const {
    
    // iterate through array
    for (unsigned int i = 0; i < size_; ++i) {
        // val found return index
        if (data_[i] == val) return i;
    }

    // val not found return size
    return size_;
}


void SequentialList::print() const {
    
    // iterate through array
    for (unsigned int i = 0; i < size_; ++i) {
        std::cout << data_[i] << " ";
    }
    // end of array
    std::cout << "\n";
}


bool SequentialList::insert(DataType val, unsigned int index) {
    if (index > size_) return false; // index cannot be larger than size

    // Resize if full
    if (full()) {
        DataType* newData = new DataType[capacity_ * 2];
        for (unsigned int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ *= 2;
    }

    // Shift elements to the right
    for (unsigned int i = size_; i > index; --i) {
        data_[i] = data_[i - 1];
    }

    // Insert new value
    data_[index] = val;
    ++size_;
    return true;    
}


bool SequentialList::insert_front(DataType val) {
    return insert(val, 0);
}


bool SequentialList::insert_back(DataType val) {
    return insert(val, size_);
}


bool SequentialList::remove(unsigned int index) {
    if (empty() || index >= size_) return false;

    // Shift elements to the left
    for (unsigned int i = index; i < size_ - 1; ++i) {
        data_[i] = data_[i + 1];
    }

    --size_;

    // Shrink the array if necessary
    if (size_ < capacity_ / 4 && capacity_ > 20) {
        unsigned int newCapacity = capacity_ / 2;
        newCapacity = newCapacity < 20 ? 20 : newCapacity;
        DataType* newData = new DataType[newCapacity];
        for (unsigned int i = 0; i < size_; ++i) {
            newData[i] = data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_ = newCapacity;
    }

    return true;
}


bool SequentialList::remove_front() {
    return remove(0);
}


bool SequentialList::remove_back() {
    return remove(size_ - 1);
}


bool SequentialList::replace(unsigned int index, DataType val) {
    if (index > size_ || index < 0) return false;

    // in bounds insert
    data_[index] = val;
    return true;
}
