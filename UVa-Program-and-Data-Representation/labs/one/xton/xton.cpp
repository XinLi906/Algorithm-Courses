#include <iostream>
using namespace std;

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return x * power(x, y - 1);
}

int main() {
    int x, y, z;
    cin >> x;
    cin >> y;
    z = power(x, y);
    cout << x << " ** " << y << " = " << z << endl;
    return 0;
}