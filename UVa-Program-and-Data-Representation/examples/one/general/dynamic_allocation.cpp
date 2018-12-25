#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please enter an integer value: ";
    cin >> n;

    int *ages = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter a value for ages[ " << i << " ]: ";
        cin >> ages[i];
    }

    for (int i = 0; i < n; i++) {
        cout << "ages[ " << i << " ]: " << ages[i] << ", ";
    }

    cout << endl;

    delete [] ages;
    return 0;
}