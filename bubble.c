#include "bubble.h"

#include "stats.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

//bubble sort based on the pseudocode from
//assignment doc.
//Inputs: array, size of array
void bubble_sort(uint32_t *A, uint32_t n) {
    extern uint32_t compares, moves;
    bool swapped = true;
    compares = 0;
    moves = 0;
    //runs until numbers stop getting swapped
    while (swapped) {
        swapped = false;
        //iterates through array
        for (uint32_t i = 1; i < n; i++) {
            //if the previous num is greater than current
            //num then it swaps them. greater than function
            //increments comparisons
            if (greater_than(A[i - 1], A[i])) {
                int32_t temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                moves += 3;
                swapped = true;
            }
        }
        n -= 1;
    }
    return;
}
