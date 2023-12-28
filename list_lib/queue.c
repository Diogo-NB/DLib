#include "queue.h"

// Allocates memory for a new queue
Queue create_queue()
{
    Queue Q = (Queue)malloc(sizeof(struct queue));
    Q->end = NULL;
    Q->start = NULL;

    return Q;
}

// Inserts a new element at the start of the queue
int enqueue(Queue Q, void *data)
{
    if (Q == NULL)
        return -1;

    if (data == NULL)
        return 0;

    QNode new_node = (QNode)malloc(sizeof(struct qNode));
    new_node->data = data;
    new_node->prev = NULL;

    if (is_queue_empty(Q))
    {
        Q->start = Q->end = new_node;
    }
    else
    {
        Q->start->prev = new_node;
        Q->start = new_node;
    }

    return 1;
}

// Removes and return the end element
void *qpop(Queue Q)
{
    if (is_queue_empty(Q))
        return NULL;

    QNode end = Q->end;     // Current end node
    void *data = end->data; // Data to be returned

    // Setting new end node
    if (Q->end == Q->start)
        Q->end = Q->start = NULL;
    else
        Q->end = end->prev;

    free(end); // Deallocate the old end node
    return data;
}

// Returns true (1) if the queue is empty
int is_queue_empty(Queue Q)
{
    if (Q == NULL)
        return -1;

    return Q->end == NULL;
}

// Deallocates the queue (doesn't free the data in each node!)
void free_queue(Queue Q)
{
    if (Q == NULL)
        return;

    QNode aux = Q->end;
    while (aux != NULL)
    {
        Q->end = aux->prev;
        free(aux);
        aux = Q->end;
    }
    free(Q);
}

// free_queue(Q) while calling a free data function passed by the user for each node
void free_queue_func(Queue Q, void (*free_data_func)(void *))
{
    if (Q == NULL)
        return;

    QNode aux = Q->end;
    while (aux != NULL)
    {
        Q->end = aux->prev;
        free_data_func(aux->data);
        free(aux);
        aux = Q->end;
    }
    free(Q);
}

// Return the queue's size
int queue_size(Queue Q)
{
    if (Q == NULL)
        return -1;

    QNode aux = Q->end;
    int count = 0;
    while (aux != NULL)
    {
        count++;
        aux = aux->prev;
    }
    return count;
}