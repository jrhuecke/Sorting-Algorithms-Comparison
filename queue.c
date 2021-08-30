#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//Queue struct. Some code from Eugene's lab section
//Very similar to Stack struct
typedef struct Queue {
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    uint32_t capacity;
    int64_t *items;
} Queue;

//creates queue same way as stack
Queue *queue_create(uint32_t capacity) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->head = 0;
    q->tail = 0;
    q->size = 0;
    q->capacity = capacity;
    q->items = (int64_t *) malloc(capacity * sizeof(int64_t));
    return q;
}

//deletes queue by freeing all items and then removing pointer
void queue_delete(Queue **q) {
    if (*q && (*q)->items) {
        free((*q)->items);
        free(*q);
        *q = NULL;
    }
    return;
}

//checks if queue is empty by checking current size
bool queue_empty(Queue *q) {
    if (q->size == 0) {
        return true;
    } else {
        return false;
    }
}

//checks if queue is full by seeing if head and tail are at same spot and size != 0
bool queue_full(Queue *q) {
    if (q->head == q->tail && q->size > 0) {
        return true;
    } else {
        return false;
    }
}

//returns current size
uint32_t queue_size(Queue *q) {
    return q->size;
}

//first checks if queue is full and then puts given int at tail pointer
//then increments tail using mod that way it loops back around.
bool enqueue(Queue *q, int64_t x) {
    if (queue_full(q)) {
        return false;
    } else {
        q->items[q->tail] = x;
        q->tail = (q->tail + 1) % q->capacity;
        q->size += 1;
        return true;
    }
}

//first checks if queue is empty and then returns the int at head pointer
//then increments head using mod that way it loops back around.

bool dequeue(Queue *q, int64_t *x) {
    if (queue_empty(q)) {
        return false;
    } else {
        *x = q->items[q->head];
        q->head = (q->head + 1) % q->capacity;
        q->size -= 1;
        return true;
    }
}

//prints out the queue using for loop
void queue_print(Queue *q) {
    printf("[");
    for (uint32_t i = q->head; i < q->tail; i = (i + 1) % q->capacity) {
        printf("%" PRId64, q->items[i]);
        if (i + 1 != q->tail) {
            printf(", ");
        }
    }
    printf("]\n");
}
