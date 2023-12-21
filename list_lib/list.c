#include "list.h"

// Allocates memory for a new List
List create_list()
{
    List L = (List)malloc(sizeof(struct list));
    L->end = NULL;
    L->start = NULL;
    return L;
}

// Inserts a new element at the end of the list and returns it's node
Node append(List L, void *data)
{
    if (L == NULL)
        return NULL;

    Node new_node = _create_node(data);

    if (is_list_empty(L)) // Is first node
    {
        L->end = L->start = new_node;
    }
    else // Inserting at the end
    {
        new_node->prev = L->end;
        L->end->next = new_node;
        L->end = new_node;
    }
    return new_node;
}

// Inserts a new element at the start of the list and returns it's node
Node prepend(List L, void *data)
{
    if (L == NULL)
        return NULL;

    Node new_node = _create_node(data);

    if (is_list_empty(L)) // Is first node
    {
        L->end = L->start = new_node;
    }
    else // Inserting at the start
    {
        new_node->next = L->start;
        L->start->prev = new_node;
        L->start = new_node;
    }
    return new_node;
}

// Calls a function (func) for each list's element, from start to end
void for_each_element(List L, void (*func)(void *))
{
    if (L == NULL || func == NULL)
        return;

    Node aux = L->start;
    while (aux != NULL)
    {
        func(aux->data);
        aux = aux->next;
    }
}

// Calls a function (func) for each list's element, from end to start
void for_each_element_reversed(List L, void (*func)(void *))
{
    if (L == NULL || func == NULL)
        return;

    Node aux = L->end;
    while (aux != NULL)
    {
        func(aux->data);
        aux = aux->prev;
    }
}

// Returns a new list containing the same elements
List clone_list(List L)
{
    if (L == NULL)
        return NULL;

    List new_list = create_list();

    Node aux = L->start;
    while (aux != NULL)
    {
        append(new_list, aux->data);
        aux = aux->next;
    }
    return new_list;
}

// Returns a new list containing the same elements in reverse order
List clone_list_reversed(List L)
{
    if (L == NULL)
        return NULL;

    List new_list = create_list();

    Node aux = L->end;
    while (aux != NULL)
    {
        append(new_list, aux->data);
        aux = aux->prev;
    }
    return new_list;
}

// Creates a new next node
Node _create_node(void *new_node_data)
{
    Node new_node = (Node)malloc(sizeof(struct node));
    new_node->data = new_node_data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Removes a node from a list
void remove_node(List L, Node x)
{
    if (!(L == NULL || L->start == NULL || x == NULL))
    {
        if (x == L->end && x == L->start)
        {
            L->end = NULL;
            L->start = NULL;
        }
        else if (x == L->end)
        {
            L->end = x->prev;
            x->prev->next = NULL;
        }
        else if (x == L->start)
        {
            L->start = x->next;
            x->next->prev = NULL;
        }
        else
        {
            x->prev->next = x->next;
            x->next->prev = x->prev;
        }
        free(x);
    }
}

// Finds a node where func returns true (1)
Node find_node(List L, int (*func)(void *))
{
    if (is_list_empty(L) != 0 || func == NULL)
        return NULL;

    Node aux;
    for (aux = L->start; aux != NULL && !func(aux->data); aux = aux->next)
    {
    }

    return aux;
}

// Swaps data between two nodes
int swap(Node n1, Node n2)
{
    if (n1 == NULL || n2 == NULL)
        return 0;

    void *data = n1->data;
    n1->data = n2->data;
    n2->data = data;

    return 1;
}

// Returns true (1) if the list is empty
int is_list_empty(List L)
{
    if (L == NULL)
        return -1;

    return L->start == NULL;
}

// Deallocates the list (doesn't free the data in each node!)
void free_list(List L)
{
    if (L == NULL)
        return;

    Node aux = L->end;
    while (aux != NULL)
    {
        L->end = aux->prev;
        free(aux);
        aux = L->end;
    }
    free(L);
}

// free_list(S) while calling a free data function passed by the user for each node
void free_list_func(List L, void (*free_data_func)(void *))
{
    if (L == NULL)
        return;

    Node aux = L->end;
    while (aux != NULL)
    {
        L->end = aux->prev;
        free_data_func(aux->data);
        free(aux);
        aux = L->end;
    }
    free(L);
}

// Return the list's length
int list_length(List L)
{
    if (L == NULL)
        return -1;

    int count = 0;
    Node aux = L->start;
    while (aux != NULL)
    {
        count++;
        aux = aux->next;
    }
    return count;
}