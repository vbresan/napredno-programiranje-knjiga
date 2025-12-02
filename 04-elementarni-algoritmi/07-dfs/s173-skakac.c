/* Unesi brojeve a, b, c i d (1 <= a, b, c, d <= 8) koji prestavljaju dvije
 * lokacije skakaca na sahovskoj ploci. Zatim unesi broj x ( 1 <= x <= 10) i
 * provjeri moze li skakac doci s polja a-b na polje c-d u x ili manje
 * poteza. */

#include <stdio.h>
int board[8][8];
int limit;

void visit(int a, int b, int step) {

  if (a < 0 || a > 7 || b < 0 || b > 7) {
    return;
  }

  if (board[a][b] != -1 && board[a][b] <= step) {
    return;
  }

  if (step > limit) {
    return;
  }

  board[a][b] = step;
  visit(a - 1, b - 2, step + 1);
  visit(a - 1, b + 2, step + 1);
  visit(a + 1, b - 2, step + 1);
  visit(a + 1, b + 2, step + 1);
  visit(a - 2, b - 1, step + 1);
  visit(a - 2, b + 1, step + 1);
  visit(a + 2, b - 1, step + 1);
  visit(a + 2, b + 1, step + 1);
}

void print_board() {

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }
}

int main() {

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      board[i][j] = -1;
    }
  }

  int a, b, c, d;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &limit);
  a--;
  b--;
  c--;
  d--;

  visit(a, b, 0);
  if (board[c][d] != -1) {
    printf("Can.\n");

  } else {
    printf("Can not.\n");
  }

  print_board();
  return 0;
}
