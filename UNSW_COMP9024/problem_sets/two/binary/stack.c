#include <assert.h>
#include "stack.h"

#define EMPTY -1

static struct {
    int items[CAPCITY];
    int top;
} Stack;

void StackInit()
{
    Stack.top = EMPTY;
}

bool StackIsEmpty()
{
    return Stack.top == EMPTY;
}

void StackPush(int digit)
{
    assert(Stack.top < CAPCITY - 1);
    Stack.items[++Stack.top] = digit;
}

int StackPop()
{
    assert(Stack.top > EMPTY);
    return Stack.items[Stack.top--];
}

