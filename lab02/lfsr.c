#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

uint16_t get_bit(uint16_t num, uint16_t digit) 
{
    num >>= digit;
    return num & 1;
}

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    unsigned next_bit = ((get_bit(*reg, 0) ^ get_bit(*reg, 2)) ^ get_bit(*reg, 3)) ^ get_bit(*reg, 5);
    *reg = (*reg >> 1) | (next_bit << 15);
    /*
        Example:
        *reg = 00...011, next_bit = 1(just random example)
        *reg >> 1 is 00...001
        next_bit << 15 is 10000...(15 zeros)
        | operator is bitwise or, it compares each bit of its first operand to the corresponding bit of its second operand.
        so (*reg >> 1) | (next_bit << 15) is:
            0000000000000001
        OR  1000000000000001
        is  1000000000000001
    */
}

