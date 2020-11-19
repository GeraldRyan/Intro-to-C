#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "llqueue.h"
#include "stdbool.h"

typedef struct Node
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
void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int item)
{
    node * newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;
    newnode->value = item;
    newnode->next = NULL;
    if (q->tail != NULL){
        q->tail->next = newnode;
    }
    q->tail = newnode;
    if (q->head == NULL){
        q->head = newnode;
    }
    printf("enqueue %i \n", q->head->value);
    return true;

}
/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(queue *q)
{
    if (q->head == NULL) return 0;
    node *tmp = q->head;
    int result = tmp->value;
    q->head = q->head->next;
    if (q->head == NULL){
        q->tail = NULL;
    }
    free(tmp); 
    printf("dequeue %i\n", result);
    return result;

}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    // free(q->storage);
    free(q);
}

#ifndef TESTING
int main(void)
{
    queue *q = init_queue();

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