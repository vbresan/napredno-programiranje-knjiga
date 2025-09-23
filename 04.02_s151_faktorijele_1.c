/* Unesi n i ispisi s koliko nula zavrsava umnozak prvih n prirodnih brojeva n!
 */

#include <stdio.h>
int main() {

  int n;
  scanf("%d", &n);

  int count = 0;
  for (int i = 1; i <= n; i++) {
    int factor = i;
    while ((factor % 5) == 0) {
      count++;
      factor /= 5;
    }
  }

  printf("%d\n", count);
  return 0;
}
