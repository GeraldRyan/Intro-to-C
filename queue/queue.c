#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue
{
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->capacity = capacity;
    newQueue->storage = malloc(capacity * sizeof(int));
    newQueue->length = 0;
    return newQueue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if (q->length < q->capacity)
    {
        *(q->storage + q->length) = item;
        printf("Queueing, capacity: %i, current_length: %i \n", q->capacity, q->length);
        printf("Storage position: %i, storage: %u \n", q->length, *(q->storage + q->length));
        q->length++;
    }
    else
    {
        printf("Queue is full: capacity: %i, length: %i\n", q->capacity, q->length);
        realloc(q->storage, q->length * 2);
        *(q->storage + q->length) = item;
        printf("Queueing, capacity: %i, current_length: %i \n", q->capacity, q->length);
        printf("Storage position: %i, storage: %u \n", q->length, *(q->storage + q->length));
        q->length++;
    }
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    printf("Dequeue running\n");
    return 1;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    free(q->storage);
    free(q);
}

#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 7);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif