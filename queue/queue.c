#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue
{
    unsigned int length;
    unsigned int capacity;
    int *storage;
    unsigned int front;
    unsigned int rear;
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
    newQueue->front = 0;
    newQueue->rear = 0;
    return newQueue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/

void doublequeue(Queue *q){
    printf("doubling queue from %i to %i \n", q->capacity, q->capacity*2);
    q->capacity *=2;
    // realloc(q->storage, q->capacity);


}

void enqueue(Queue *q, int item)
{
    // printf("rear and front and capacity, %i %i %i\n", q->rear, q->front, q->capacity);
    if (q->rear == q->front && q->length != 0){
        doublequeue(q);
    }
    *(q->storage + q->rear) = item;
    printf("enqueued %i\n", item);
    q->rear++;
    q->length++;
    if (q->rear == q->capacity){
        q->rear = 0;
    }
}
/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    if (q->front == q->rear && q->length==0)
    {
        return -1;
    }
    int rvalue = *(q->storage + q->front);
    *(q->storage + q->front) = NULL;
    q->front++;
    q->length--;
    return rvalue;
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

    enqueue(q, 2);
    enqueue(q, 7);
    enqueue(q, 5);
    enqueue(q, 4);
    // enqueue(q, 5);
    // enqueue(q, 6);

    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    printf("Dequeued %d\n", dequeue(q));
    // printf("%d\n", dequeue(q));
    // printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif