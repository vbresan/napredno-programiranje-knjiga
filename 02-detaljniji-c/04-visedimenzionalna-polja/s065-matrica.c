/* Unesi n i m (1 <= n, m <= 10), a zatim n redova sa po m brojeva u pojedinom
 * retku. n redova s po m brojeva opisuje polje n x m. Ispisi polje istih
 * dimenzija, gdje na mjestu pojedinog elementa pise suma svih brojeva koji
 * imaju manji ili jednak indeks stupca ili retka (suma svih elementa iznad i
 * lijevo u polju).
 */

#include <stdio.h>

int main() {

  int polje1[10][10];
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &polje1[i][j]);
    }
  }

  int polje2[10][10] = {{0}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k <= i; k++) {
        for (int l = 0; l <= j; l++) {
          polje2[i][j] += polje1[k][l];
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", polje2[i][j]);
    }
    printf("\n");
  }

  return 0;
}
