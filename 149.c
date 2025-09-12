/* Unesi n (1 <= n <= 10000) i ispisi koliko neparnih znamenaka sadrzi n-ti
 * Fibonaccijev broj. */

#include <stdio.h>

#define MAX_BLOCKS 233 // max digits (2090) / digits per block (9)

int main() {

  int a[MAX_BLOCKS] = {0}, b[MAX_BLOCKS] = {0};
  a[0] = 0;
  b[0] = 1;

  int n;
  scanf("%d", &n);
  for (int i = 3; i <= n; i++) {
    for (int j = 0, overflow = 0; j < MAX_BLOCKS; j++) {
      a[j] += b[j] + overflow;
      overflow = a[j] / 1000000000;
      a[j] %= 1000000000;
    }
    for (int j = 0; j < MAX_BLOCKS; j++) {
      a[j] ^= b[j];
      b[j] ^= a[j];
      a[j] ^= b[j];
    }
  }

  int count = 0;
  for (int i = 0; i < MAX_BLOCKS; i++) {
    int block = b[i];
    while (block) {
      if ((block % 10) & 1) {
        count++;
      }
      block /= 10;
    }
  }

  printf("%d\n", count);
  return 0;
}
