#define ull unsigned long long int

typedef struct ULLILListNode {
    ull val;
    struct ULLILListNode *next;
} NodeT;

typedef struct ULLILListRep {
    NodeT *first;
    int length;
} ULLILListRep;

typedef struct ULLILListRep *ULLILList;

ULLILList NewULLILList();

void DropULLILList(ULLILList);

int ULLILListIsEmpty(ULLILList);

void ULLILListPush(ULLILList, ull);

ull ULLILListPop(ULLILList);