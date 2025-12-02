/* Unesi dva broja i ispisi njihov najmanji zajednicki visekratnik. */

#include <stdio.h>
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {

  int a, b;
  scanf("%d %d", &a, &b);

  for (int i = 2, divisor = gcd(a, b); divisor > 1;) {
    if (divisor % i == 0) {
      printf("%d\n", i);
      return 0;
    } else {
      i++;
    }
  }

  return 0;
}
