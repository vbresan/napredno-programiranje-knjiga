/* Zadana su dva broja a i b (2 <= a < b <= 10000). Napravi program koji
 * ispisuje sve proste (prim) brojeve iz intervala [a, b]. */

#include <stdio.h>

int main() {

  int a, b;
  scanf("%d %d", &a, &b);

  for (int i = a; i <= b; i++) {

    int prost = 1;
    for (int j = 2; j * j <= i && prost == 1; j++) {
      if (i % j == 0) {
        prost = 0;
      }
    }

    if (prost == 1) {
      printf("%d\n", i);
    }
  }

  return 0;
}
