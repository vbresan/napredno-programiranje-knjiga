/* Unesi x. Ispisi sumu brojeva x i "okrenutog" broja x.
   (Kada okrenemo 1234 dobijemo 4321)
*/

#include <stdio.h>

int main() {

  int x, a, b;

  scanf("%d", &x);
  a = x;
  b = 0;

  for (; x > 0; x /= 10) {
    b = b * 10 + x % 10;
  }

  printf("%d\n", a + b);
  return 0;
}
