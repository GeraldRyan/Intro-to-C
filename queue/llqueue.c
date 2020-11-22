#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "llqueue.h"

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the querue's storage structure. 
*/
void init_queue(queue *q){
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value)
{
    node * newnode = malloc(sizeof(node));
    if (newnode == NULL) return false;
    newnode->value = value;
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
void destroyQueue(queue *q)
{
    // free(q->storage);
    free(q);
}

#ifndef TESTING
int main(void)
{
    queue *q;
    init_queue(&q);
    printf("q and &q: %u %u \n", q, &q);
    enqueue(&q, 1);
    printf("q and &q: %u %u \n", q->head, &q);

    enqueue(&q, 2);
    printf("q and &q: %u %u \n", q, &q);

    enqueue(&q, 3);
    printf("q and &q: %u %u \n", q->head, &q);

    enqueue(&q, 4);
    printf("q and &q: %u %u \n", q, &q);

    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);

    // enqueue(q, 6);

    printf("Dequeued %d\n", dequeue(&q));
    printf("Dequeued %d\n", dequeue(&q));
    printf("Dequeued %d\n", dequeue(&q));
    printf("Dequeued %d\n", dequeue(&q));
    // printf("%d\n", dequeue(q));
    // printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif