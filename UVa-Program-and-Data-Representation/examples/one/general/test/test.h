#ifndef TEST_H
#define TEST_H

#include <iostream>
using namespace std;

class test {
    static int idcount;
    const int id;
    int value;

public:
    test();
    test(int v);
    test(const test& x);
    ~test();
    test& operator = (const test& other);
    friend ostream& operator<<(ostream& out, const test& f);
};

#endif