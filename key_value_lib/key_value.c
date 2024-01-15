#include <stdlib.h>
#include <stdio.h>

#include "key_value.h"

KV create_kv(int key, void *value)
{
    KV kv = (KV)malloc(sizeof(struct key_value));
    kv->key = key;
    kv->value = value;
    return kv;
}

KV *create_kv_array(int n)
{
    KV *kv_arr = (KV *)malloc(sizeof(KV) * n);
    for (int i = 0; i < n; i++)
        kv_arr[i] = create_kv(0, NULL);

    return kv_arr;
}

void free_kv_array(KV *arr, int n)
{
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

void free_kv_array_func(KV *arr, int n, void (*free_data_func)(void *))
{
    for (int i = 0; i < n; i++)
    {
        free_data_func(arr[i]->value);
        free(arr[i]);
    }
    free(arr);
}

void print_keys(KV *arr, int n)
{
    printf("\n[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]->key);

    printf("]");
}

void print_kv_array(KV *arr, int n, void (*print_value)(void *))
{
    printf("\n[ ");
    for (int i = 0; i < n; i++)
    {
        printf("(%d : ", arr[i]->key);
        print_value(arr[i]->value);
        printf(") ");
    }

    printf("]");
}

KV kv_search(KV *arr, int n, int key)
{
    int last_key = arr[n - 1]->key;
    if (last_key == key)
        return arr[n - 1];

    arr[n - 1]->key = key;

    int i = 0;
    while (arr[i]->key != key)
        i++;

    arr[n - 1]->key = last_key;
    if (i == n - 1)
        return NULL;

    return arr[i];
}

KV kv_bsearch(KV *arr, int n, int key)
{
    int start = 0, end = n - 1, mid;
    do
    {
        mid = start + (end - start) / 2;
        if (key > arr[mid]->key)
            start = mid + 1;
        else if (key < arr[mid]->key)
            end = mid;
        else
            return arr[mid];
    } while (start != end);

    return arr[end]->key == key ? arr[end] : NULL;
}