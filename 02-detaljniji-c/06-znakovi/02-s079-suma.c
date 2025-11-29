/* Unesi x (1 <= x <= 10^100) i ispisi sumu njegovih znamenaka. */

#include <stdio.h>

int main() {

  char x[100 + 1 + 1];
  scanf("%s", x);

  int sum = 0;
  for (int i = 0; x[i]; i++) {
    sum += x[i] - '0';
  }

  printf("%d\n", sum);

  return 0;
}
