/* Unesi dimenzije polja n (1 <= n <= 10), a zatim polje n^2 opisano sa n
 * redova koji sadrze n brojeva. Zatim uredno ispisi sva cetiri pravokutna
 * trokuta kojima je hipotenuza dijagonala (zajedno s dijagonalom). Elementi
 * polja su jednoznamenkasti. */

#include <stdio.h>

int main() {

  int polje[10][10];

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &polje[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i >= j) {
        printf("%d ", polje[i][j]);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i <= j) {
        printf("%d ", polje[i][j]);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + j <= n - 1) {
        printf("%d ", polje[i][j]);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + j >= n - 1) {
        printf("%d ", polje[i][j]);
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}
