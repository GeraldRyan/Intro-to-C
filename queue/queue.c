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

void doublequeue(Queue *q)
{

    // when doubling and using realloc- the data block is copied into a larger block of memory that screws up the ordering with respect to our flags, so we have to rearrange either the data or flags or both in a given way. The following is my attempt. THere are two parts- that one one side of front and that on other.

    // This takes the data from the front to the total length (as if the array was not a circular array) and stores it in the first dummy array
    int sizeFromFront = q->capacity - q->front; // 4 in our example in main
    int *dummyFromFront = malloc(sizeof(int) * sizeFromFront);
    int sizeToRear = q->rear; // 0 in our example from main
    int *dummyFromRear = malloc(sizeof(int) * sizeToRear);

    for (int i = q->front; i < q->capacity; i++)
    {
        // printf("This is q->storage not dereferenced %u and then defererenced %i\n", q->storage, *q->storage);
        *(dummyFromFront + i - q->front) = *(q->storage + i);
    }
    int ptr = 0;
    do
    {
        printf("%i-", dummyFromFront[ptr]);
        ptr++;
    } while (dummyFromFront[ptr] != 0);
    printf("\n");
    ptr = 0;
    for (int i = 0; i < q->rear; i++)
    {

        printf("This is q->storage not dereferenced %u and then defererenced %i\n", q->storage, *q->storage);
        *(dummyFromRear + i) = *(q->storage + i);
    }
    do
    {
        printf("%i", dummyFromRear[ptr]);
        ptr++;

    } while (dummyFromRear[ptr] != 0);

    printf("Dummy From Front %i and From Rear %i\n", *dummyFromFront, *dummyFromRear);

    // Doubling the memory space
    printf("doubling queue from %i to %i \n", q->capacity, q->capacity * 2);
    q->capacity *= 2;
    realloc(q->storage, q->capacity);
    int j;
    // reorder the array
    for (j = 0; j < sizeFromFront; j++)
    {
        q->storage[j] = dummyFromFront[j];
    }
    for (int i = 0; i < sizeToRear; i++)
    {
        q->storage[j] = dummyFromRear[i];
        j++;
    }
    ptr = 0;
    do{

        printf("aa %i", q->storage[ptr]);
        ptr++;
    }
    while (q->storage[ptr] != 0);
}

void enqueue(Queue *q, int item)
{
    // printf("rear and front and capacity, %i %i %i\n", q->rear, q->front, q->capacity);
    if (q->rear == q->front && q->length != 0)
    {
        doublequeue(q);
    }
    *(q->storage + q->rear) = item;
    printf("enqueued %i\n", item);
    q->rear++;
    q->length++;
    if (q->rear == q->capacity)
    {
        q->rear = 0;
    }
}
/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    if (q->front == q->rear && q->length == 0)
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

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    dequeue(q);
    dequeue(q);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);

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