/* GCD (Euklidov algoritam) */

#include <stdio.h>

int gcd(int a, int b) {

  printf("a=%5d  b=%5d\n", a, b);

  if (!b) {
    return a;
  }

  a %= b;
  return gcd(b, a);
}

int main() {

  int a, b;
  scanf("%d %d", &a, &b);
  printf("gcd = %d\n", gcd(a, b));

  return 0;
}
