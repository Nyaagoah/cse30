/**
 * Assignment-1
 * Username:Nyaagoah _______ (fill out your username here)
 * Class: UCSD CSE30-S224
 */
#include <stdio.h>
#include <stdlib.h>

#define POLYNOMIAL_FORMAT "%x * 16^%d\n"

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "%s wrong number of arguments\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned int base10 = (unsigned) atoi(argv[1]);

    // Special case for 0
    if (base10 == 0) {
        printf(POLYNOMIAL_FORMAT, 0, 0);
        return EXIT_SUCCESS;
    }

    // Array to store hexadecimal digits
    unsigned int hex_digits[8];
    int power = 0;

    // Convert the number to hexadecimal and store the digits
    while (base10 > 0) {
        hex_digits[power] = base10 % 16;
        base10 /= 16;
        power++;
    }

    // Print the digits in the required format, starting from the least significant digit
    for (int i = 0; i < power; i++) {
        printf(POLYNOMIAL_FORMAT, hex_digits[i], i);
    }

    return EXIT_SUCCESS;
}
