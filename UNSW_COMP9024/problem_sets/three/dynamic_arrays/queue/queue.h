typedef struct QueueRep *queue;

queue newQueue(void);

void dropQueue(queue);

int QueueIsEmpty(queue);

void QueueEnqueue(queue, int);

int QueueDequeue(queue);