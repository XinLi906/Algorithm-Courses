typedef struct LinkedListNode NodeT;

NodeT *makeNode(int);

void freeLL(NodeT *);

void showLL(NodeT *);

NodeT *joinLL(NodeT *, NodeT *);

NodeT *splitLL(NodeT *);