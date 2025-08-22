/*
* Napisi program koji unosi broj odigranih nogometnih utakmica 
* n (1 <= n <= 100) i u sljedecih n redova po 4 cijela broja a, b, c i d. Pri 
* tom su a i b (1 <= a, b <= 10) redni brojevi nogometnih ekipa koje su 
* odigrale utakmicu s rezultatom c:d (0 <= c, d <= 15) (ekipa a je dala c 
* zgoditaka, dok je ekipa b dala d zgoditaka). Nakon toga se unosi m 
* (1 <= m <= 20), a zatim m parova prirodnih brojeva x i y (1 <= x, y <= 10).
* Za svaki par ispisi koliko ukupno zgoditaka je ekipa x dala ekipi y.
*/

#include <stdio.h>

int main() {

  int zgodici[10][10] = {{0}};

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {

    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    zgodici[a - 1][b - 1] += c;
    zgodici[b - 1][a - 1] += d;
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {

    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", zgodici[x - 1][y - 1]);
  }

  return 0;
}
