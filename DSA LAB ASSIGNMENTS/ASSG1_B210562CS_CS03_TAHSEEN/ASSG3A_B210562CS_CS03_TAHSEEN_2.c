#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *arr;
    int size;
    int capacity;
} heap;

heap* create_heap(int capacity) {
    heap* h = (heap*) malloc(sizeof(heap));
    h->arr = (int*) malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

int parent(int i) {
    return (i - 1) / 2;
}

int left_child(int i) {
    return 2 * i + 1;
}

int right_child(int i) {
    return 2 * i + 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(heap* h, int key) {
    if (h->size >= h->capacity) {
        printf("Heap is full!\n");
        return;
    }
    h->arr[h->size] = key;
    int i = h->size;
    while (i > 0 && h->arr[i] < h->arr[parent(i)]) {
        swap(&h->arr[i], &h->arr[parent(i)]);
        i = parent(i);
    }
    h->size++;
}

int find_min(heap* h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    return h->arr[0];
}

int extract_min(heap* h) {
    if (h->size == 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    int min_val = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    int i = 0;
    while (left_child(i) < h->size) {
        int j = left_child(i);
        if (right_child(i) < h->size && h->arr[right_child(i)] < h->arr[left_child(i)]) {
            j = right_child(i);
        }
        if (h->arr[i] <= h->arr[j]) {
            break;
        }
        swap(&h->arr[i], &h->arr[j]);
        i = j;
    }
    return min_val;
}

void decrease_key(heap* h, int index, int new_val) {
    if (new_val >= h->arr[index]) {
        printf("New value should be smaller than current value!\n");
        return;
    }
    h->arr[index] = new_val;
    while (index > 0 && h->arr[index] < h->arr[parent(index)]) {
        swap(&h->arr[index], &h->arr[parent(index)]);
        index = parent(index);
    }
}

void delete(heap* h, int key) {
    int index = -1;
    for (int i = 0; i < h->size; i++) {
        if (h->arr[i] == key) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Key not found!\n");
        return;
    }
    decrease_key(h, index, -1);
    extract_min(h);
}

void print_heap(heap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main()