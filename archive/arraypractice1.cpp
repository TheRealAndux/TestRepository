#include <iostream>
using namespace std;

class Array {
    private:
    int* arr;
    int size;

    public:

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
    
    void set(int index, int value) {
        arr[index] = value;
    }

    ~Array() {
        delete[] arr;
    }

    Array(int s) {
        size = s;
        arr = new int[size];
    }

    Array(const Array& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            int* newArr = new int[other.size];
            
            for (int i = 0; i < other.size; i++) {
                newArr[i] = other.arr[i];
            }

            delete[] arr;
            arr = newArr;
            size = other.size;
        }
        return *this;
    }


};

int main() {
    Array a(3);
        a.set(0, 1);
        a.set(1, 2);
        a.set(2, 3);
    
    Array b = a;

    Array c(3);
        c.set(0, 4);
        c.set(1, 5);
        c.set(2, 6);

    c = a;
    
    a.print();
    b.print();
    c.print();

    return 0;
}