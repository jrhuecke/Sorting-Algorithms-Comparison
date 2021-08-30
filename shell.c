#include "shell.h"

#include "gaps.h"
#include "stats.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

//shell sort based on pseudocode from assignment doc.
//inputs: array, size of array
void shell_sort(uint32_t *A, uint32_t n) {
    extern uint32_t compares, moves;
    compares = 0;
    moves = 0;
    //iterates through gaps array
    for (uint32_t i = 0; i < 102; i++) {
        //compares nums in array using current gap
        for (uint32_t j = gaps[i]; j < n; j++) {
            uint32_t k = j;
            uint32_t temp = A[j];
            moves += 1;
            //if the current num is less than the num the gap distance away
            //then it swaps them
            while (k >= gaps[i] && greater_than(A[k - gaps[i]], temp)) {
                A[k] = A[k - gaps[i]];
                moves += 1;
                k -= gaps[i];
            }
            A[k] = temp;
            moves += 1;
        }
    }
}
