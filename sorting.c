#include "bubble.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTIONS "absqQr:n:p:"

//Used to decide what functions to run, in what order, and to avoid multiple runs
//From Eugene's lab section
typedef enum Sort {
    BUBBLE,
    SHELL,
    QUICKS,
    QUICKQ,
} Sort;

//Prints out the table for bubble sort:
//Inputs: size of array, num elements to print, and the random seed
void bubble(uint32_t n, uint32_t num_to_print, uint32_t seed) {
    //sets random seed and then generates random array
    srandom(seed);
    uint32_t *arr = malloc(n * sizeof(int));
    for (uint32_t i = 0; i < n; i++) {
        arr[i] = random();
    }
    //puts the array through bubble sort
    bubble_sort(arr, n);
    //prints out the table five numbers at a time.
    //Every five numbers prints a newline.
    //printf code from assigment doc
    extern uint32_t compares, moves;
    printf("Bubble Sort\n");
    printf("%u elements, %u moves, %u compares", n, moves, compares);
    for (uint32_t i = 0; i < num_to_print; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    return;
}

//Basically the same as previous function except for shell sort
void shell(uint32_t n, uint32_t num_to_print, uint32_t seed) {
    srandom(seed);
    uint32_t *arr = malloc(n * sizeof(int));
    for (uint32_t i = 0; i < n; i++) {
        arr[i] = random();
    }
    shell_sort(arr, n);
    extern uint32_t compares, moves;
    printf("Shell Sort\n");
    printf("%u elements, %u moves, %u compares", n, moves, compares);
    for (uint32_t i = 0; i < num_to_print; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    return;
}

//Same as previous. For quicksort(stack)
//Also uses prints the max_stack_size external variable
void quicks(uint32_t n, uint32_t num_to_print, uint32_t seed) {
    srandom(seed);
    uint32_t *arr = malloc(n * sizeof(int));
    for (uint32_t i = 0; i < n; i++) {
        arr[i] = random();
    }
    quick_sort_stack(arr, n);
    extern uint32_t compares, moves, max_stack_size;
    printf("Quick Sort (Stack)\n");
    printf("%u elements, %u moves, %u compares\n", n, moves, compares);
    printf("Max stack size: %u", max_stack_size);
    for (uint32_t i = 0; i < num_to_print; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    return;
}

//Same as previous. For quicksort(queue)
//Also uses prints the max_queue_size external variable
void quickq(uint32_t n, uint32_t num_to_print, uint32_t seed) {
    srandom(seed);
    uint32_t *arr = malloc(n * sizeof(int));
    for (uint32_t i = 0; i < n; i++) {
        arr[i] = random();
    }
    quick_sort_queue(arr, n);
    extern uint32_t compares, moves, max_queue_size;
    printf("Quick Sort (Queue)\n");
    printf("%u elements, %u moves, %u compares\n", n, moves, compares);
    printf("Max queue size: %u", max_queue_size);
    for (uint32_t i = 0; i < num_to_print; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%13" PRIu32, arr[i]);
    }
    printf("\n");
    return;
}

int main(int argc, char **argv) {
    int opt = 0;
    uint32_t size = 100, num_to_print = 100, seed = 13371453;
    //creates empty array to store the command-line arguments in.
    //set struct from Pizza
    Set sorts = set_empty();

    //function table used for calling the functions. From Eugene's lab section
    void (*sort_funcs[4])(uint32_t size, uint32_t num_to_print, uint32_t seed)
        = { bubble, shell, quicks, quickq };

    //Takes the command-line arguments and stores them in the sorts set
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            sorts = set_insert(sorts, BUBBLE);
            sorts = set_insert(sorts, SHELL);
            sorts = set_insert(sorts, QUICKS);
            sorts = set_insert(sorts, QUICKQ);
            break;
        case 'b': sorts = set_insert(sorts, BUBBLE); break;
        case 's': sorts = set_insert(sorts, SHELL); break;
        case 'q': sorts = set_insert(sorts, QUICKS); break;
        case 'Q': sorts = set_insert(sorts, QUICKQ); break;
        //these three command arguments have called with them
        //which are optioned using optarg. atoi converts optarg
        //to an int
        case 'r': seed = atoi(optarg); break;
        case 'n': size = atoi(optarg); break;
        case 'p': num_to_print = atoi(optarg); break;
        }
    }
    //makes sure it wont print beyond the array's size
    if (num_to_print > size) {
        num_to_print = size;
    }
    //checks if a function needs to be run in the correct order.
    //Also only checks once to prevent a function being called
    //multiple times.
    for (Sort i = BUBBLE; i <= QUICKQ; i += 1) {
        if (set_member(sorts, i)) {
            sort_funcs[i](size, num_to_print, seed);
        }
    }
    return 0;
}
