
#ifndef KEY_VALUE_SORT_H_INCLUDED
#define KEY_VALUE_SORT_H_INCLUDED

#include "key_value.h"

void kv_radix_sort(KV *arr, int n, int max);

void kv_counting_sort(KV *arr, int n, int max);

void _kv_1_digit_counting_sort(KV *arr, int n, int div, KV *temp);

void kv_bubble_sort(KV *arr, int n);

int kv_swap(KV kv1, KV kv2);

#endif