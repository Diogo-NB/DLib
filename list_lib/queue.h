#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

// A stack's node
struct qNode
{
    void *data;
    struct qNode *prev; // Previous node
};

typedef struct qNode *QNode;

struct queue
{
    struct qNode *end;
    struct qNode *start;
};

// A queue's pointer
typedef struct queue *Queue;

// Allocates memory for a new queue
Queue create_queue();

// Inserts a new element at the top of the queue
int enqueue(Queue Q, void *data);

// Removes and return the top element
void *qpop(Queue Q);

// Returns true (1) if the queue is empty
int is_queue_empty(Queue Q);

// Deallocates the queue (doesn't free the data in each node!)
void free_queue(Queue Q);

// free_queue(Q) while calling a free data function passed by the user for each node
void free_queue_func(Queue Q, void (*free_data_func)(void *));

// Return the queue's size
int queue_size(Queue Q);

#endif