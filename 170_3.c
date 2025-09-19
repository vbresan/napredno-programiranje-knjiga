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

#define MAX_TRIES 1000

#include <stdio.h>

int visited[6][6][6][6][6][6]; // a-f, 0-5
int max_depth = 1;

void solve(int a, int b, int c, int d, int e, int f, int depth) {

  if (depth > max_depth) {
    return;
  }

  if (visited[a - 1][b - 1][c - 1][d - 1][e - 1][f - 1]) {
    if (visited[a - 1][b - 1][c - 1][d - 1][e - 1][f - 1] < depth) {
      return;
    }
  }

  visited[a - 1][b - 1][c - 1][d - 1][e - 1][f - 1] = depth;

  if (a == 1 && b == 2 && c == 3 && d == 4 && e == 5 && f == 6) {
    return;
  }

  solve(d, b, c, a, e, f, depth + 1);
  solve(a, e, c, d, b, f, depth + 1);
  solve(a, b, f, d, e, c, depth + 1);
  solve(b, a, c, d, e, f, depth + 1);
  solve(a, c, b, d, e, f, depth + 1);
  solve(a, b, c, e, d, f, depth + 1);
  solve(a, b, c, d, f, e, depth + 1);
}

int backtrack(int a, int b, int c, int d, int e, int f, int depth) {

  if (!depth || visited[a - 1][b - 1][c - 1][d - 1][e - 1][f - 1] != depth) {
    return 0;
  }

  if (depth == 1) {
    printf("\n%d %d %d\n%d %d %d\n", a, b, c, d, e, f);
    return 1;
  }

  if (backtrack(d, b, c, a, e, f, depth - 1) ||
      backtrack(a, e, c, d, b, f, depth - 1) ||
      backtrack(a, b, f, d, e, c, depth - 1) ||
      backtrack(b, a, c, d, e, f, depth - 1) ||
      backtrack(a, c, b, d, e, f, depth - 1) ||
      backtrack(a, b, c, e, d, f, depth - 1) ||
      backtrack(a, b, c, d, f, e, depth - 1)) {
    printf("\n%d %d %d\n%d %d %d\n", a, b, c, d, e, f);
    return 1;
  }

  return 0;
}

int main() {

  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

  int depth = 0;
  while (!depth && max_depth <= MAX_TRIES) {
    solve(a, b, c, d, e, f, 1);
    depth = visited[0][1][2][3][4][5];
    max_depth++;
  }

  // It is not working when solution is not possible. It loops forever.
  if (depth) {
    backtrack(1, 2, 3, 4, 5, 6, depth);
  } else {
    printf("No possible solutions.\n");
  }

  return 0;
}
