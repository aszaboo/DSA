#include "circular-queue.h"
#include <iostream>

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_ = 16;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
    size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity < 16 ? capacity_ = 16 : capacity_ = capacity;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;
    size_ = 0;
}

CircularQueue::~CircularQueue() {
    delete[] items_;
}

void CircularQueue::resize() {
    QueueItem* newQueue = new QueueItem[capacity_ * 2];

    unsigned int index = head_;
    for (unsigned int i = 0; i < size_; ++i) {
        newQueue[i] = items_[index];
        index++;
        index = (index + 1) % capacity_;
    }

    delete[] items_;
    items_ = newQueue;
    head_ = 0;
    tail_ = size_;
    capacity_ *= 2;
}

void CircularQueue::shrink() {
    if (capacity_ <= 16) return;

    // create a new queue
    QueueItem* newQueue = new QueueItem[capacity_ / 2];

    // copy elements over
    unsigned int index = head_;
    for (unsigned int i = 0; i < size_; ++i) {
        newQueue[i] = items_[index];
        index = (index + 1) % capacity_;
    }

    delete[] items_;
    items_ = newQueue;
    head_ = 0;
    tail_ = size_;
    capacity_ /= 2;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    return size_ == 0;
}

bool CircularQueue::full() const {
    return size_ == capacity_;
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if (empty()) return EMPTY_QUEUE;
    return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if (full()) {
        resize();
    }

    items_[tail_] = value; 
    tail_ = (tail_ + 1) % capacity_;
    size_++;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if (empty()) return EMPTY_QUEUE;

    QueueItem value = items_[head_];
    head_ = (head_ + 1) % capacity_;
    size_--;

    if (size_ > 0 && size_ <= capacity_ / 4) {
        shrink();
    }

    return value;
}

void CircularQueue::print() const {
    unsigned int index = head_;
    for (unsigned int i = 0; i < size_; ++i) {
        std::cout << items_[index] << " ";
        index = (index + 1) % capacity_;
    }
    std::cout << "end" << std::endl;
}
