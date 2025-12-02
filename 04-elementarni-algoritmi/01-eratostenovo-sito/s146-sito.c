/* Eratostenovo sito. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main() {

  int n;
  scanf("%d", &n);

  char *prosti = malloc(sizeof(char) * (n + 1));
  for (int i = 0; i <= n; i++) {
    prosti[i] = 1;
  }
  prosti[0] = prosti[1] = 0;

  int granica = sqrt(n);
  for (int i = 2; i <= granica; i++) {
    if (prosti[i]) {
      for (int j = i * i; j <= n; j += i) {
        prosti[j] = 0;
      }
    }
  }

  for (int i = 0; i <= n; i++) {
    if (prosti[i]) {
      printf("%d ", i);
    }
  }

  printf("\n");

  free(prosti);
  return 0;
}
