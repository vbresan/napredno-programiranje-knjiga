/* Napravi program koji provjerava je li uneseni prirodni broj prost (prim).
   Broj 1 nije prost. */

#include <stdio.h>

int main() {

  int n;
  scanf("%d", &n);

  if (n == 1) {
    printf("1 nije prost\n");
    return 0;
  }

  if (n == 2) {
    printf("2 je prost\n");
    return 0;
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      printf("%d nije prost\n", n);
      return 0;
    }
  }

  printf("%d je prost\n", n);
  return 0;
}
