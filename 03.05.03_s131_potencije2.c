/* Ispisi potencije broja 2 koje se nalaze u zadanom broju. */

#include <stdio.h>
int main() {

  int broj;
  scanf("%d", &broj);

  while (broj) {

    int najmanja = broj & -broj;
    printf("%d ", najmanja);

    broj -= najmanja;
  }

  printf("\n");
  return 0;
}
