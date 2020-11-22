#ifndef stack_h
#define stack_h
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q);

bool enqueue(queue *q, int value);
int dequeue(queue *q);

void destroyQueue(queue *q);

#endif