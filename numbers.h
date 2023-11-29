#include <stdint.h>
#include "bits.h"
#include <assert.h>

struct bits8 {
  struct bit b0; 
  struct bit b1;
  struct bit b2;
  struct bit b3;
  struct bit b4;
  struct bit b5;
  struct bit b6;
  struct bit b7;
};


struct bits8 bits8_from_int(unsigned int x) {
  struct bits8 b;
  b.b0 = bit_from_int(x%2);
  x = x/2;
  b.b1 = bit_from_int(x%2);
  x = x/2;
  b.b2 = bit_from_int(x%2);
  x = x/2;
  b.b3 = bit_from_int(x%2);
  x = x/2;
  b.b4 = bit_from_int(x%2);
  x = x/2;
  b.b5 = bit_from_int(x%2);
  x = x/2;
  b.b6 = bit_from_int(x%2);
  x = x/2;
  b.b7 = bit_from_int(x%2);
  return b;
}
unsigned int bits8_to_int(struct bits8 x) {
  int sum = 0;
  sum += bit_to_int(x.b0);
  sum += 2*bit_to_int(x.b1);
  sum += 4*bit_to_int(x.b2);
  sum += 8*bit_to_int(x.b3);
  sum += 16*bit_to_int(x.b4);
  sum += 32*bit_to_int(x.b5);
  sum += 64*bit_to_int(x.b6);
  return sum;
}

void bits8_print(struct bits8 v) {
  bit_print(v.b7);
  bit_print(v.b6);
  bit_print(v.b5);
  bit_print(v.b4);
  bit_print(v.b3);
  bit_print(v.b2);
  bit_print(v.b1);
  bit_print(v.b0);
}


struct bits8 bits8_add(struct bits8 x, struct bits8 y) {
  struct bits8 s;
  struct bits8 c;
  s.b0 = bit_xor(x.b0, y.b0); 
  c.b0 = bit_and(x.b0, y.b0);
  s.b1 = bit_xor(bit_xor(x.b1, y.b1), c.b0); 
  c.b1 = bit_or(bit_and(x.b1, y.b1), bit_and(bit_or(x.b1, y.b1), c.b0));
  s.b2 = bit_xor(bit_xor(x.b2, y.b2), c.b1); 
  c.b2 = bit_or(bit_and(x.b2, y.b2), bit_and(bit_or(x.b2, y.b2), c.b1));
  s.b3 = bit_xor(bit_xor(x.b3, y.b3), c.b2); 
  c.b3 = bit_or(bit_and(x.b3, y.b3), bit_and(bit_or(x.b3, y.b3), c.b2));
  s.b4 = bit_xor(bit_xor(x.b4, y.b4), c.b3); 
  c.b4 = bit_or(bit_and(x.b4, y.b4), bit_and(bit_or(x.b4, y.b4), c.b3));
  s.b5 = bit_xor(bit_xor(x.b5, y.b5), c.b4); 
  c.b5 = bit_or(bit_and(x.b5, y.b5), bit_and(bit_or(x.b5, y.b5), c.b4));
  s.b6 = bit_xor(bit_xor(x.b6, y.b6), c.b5); 
  c.b6 = bit_or(bit_and(x.b6, y.b6), bit_and(bit_or(x.b6, y.b6), c.b5));
  s.b7 = bit_xor(bit_xor(x.b7, y.b7), c.b6); 
  c.b7 = bit_or(bit_and(x.b7, y.b7), bit_and(bit_or(x.b7, y.b7), c.b6));
  return s;
}
struct bits8 bits8_negate(struct bits8 x) {
  struct bits8 c;
  c.b0.v = 1;
  c.b1.v = 0;
  c.b2.v = 0;
  c.b3.v = 0;
  c.b4.v = 0;
  c.b5.v = 0;
  c.b6.v = 0;
  c.b7.v = 0;
  x.b0 = bit_not(x.b0);
  x.b1 = bit_not(x.b1);
  x.b2 = bit_not(x.b2);
  x.b3 = bit_not(x.b3);
  x.b4 = bit_not(x.b4);
  x.b5 = bit_not(x.b5);
  x.b6 = bit_not(x.b6);
  x.b7 = bit_not(x.b7);
  return bits8_add(x, c);
}

struct bit make_zero(void) {
  struct bit b;
  b.v = 0;
  return b;
}

int bits8_to_int_signed(struct bits8 x) {
  int z;
  z = (-128)*bit_to_int(x.b7) + 64*bit_to_int(x.b6) + 32*bit_to_int(x.b5) + 16*bit_to_int(x.b4) + 8 * bit_to_int(x.b3) + 4 * bit_to_int(x.b2) + 2 * bit_to_int(x.b1) + bit_to_int(x.b0);
  return z; 
}
