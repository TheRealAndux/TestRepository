#include <iostream>
#include "dynamicarr.h"
using namespace std;

int main() {
    int num;
    Array a(5);
        a.SetValue(0, 1); 
        a.SetValue(1, 2); 
        a.SetValue(2, 3); 
        a.SetValue(3, 4);   
        a.SetValue(4, 5);

    Array b = a;

    Array c(3);
        c.SetValue(0,6);
        c.SetValue(1,7);
        c.SetValue(2,8);

    cout << "Initial Arrays:" << endl;    
    a.Print();
    b.Print();
    c.Print();

    for (int i = 0; i < 2; i++) {
        cout << "Round " << i+1 << ": Find which index of A: ";
        cin >> num;

        if (a.indexOf(num) == -1) {
        cout << "Value not found in A" << endl;
    }

        else {
        cout << a.indexOf(num) << endl;
    }
    }

    cout << "A will now be copied to C.\n";
    c = a;

    c.Print();

    return 0;
}