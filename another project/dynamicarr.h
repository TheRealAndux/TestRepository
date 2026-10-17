#pragma once
class Array{ 
    private:
    int* data;                                  // Array Pointer
    int size;                                   // Array Size
    int capacity;                               // Array Capacity

    public:
    void Print() const;                         // Prints array, ends with newline
    void SetValue(int index, int value);        // Sets value of some index of an Array
    int indexOf(int value);                     // Searches Array for an index
    Array(int s);                               // Constructor
    ~Array();                                   // Destructor
    Array(const Array &other);                  // Copy Constructor
    Array& operator=(const Array &other);       // Copy Assignment
};