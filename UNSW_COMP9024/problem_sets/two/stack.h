#include <stdbool.h>

#define CAPCITY 100

static struct Stack {
    int items[CAPCITY];
    int top;
} Stack;

void StackInit();
bool StackIsEmpty();
void StackPush(int digit);
int StackPop();
