#ifndef LISTITR_H
#define LISTITR_H

#include "ListNode.h"
#include "List.h"

class ListItr {
public:
    ListItr();
    ListItr(ListNode * theNode);
    bool isPastEnd() const;
    bool isPastBeginning() const;
    void moveForward();
    void moveBackward();
    int retrieve() const;

private:
    ListNode* current;
    friend class List;
};

#endif