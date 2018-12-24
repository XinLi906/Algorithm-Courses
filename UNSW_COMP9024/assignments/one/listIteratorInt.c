/*
  listIteratorInt.c : A naive list Iterator ADT implementation
  Written by Xin Li
  Date: ....
*/

typedef struct IteratorIntRep {
    int item;
    IteratorInt next;
    IteratorInt prev;
} iter_t;

IteratorInt IteratorIntNew() {
    iter_t *iter_int = null;
    return iter_int;
}

int add(IteratorInt it, int v) {
    iter_t *new;
    new->prev = it;
    if (it) {
        it->next = new;
    }
    it = new;
    return 1;
}