#include <iostream>
#include <string>
using namespace std;

int main() {
    string *pointerToString = new string("hi");

    delete pointerToString;
    return 0;
}