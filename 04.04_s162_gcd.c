/* Unesi n (2 <= n <= 100000) i zatim n prirodnih brojeva. Ispisi njihov
 * najveci zajednicki djelitelj. */

#include <stdio.h>
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {

  int n, solution;
  scanf("%d %d", &n, &solution);
  for (int i = 0; i < n - 1; i++) {

    int next;
    scanf("%d", &next);
    solution = gcd(solution, next);
  }

  printf("%d\n", solution);

  return 0;
}
