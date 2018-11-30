#include <assert.h>

#include "queue.h"

#define CAPCITY 100
#define EMPTY -1
#define INIT 0
#define NULL 0xffff

static struct queue {
    int items[CAPCITY];
    int head;
    int tail;
} Queue;

void QueueInit()
{
    Queue.head = EMPTY;
    Queue.tail = INIT;
}

int QueueIsEmpty()
{
    return Queue.head == EMPTY
        || Queue.items[Queue.head] != NULL;
}

int QueueIsFull()
{
    return Queue.head == Queue.tail && Queue.items[Queue.head];
}

void QueueEnqueue(int digit)
{
    assert(!QueueIsFull());

    Queue.items[Queue.tail] = digit;

    if (Queue.tail == CAPCITY - 1) {
        Queue.tail = INIT;
    } else {
        Queue.tail++;
    }

    if(Queue.head == EMPTY) {
        Queue.head++;
    }
}

int QueueDequeue()
{
    assert(!QueueIsEmpty());

    int ele = Queue.items[Queue.head];
    Queue.items[Queue.head] = NULL;

    if (Queue.head == CAPCITY - 1) {
        Queue.head = INIT;
    } else {
        Queue.head++;
    }

    return ele;
}
