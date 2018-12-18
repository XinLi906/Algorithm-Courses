typedef struct StackRep *stack;

stack newStack();
void dropStack(stack);
int StackIsEmpty(stack);
void StackPush(stack, int);
int StackPop(stack);
