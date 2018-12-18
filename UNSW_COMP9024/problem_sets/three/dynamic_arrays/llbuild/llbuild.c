#include <stdio.h>
#include "linkedlist.h"


int main(int argc, char *argv[]) {
    NodeT *head = NULL;
    int data;

    fprintf(stdout, "Enter an integer: ");
    while (fscanf(stdin, "%d", &data) == 1) {
        NodeT *new = makeNode(data);
        head = joinLL(head, new);
        fprintf(stdout, "Enter an integer: ");
    }
    fprintf(stdout, "Finished. List is ");
    showLL(head);
    freeLL(head);
    
    return 0;
}