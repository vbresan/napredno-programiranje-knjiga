/* Unesi n i ispisi s koliko nula zavrsava umnozak prvih n prirodnih brojeva n!
 */

#include <stdio.h>

int main() {

  int n, count = 0;
  scanf("%d", &n);
  while (n) {
    count += n / 5;
    n /= 5;
  }

  printf("%d\n", count);
  return 0;
}
