/**
 * Assignment-1
 * Username: Nyaagoah (fill out your username here)
 * Class: UCSD CSE30-S224
 */
#include <stdio.h>
#include <stdlib.h>

#define POLYNOMIAL_FORMAT "%x * 16^%d\n"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        // Ensure the error message matches exactly
        fprintf(stderr, "%s: wrong number of arguments\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int base10 = (unsigned) atoi(argv[1]);

    // Special case for 0
    if (base10 == 0) {
        printf(POLYNOMIAL_FORMAT, 0, 0);
        return EXIT_SUCCESS;
    }

    // Array to store hexadecimal digits
    unsigned int hex_digits[8]; // Array to hold up to 8 hex digits (since 2147483647 in hex is 0x7FFFFFFF)
    int power = 0;

    // Convert the number to hexadecimal and store the digits
    while (base10 > 0) {
        hex_digits[power] = base10 % 16;
        base10 /= 16;
        power++;
    }

    // Print the digits in the required format, starting from the most significant
    for (int i = power - 1; i >= 0; i--) {
        printf(POLYNOMIAL_FORMAT, hex_digits[i], i);  // Corrected to print with the correct index for powers of 16
    }

    return EXIT_SUCCESS;
}
