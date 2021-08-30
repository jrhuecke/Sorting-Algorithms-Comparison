#include "stats.h"

#include <stdbool.h>
#include <stdint.h>

//checks if first input is larger than second input
//and than increase the external compares variable by 1
bool greater_than(uint32_t a, uint32_t b) {
    extern uint32_t compares;
    compares += 1;
    if (a > b) {
        return true;
    } else {
        return false;
    }
}
