#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;
    int count;
    int cap;

    void grow() {
        if (count < cap) {
            return;
        }
        const int newCap = cap*2;
        int* biggerArr = new int[newCap];
        for (int i = 0; i < count; i++) {
            biggerArr[i] = data[i];
        }
        delete[] data;
        data = biggerArr;
        cap = newCap;
    }

public:
    DynamicArray() 
        : data(new int[2]), count(0), cap(2) {}

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other)
        : data(new int[other.cap]), count(other.count), cap(other.cap) {
        for (int i = 0; i < count; i++) {
            data[i] = other.data[i];
        }
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            int* arrayCopy = new int[other.cap];
            for (int i = 0; i < other.count; i++) {
                arrayCopy[i] = other.data[i];
            }   
            delete[] data;
            data = arrayCopy;
            count = other.count;
            cap = other.cap;
        }
        return *this;
    }

    bool operator==(const DynamicArray& other) const {
        int i = 0;
        if (count != other.count) {
            return false;
        }
        while (i < other.count) {
            if (data[i] != other.data[i]) {
                return false;
            }
            i++;
        }
        return true;
    }

    void push_back(int value) {
        if (count == cap) {
            grow();
        }
        data[count] = value;
        ++count;
    }

    void pop_back() {
        if (count <= 0) {
            return;
        }
        --count;
    }

    int& operator[](int index) {
        return data[index];
    }

    int size() const {
        return count;
    }

    int capacity() const {
        return cap;
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }


    void erase(int index) {
        if (index < 0 || index >= count) {
            return;
        }

        for (int i = index; i < count-1; i++) {
            data[i] = data[i + 1];
        }

        count--;
    }

    void insert(int index, int value) {
        if (index < 0 || index > count) {
            return;
        }
        
        if (count == cap) {
            grow();
        }


        for (int i = count-1; i >= index; i--) {
            data[i+1] = data[i];
        }

        data[index] = value;
        count++;
    }

};

int main() {
    
}