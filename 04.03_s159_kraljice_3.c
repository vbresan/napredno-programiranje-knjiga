/* Na koliko se nacina na sahovsku plocu moze staviti 8 kraljica, tako da se
 * nijedan par medjusobno ne napada. */

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int solutions;

void print_array(int array[], int end) {
  for (int i = 0; i <= end; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int is_safe(int board[], int row, int column, int n) {

  for (int prev_column = 0; prev_column < column; prev_column++) {
    if (board[prev_column] == row) {
      return 0;
    }
    if (abs(board[prev_column] - row) == abs(prev_column - column)) {
      return 0;
    }
  }

  return 1;
}

void solve_n_queens(int board[], int column, int n) {

  if (column == n) {
    // print_array(array, end);
    solutions++;
    return;
  }

  for (int row = 0; row < n; row++) {
    if (is_safe(board, row, column, n)) {
      board[column] = row;
      solve_n_queens(board, column + 1, n);
    }
  }
}

int main() {

  int board[BOARD_SIZE];

  solve_n_queens(board, 0, BOARD_SIZE);
  printf("%d\n", solutions);

  return 0;
}
