/* Ispisi prvu potenciju broja 2 vecu ili jednaku unesenom broju.  */

#include <stdio.h>

int main() {

  int n, pot = 1;
  scanf("%d", &n);
  while (pot < n) {
    pot *= 2;
  }

  printf("%d\n", pot);

  return 0;
}
