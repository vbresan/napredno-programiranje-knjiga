/* Unesi n (1 <= n <= 1000) i ispisi koliko znamenaka jednakih jedinici sadrzi
 * umnozak prvih n prirodnih brojeva n! */

/* 1000! has 2,568 digits. When using 1,000,000,000-sized blocks it is 286
 * blocks. */

#include <stdio.h>

#define BLOCK_SIZE 1000000000
#define BLOCK_NUM 286

int main() {

  int a[BLOCK_NUM] = {0};
  a[0] = 1;

  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < BLOCK_NUM; j++) {
      a[j] *= i;
    }
    for (int j = 1; j < BLOCK_NUM; j++) {
      a[j] += a[j - 1] / BLOCK_SIZE;
      a[j - 1] %= BLOCK_SIZE;
    }
  }

  int count = 0;
  for (int i = 0; i < BLOCK_NUM; i++) {
    int block = a[i];
    printf("%d ", block);
    while (block) {
      if (block % 10 == 1) {
        count++;
      }
      block /= 10;
    }
  }

  printf("%d\n", count);
  return 0;
}
