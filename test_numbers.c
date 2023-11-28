#include <stdlib.h>
#include "numbers.h"

int main() {
  int number = 10;
  struct bits8 bitNumber = bits8_from_int(number); 
  printf("%d som binær er: ", number);
  bits8_print(bitNumber);
  printf("\nog som et tal igen: %d\n", bits8_to_int(bitNumber));
  struct bits8 bitNumber2 = bits8_add(bitNumber, bitNumber);
  bits8_print(bitNumber2);
  printf("\nog som et tal igen: %d\n", bits8_to_int(bitNumber2));
  struct bits8 bitnumber3= bits8_from_int(10);
  struct bits8 bitnumber4= bits8_from_int(10);
  struct bits8 bitnumber5 = bits8_mul(bitnumber3, bitnumber4);
  printf("10*10 er: ");
  bits8_print(bitnumber5);
  printf("\nog som et tal: %d", bits8_to_int(bitnumber5));
  printf("\nog her 10 som binært tal negatet: ");
  bits8_print(bits8_negate(bitnumber3));
  printf("\n");
}
