/* Unesi n (1 <= n <= 100000), a zatim niz od n cijelih brojeva koji su
 * poredani od manjeg prema vecem. Zatim unesi m (1 <= m <= 100000), a zatim
 * m cijelih brojeva. Redom za svaki od unesenih m brojeva ispisi na kojem se
 * mjestu nalazi u nizu, odnosno "ne" ako ga nema.
 */

#include <stdio.h>

int pretraga(int element, int niz[], int n) {

  int donji = 0, gornji = n - 1;
  while (donji <= gornji) {

    int sredina = donji + (gornji - donji) / 2;
    if (element == niz[sredina]) {
      return sredina;
    } else if (element < niz[sredina]) {
      gornji = sredina - 1;
    } else {
      donji = sredina + 1;
    }
  }

  return -1;
}

int main() {

  int n;
  scanf("%d", &n);

  int niz_1[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &niz_1[i]);
  }

  int m;
  scanf("%d", &m);

  int niz_2[m];
  for (int i = 0; i < m; i++) {
    scanf("%d", &niz_2[i]);
  }

  for (int i = 0; i < m; i++) {

    int index = pretraga(niz_2[i], niz_1, n);
    if (index >= 0) {
      printf("%d\n", index);
    } else {
      printf("ne\n");
    }
  }

  return 0;
}
