#ifndef KEY_VALUE_H_INCLUDED
#define KEY_VALUE_H_INCLUDED

struct key_value
{
    int key;
    void *value;
};

typedef struct key_value *KV;

KV create_kv(int key, void *value);

KV *create_kv_array(int n);

void free_kv_array(KV *arr, int n);

void free_kv_array_func(KV *arr, int n, void (*free_data_func)(void *));

void print_keys(KV *arr, int n);

void print_kv_array(KV *arr, int n, void (*print_value)(void *));

KV kv_search(KV *arr, int n, int key);

KV kv_bsearch(KV *arr, int n, int key);

#endif