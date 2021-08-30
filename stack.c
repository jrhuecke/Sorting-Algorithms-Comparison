#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//Stack struct. Code from Eugene's lab section
typedef struct Stack {
    uint32_t top;
    uint32_t capacity;
    int64_t *items;
} Stack;

Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = 0;
    s->capacity = capacity;
    //dynamically creates size by mulitplying the inputted capacity by the size of each element
    s->items = (int64_t *) malloc(capacity * sizeof(int64_t));
    return s;
}

//deletes the stack by freeing the items and making the pointer null
void stack_delete(Stack **s) {
    if (*s && (*s)->items) {
        free((*s)->items);
        free(*s);
        *s = NULL;
    }
    return;
}

//determines if empty by seeing if the pointer is at bottom of stack
bool stack_empty(Stack *s) {
    if (s->top == 0) {
        return true;
    } else {
        return false;
    }
}

//stack is full if pointer is at the max capacity
bool stack_full(Stack *s) {
    return s->top == s->capacity;
}

//returns where the pointer currently is
uint32_t stack_size(Stack *s) {
    return (s->top);
}

//first checks if stack is full and then moves given int onto the stack
//then moves the pointer foward
bool stack_push(Stack *s, int64_t x) {
    if (stack_full(s)) {
        return false;
    }
    s->items[s->top] = x;
    s->top += 1;
    return true;
}

//first checks if stack is emtpy and then returns the most recent int put on the stack
//moves pointer back
bool stack_pop(Stack *s, int64_t *x) {
    if (stack_empty(s)) {
        return false;
    } else {
        s->top -= 1;
        *x = s->items[s->top];
        return true;
    }
}

//uses for loop to print out the stack elements
void stack_print(Stack *s) {
    printf("[");
    for (uint32_t i = 0; i < s->top; i += 1) {
        printf("%" PRId64, s->items[i]);
        if (i + 1 != s->top) {
            printf(", ");
        }
    }
    printf("]\n");
}
