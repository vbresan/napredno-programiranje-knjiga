/* Brzo potenciranje. */

#include <stdio.h>

int main() {

  int baza, eksponent;
  scanf("%d %d", &baza, &eksponent);
  printf("%d na %d = ", baza, eksponent);

  int rjesenje = 1, potencija = baza;
  while (eksponent) {
    if (eksponent & 1) {
      rjesenje *= potencija;
    }

    potencija *= potencija;
    eksponent >>= 1;
  }

  printf("%d\n", rjesenje);

  return 0;
}
