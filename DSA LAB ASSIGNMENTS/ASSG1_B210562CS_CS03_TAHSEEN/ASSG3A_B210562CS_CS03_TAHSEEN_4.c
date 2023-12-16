#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to create a new node with the given data
struct Node* newNode(int data);

// Priority queue structure
struct PriorityQueue {
    struct Node* head;
};

void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}

// void deleteRoot(int array[], int num)
// {
//   int i;
//   for (i = 0; i < size; i++)
//   {
//     if (num == array[i])
//       break;
//   }

//   swap(&array[i], &array[size - 1]);
//   size -= 1;
//   for (int i = size / 2 - 1; i >= 0; i--)
//   {
//     heapify(array, size, i);
//   }
// }

// Function to initialize an empty priority queue
struct PriorityQueue* initQueue();

// Function to insert a new element with the given priority
void insert(struct PriorityQueue* queue, int data);

// Function to remove and return the element with the highest priority
int removeMax(struct PriorityQueue* queue);

// Function to compute the minimum cost of connecting all the ropes
int minCost(int* ropes, int n);

// Main function
int main() {
    int n;
    scanf("%d", &n);
    int ropes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &ropes[i]);
    }
    printf("%d", minCost(ropes, n));
    return 0;
}


// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to initialize an empty priority queue
struct PriorityQueue* initQueue() {
    struct PriorityQueue* queue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    queue->head = NULL;
    return queue;
}

// Function to insert a new element with the given priority
void insert(struct PriorityQueue* queue, int data) {
    struct Node* t = newNode(data);
    if (queue->head == NULL || data < queue->head->data) {
        t->next = queue->head;
        queue->head = t;
    } else {
        struct Node* current = queue->head;
        while (current->next != NULL && data >= current->next->data) {
            current = current->next;
        }
        t->next = current->next;
        current->next = t;
    }
}

// Function to remove and return the element with the highest priority
int removeMax(struct PriorityQueue* queue) {
    if (queue->head == NULL) {
        return -1;
    } else {
        int data = queue->head->data;
        struct Node* temp = queue->head;
        queue->head = queue->head->next;
        free(temp);
        return data;
    }
}

// Function to compute the minimum cost of connecting all the ropes
int minCost(int* ropes, int n) {
    struct PriorityQueue* queue = initQueue();
    for (int i = 0; i < n; i++) {
        insert(queue, ropes[i]);
    }
    int totalCost = 0;
    while (queue->head->next != NULL) {
        int cost = removeMax(queue) + removeMax(queue);
        insert(queue, cost);
        totalCost += cost;
    }
    return totalCost;
}