#include "kv_sort.h"

void kv_radix_sort(KV *arr, int n, int max)
{
    int i, div = 1;
    KV *temp = create_kv_array(n);

    while (max > 0)
    {
        _kv_1_digit_counting_sort(arr, n, div, temp);
        div *= 10;
        max /= 10;
    }

    free_kv_array(temp, n);
}

void kv_counting_sort(KV *arr, int n, int max)
{
    int i, aux;
    int *c = (int *)calloc(sizeof(int), max + 1);
    KV *temp = create_kv_array(n);
    KV kv;

    for (i = 0; i < n; i++)
        c[arr[i]->key]++;

    int accumulator = 0;
    for (i = 0; i < max + 1; i++)
    {
        aux = c[i];
        c[i] = accumulator;
        accumulator = accumulator + aux;
    }

    for (i = 0; i < n; i++)
    {
        kv = temp[c[arr[i]->key]];
        kv->key = arr[i]->key;
        kv->value = arr[i]->value;
        c[arr[i]->key]++;
    }

    for (i = 0; i < n; i++)
    {
        arr[i]->key = temp[i]->key;
        arr[i]->value = temp[i]->value;
    }
    free_kv_array(temp, n);
}

void _kv_1_digit_counting_sort(KV *arr, int n, int div, KV *temp)
{
    int i, aux;
    int *c = (int *)calloc(sizeof(int), 10);
    int digit;
    KV kv;

    for (i = 0; i < n; i++)
    {
        digit = (arr[i]->key / div) % 10;
        c[digit]++;
    }

    int accumulator = 0;
    for (i = 0; i < 10; i++)
    {
        aux = c[i];
        c[i] = accumulator;
        accumulator = accumulator + aux;
    }

    for (i = 0; i < n; i++)
    {
        digit = (arr[i]->key / div) % 10;
        kv = temp[c[digit]];
        kv->key = arr[i]->key;
        kv->value = arr[i]->value;

        c[digit]++;
    }

    for (i = 0; i < n; i++)
    {
        arr[i]->key = temp[i]->key;
        arr[i]->value = temp[i]->value;
    }
}

void kv_bubble_sort(KV *arr, int n)
{
    int flag = 1;
    int i, j;
    for (i = 0; flag && i < n; i++)
    {
        flag = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j]->key > arr[j + 1]->key)
            {
                flag = kv_swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
    }
}

int kv_swap(KV kv1, KV kv2)
{
    if (kv1 == NULL || kv2 == NULL)
        return 0;

    void *value = kv1->value;
    kv1->value = kv2->value;
    kv2->value = value;

    int key = kv1->key;
    kv1->key = kv2->key;
    kv2->key = key;

    return 1;
}