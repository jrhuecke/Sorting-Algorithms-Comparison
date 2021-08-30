#ifndef __STATS_H__
#define __STATS_H__

#include <stdbool.h>
#include <stdint.h>

uint32_t compares;
uint32_t moves;
uint32_t max_stack_size;
uint32_t max_queue_size;

bool greater_than(uint32_t a, uint32_t b);

#endif
