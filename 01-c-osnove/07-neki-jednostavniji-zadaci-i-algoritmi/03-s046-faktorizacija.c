/* Ispisi rastav unesenog broja x na proste faktore, (1 <= x <= 1000000).  */

#include <stdio.h>

int main() {

  int x, i;
  scanf("%d", &x);
  for (i = 2; x > 1;) {
    if (x % i == 0) {
      printf("%d ", i);
      x /= i;
    } else {
      i++;
    }
  }

  printf("\n");
  return 0;
}
