/* Unesi double d i int n (1 < n <= 10) i izracunaj n-ti korijen iz d na
 * 5 decimala. */

#include <math.h>
#include <stdio.h>

int main() {

  double d;
  int n;
  scanf("%lf %d", &d, &n);

  double donji = 0, gornji = 1;
  if (d > gornji) { // ovako program ispravno radi za d < 1
    gornji = d;
  }

  while (gornji - donji > 0.000005) {

    double korijen = (gornji + donji) / 2;
    double umnozak = pow(korijen, 5);
    if (umnozak > d) {
      gornji = korijen;
    } else {
      donji = korijen;
    }
  }

  printf("%.5lf\n", (gornji + donji) / 2);

  return 0;
}
