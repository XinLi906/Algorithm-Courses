#include <iostream>
using namespace std;

int foo(int a, int b) {
    int tmp = a;
    tmp += b;
    return tmp;
}

int main() {
    int x, y, z;
    cin >> x;
    cin >> y;
    z = foo(x, y);
    cout << x << " + " << y << " = " << z << endl;
    return 0;
}