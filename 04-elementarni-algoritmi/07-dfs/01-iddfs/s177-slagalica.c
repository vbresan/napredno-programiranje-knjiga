/* Slozi rotacijama slagalicu 3x3 koristeci minimalan broj poteza. Pritom
 * ispisi sva stanja slagalice obrnutim redoslijedom. Slagalica 3x3 se treba
 * sloziti u sljedeci oblik:
 *
 * 1 2 3
 * 4 5 6
 * 7 8 9
 *
 * Pritom se mogu koristiti 4 razlicite vrste rotacija. Rotacijom se 4 brojke
 * koje se medjusobno dodiruju (kvadrant 2x2) zamijene u smjeru kazaljke na
 * satu. */

#include <stdio.h>

int solve(int a, int b, int c, int d, int e, int f, int g, int h, int i,
          int depth) {

  if (a == 1 && b == 2 && c == 3 && d == 4 && e == 5 && f == 6 && g == 7 &&
      h == 8 && i == 9) {
    printf("\n%d %d %d\n%d %d %d\n%d %d %d\n", a, b, c, d, e, f, g, h, i);
    return 1;
  }

  if (depth == 0) {
    return 0;
  }

  if (solve(d, a, c, e, b, f, g, h, i, depth - 1) ||
      solve(a, e, b, d, f, c, g, h, i, depth - 1) ||
      solve(a, b, c, g, d, f, h, e, i, depth - 1) ||
      solve(a, b, c, d, h, e, g, i, f, depth - 1)) {
    printf("\n%d %d %d\n%d %d %d\n%d %d %d\n", a, b, c, d, e, f, g, h, i);
    return 1;
  }

  return 0;
}

int main() {

  int a, b, c, d, e, f, g, h, i;
  scanf("%d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i);

  for (int depth = 0; depth <= 12; depth++) {
    if (solve(a, b, c, d, e, f, g, h, i, depth)) {
      break;
    }
  }

  return 0;
}
