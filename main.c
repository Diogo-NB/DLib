#include "kv_sort.h"

char *get_s()
{
    char c;
    scanf("%c", &c);
    while (c != '\n' && c != '\0')
        scanf("%c", &c);
    return fgets((char *)malloc(sizeof(char) * 30), 30, stdin);
}

void print_value(void *s)
{
    if (s == NULL)
        return;

    char *c = (char *)s;
    for (int i = 0; c[i] != '\n' && c[i] != '\0'; i++)
        printf("%c", c[i]);
}

int main(void)
{
    KV *arr;
    KV kv;
    int n, max_key = 0, i;
    char *s;

    scanf("%d", &n);
    arr = create_kv_array(n);

    print_kv(arr, n, print_value);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]->key);
        arr[i]->value = get_s();
        if (arr[i]->key > max_key)
            max_key = arr[i]->key;
    }

    print_kv(arr, n, print_value);

    printf("\nAfter sorting");

    // kv_bubble_sort(arr, n);
    kv_radix_sort(arr, n, max_key);
    // kv_counting_sort(arr, n, max_key);

    print_kv(arr, n, print_value);

    for (i = -1; i < n + 1; i++)
    {
        kv = kv_bsearch(arr, n, i);
        if (kv != NULL)
        {
            printf("\nFound --> %d : ", kv->key);
            print_value(kv->value);
        }
        else
        {
            printf("\nNot Found");
        }
    }

    print_kv(arr, n, print_value);

    free_kv_array_func(arr, n, free);
    return 0;
}