/* Ternarna pretraga */

#include <stdio.h>

int pretraga(int niz[], int n) {

  int donja = 0, gornja = n - 1;
  while (gornja - donja > 2) {

    int s1 = donja + (gornja - donja) / 3;
    int s2 = gornja - (gornja - donja) / 3;

    if (niz[s1] < niz[s2]) {
      donja = s1;
    } else {
      gornja = s2;
    }
  }

  return niz[(gornja + donja) / 2];
}

int main() {

  int n;
  scanf("%d", &n);

  int niz[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &niz[i]);
  }

  int rezultat = pretraga(niz, n);
  printf("%d\n", rezultat);

  return 0;
}
