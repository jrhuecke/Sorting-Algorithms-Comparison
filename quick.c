#include "quick.h"

#include "queue.h"
#include "stack.h"
#include "stats.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

//partition function based on pseudocode from
//assignment doc.
//input: array, lower int, upper int
uint32_t partition(uint32_t *A, uint32_t lo, uint32_t hi) {
    extern uint32_t compares, moves;
    //assigns pivot as number between lo and hi
    uint32_t pivot = A[lo + ((hi - lo) / 2)];
    //i is used to check lower half, j upper half
    uint32_t i = lo - 1;
    uint32_t j = hi + 1;
    //do while to make sure it runs at least once
    do {
        i += 1;
        //runs until it hits a num greater than the pivot
        while (greater_than(pivot, A[i])) {
            i += 1;
        }
        j -= 1;
        //runs until it hits a number less than the pivot
        while (greater_than(A[j], pivot)) {
            j -= 1;
        }
        //swaps the two nums found
        if (j > i) {
            uint32_t temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            moves += 3;
        }
    } while (i < j);
    return j;
}

//quick sort function that utilizes stack struct.
//based off pseudocode from assignment doc
//input: array, size of array
void quick_sort_stack(uint32_t *A, uint32_t n) {
    extern uint32_t compares, moves, max_stack_size;
    compares = 0;
    moves = 0;
    max_stack_size = 0;
    int64_t lo = 0, hi = n - 1;
    //creates the stack and pushes lower and upper int onto it
    Stack *stack = stack_create(n);
    stack_push(stack, lo);
    stack_push(stack, hi);
    //runs until the stack is empty
    while (stack_empty(stack) != true) {
        //keeps track of the largest stack size
        if (stack_size(stack) > max_stack_size) {
            max_stack_size = stack_size(stack);
        }
        //stores stack values on hi and lo
        stack_pop(stack, &hi);
        stack_pop(stack, &lo);
        //calls partition to check lo and hi
        int64_t p = partition(A, lo, hi);
        //puts lo and partition on stack if lo < partition
        if (p > lo) {
            stack_push(stack, lo);
            stack_push(stack, p);
        }
        //puts hi and partition + 1 on stack if hi > partition + 1
        if (hi > p + 1) {
            stack_push(stack, p + 1);
            stack_push(stack, hi);
        }
    }
    stack_delete(&stack);
}

//quick sort that utilizes a queue struct. Based of pseudocode
//from design doc. Code is exact same except for one spot and
//that it uses a queue instead of a stack.
//input: array, size of array
void quick_sort_queue(uint32_t *A, uint32_t n) {
    extern uint32_t compares, moves, max_queue_size;
    compares = 0;
    moves = 0;
    max_queue_size = 0;
    int64_t lo = 0, hi = n - 1;
    Queue *queue = queue_create(n);
    enqueue(queue, lo);
    enqueue(queue, hi);
    while (queue_empty(queue) != true) {
        if (queue_size(queue) > max_queue_size) {
            max_queue_size = queue_size(queue);
        }
        //only difference from previous function.
        //Stores first num off queue in lo first
        //because queues are First in First out.
        //Stacks are Last in Last out
        dequeue(queue, &lo);
        dequeue(queue, &hi);
        int64_t p = partition(A, lo, hi);
        if (p > lo) {
            enqueue(queue, lo);
            enqueue(queue, p);
        }
        if (hi > p + 1) {
            enqueue(queue, p + 1);
            enqueue(queue, hi);
        }
    }
    queue_delete(&queue);
}
