#include <iostream>

class Array {
    private: 
    int* arr;
    int size;

    public:
    
    Array(int s) 
        : arr(nullptr), size(s) {
            arr = new int[s];
    }

    ~Array() {
        delete[] arr;
    }

    Array(const Array& other) 
        : arr(nullptr), size(other.size) {
            arr = new int[other.size];

            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }

    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }

        delete[] arr;

        size = other.size;
        arr = new int[size];

        for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
            return *this;
        }

        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << arr[i];
            }
            std::cout << std::endl;
        }

        void set(int i, int value) {
            arr[i] = value;
        }

};

int main() {
    Array a(3);
        a.set(0,1);
        a.set(1,2);
        a.set(2,3);

    Array b = a;

    Array c(2);
        c.set(0, 4);
        c.set(1, 5);

    c = a;

    a.print();
    b.print();
    c.print();

    return 0;
}