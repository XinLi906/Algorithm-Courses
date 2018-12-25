#include <iostream>
using namespace std;

int main() {
    long y = 5;
    long x = 1;

    long *x_pointer = &x;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    *x_pointer = 2;

    cout << "After *x_pointer = 2 " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    x_pointer = &y;
    cout << "After *x_pointer = &y" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    *x_pointer = 3;

    cout << "After *x_pointer = 3 " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "x_pointer = " << x_pointer << endl;
    cout << "*x_pointer = " << *x_pointer << endl << endl;

    return 0;
}