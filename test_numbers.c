#include <stdio.h>
#include <stdlib.h>
#include "numbers.h"

int main() {
    int number0 = 10;
    int number1 = 5;
    struct bits8 bitNumber0 = bits8_from_int(number0);
    struct bits8 bitNumber1 = bits8_from_int(number1);
    printf("%d as binary: ", number0);
    bits8_print(bitNumber0);
    printf("\nConverted back to integer: %d\n", bits8_to_int(bitNumber0));

    struct bits8 bitNumber2 = bits8_add(bitNumber0, bitNumber1);
    printf("Sum of %d and %d in binary: ", number0, number1);
    bits8_print(bitNumber2);
    printf("\nSum converted back to integer: %d\n", bits8_to_int(bitNumber2));

    struct bits8 bitNumber3 = bits8_from_int(10);
    struct bits8 bitNumber4 = bits8_from_int(9);
    struct bits8 bitNumber5 = bits8_mul(bitNumber3, bitNumber4);
    printf("Product of 10 and 9 in binary: ");
    bits8_print(bitNumber5);
    printf("\nProduct converted back to integer: %d\n", bits8_to_int(bitNumber5));

    printf("Negation of %d in binary: ", number0);
    bits8_print(bits8_negate(bitNumber3));
    printf("\n");
}
