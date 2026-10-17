#include "dynamicarr.h"
#include <iostream>

namespace {const int defaultCap = 5; }

// Sets value of some index of an Array

void Array::SetValue(int index, int value) {
    data[index] = value;
}

// Prints array, ends with newline

void Array::Print() const {
    for (int i = 0; i < size; i++) {
        std::cout << data[i];
    }
    std::cout << std::endl;
}

// Searches Array for an index

int Array::indexOf(int value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

// Constructor

Array::Array(int s)
    : data(new int[defaultCap]), size(s), capacity(defaultCap) {}

// Destructor

Array::~Array() {
    delete[] data;
}

// Copy Constructor

Array::Array(const Array &other)
    : data(new int[other.capacity]), size(other.size), capacity(other.capacity) {
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// Copy Assignment

Array& Array::operator=(const Array &other) {
    if (this == &other) {
        return *this;
    }
    
    delete[] data;

    size = other.size;
    capacity = other.capacity;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}