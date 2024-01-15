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

    printf("Array size --> ");
    scanf("%d", &n);
    arr = create_kv_array(n);

    for (i = 0; i < n; i++)
    {
        printf("Key --> ");
        scanf("%d", &arr[i]->key);
        printf("Value (string) --> ");
        arr[i]->value = get_s();
        if (arr[i]->key > max_key)
            max_key = arr[i]->key;
    }

    print_kv_array(arr, n, print_value);

    // kv_bubble_sort(arr, n);
    kv_radix_sort(arr, n, max_key);
    // kv_counting_sort(arr, n, max_key);

    printf("\n\nAfter sorting: ");
    print_kv_array(arr, n, print_value);

    printf("\n\nBinary searching: (-1 to stop searching)\nKey --> ");
    scanf("%d", &i);

    while (i != -1)
    {
        kv = kv_bsearch(arr, n, i);
        if (kv != NULL)
        {
            printf("Found: %d : ", kv->key);
            print_value(kv->value);
        }
        else
        {
            printf("Not Found");
        }
        printf("\nKey --> ");
        scanf("%d", &i);
    }

    free_kv_array_func(arr, n, free);
    return 0;
}