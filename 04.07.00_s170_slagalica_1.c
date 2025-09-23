/*
Napravi program koji pronalazi i ispisuje poteze potrebne da bi se posložila
slagalica 2x3 ili ispisuje da ne postoji način. Slagalica 2x3 sastoji se od
brojeva od 1 do 6. Svaki broj se pojavljuje jednom i brojevi su posloženi u
matricu od 2 retka i 3 stupca. Cilj je brojeve, korištenjem nekog broja poteza,
posložiti u oblik:

123
456

Pritom se smiju koristiti samo potezi koji zamjenjuju dva broja na poljima
koja dijele zajedničku stranicu. Postoji ukupno 7 takvih poteza. To su zamjena
dvaju brojeva iz istog stupca ili zamjena dvaju susjednih brojeva u istom
retku. Ulazni podaci su 6 brojeva koji predstavljaju sadržaj slagalice.
*/

#include <stdio.h>

int visited[6][6][6][6][6][6]; // a-f, 0-5

int solve(int a, int b, int c, int d, int e, int f) {

  if (visited[a - 1][b - 1][c - 1][d - 1][e - 1][f - 1]) {
    return 0;
  }

  visited[a - 1][b - 1][c - 1][d - 1][e - 1][f - 1] = 1;

  if (a == 1 && b == 2 && c == 3 && d == 4 && e == 5 && f == 6) {
    printf("\n1 2 3\n4 5 6\n");
    return 1;
  }

  if (solve(d, b, c, a, e, f) || solve(a, e, c, d, b, f) ||
      solve(a, b, f, d, e, c) || solve(b, a, c, d, e, f) ||
      solve(a, c, b, d, e, f) || solve(a, b, c, e, d, f) ||
      solve(a, b, c, d, f, e)) {
    printf("\n%d %d %d\n%d %d %d\n", a, b, c, d, e, f);
    return 1;
  }

  return 0;
}

int main() {

  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  if (!solve(a, b, c, d, e, f)) {
    printf("No possible solution.\n");
  }

  return 0;
}
