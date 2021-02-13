#include <stdio.h>
#include <stdint.h>

// This is the length of each block containig the binary rappresentation of the occurrence for each digit
// Up to 6 bits (because 10 digits * 6 is the nearest to 64 which is the max size of uint64_t)
// this means also (6 bit) 111111 or (decimal) 63 MAX rep for each number 0-9
#define BITS_LENGTH 6

// Create a mask with the same length of the uint64_t (64 bit) with all 1s inside.
#define ALL_ONES_MASK ((uint64_t)1 << 63) - 1 



// Bit container
uint64_t rep = (uint64_t)0;

/*
    Get the occurrence of a digit
*/
unsigned getRep(unsigned n) {
    // Shift the bits of the digit n to the LSP and use a bitwise & to isolate the bits we need. 
    return (rep >> n*BITS_LENGTH) & ((1 << BITS_LENGTH) - 1);
}


/*
    Increase the number of times n is repeated.
*/
void incr(unsigned n) {
    uint64_t mask, nrep;

    nrep = getRep(n); // occurrence of specif digit.

    // Create a pattern of all 1s of BITS_LENGTH length. 
    // then shift it to the left in the bit position rappresenting the digit we need to count.
    uint64_t pattern1s = (((uint64_t)1 << BITS_LENGTH) - 1 ) << n*BITS_LENGTH;

    // then subract pattern1s from the ALL_ONES_MASK mask, obtaining a 
    // new mask that we'll use to bitwise AND rep to update the new repetition.
    mask = ALL_ONES_MASK - pattern1s;

    // first part resets the 4 bits block rappresenting the occurrence of the digit to 4 zeros.
    // then bitwise OR the result with the increment + 1 of nrep (rep of that digit) 
    // shifted to the left in the position of the 4 zeros bits spot created before.

    // in this way we can increment it without altering the others digits occurrence.
    rep = rep & mask | (nrep + 1 << BITS_LENGTH*n);

}



int main()
{
    unsigned current_rep = 0;
    int digit;

    printf("Input number: ");
    while (1) {
        digit = getchar();
        if (digit != '\n' && (digit >= '0' && digit <= '9')) {
            incr(digit - '0');
        }
        else
            break;
    }

    printf("\n"); // just a space

    for (unsigned i = 0; i < 10; i++) {
        current_rep = getRep(i);
        if (current_rep > 1) {
            printf("Occurrence of %u: %u\n", i, current_rep);
        }
    }

    
    return 0;
}
