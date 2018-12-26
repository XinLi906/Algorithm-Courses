#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();

private:
    int value;
    ListNode *next, *prev;

    friend class List;

    friend class ListItr;
};

#endif