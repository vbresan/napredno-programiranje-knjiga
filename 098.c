/* Učiteljica vodi djecu u zabavni park. Kada se djeca zabavljaju učiteljica
 * to mora platiti, a kada se ne zabavljaju ne mora. Svako dijete unaprijed
 * odabere od kada do kada će se za- bavljati. Učiteljica svaku minutu mora
 * platiti ovisno o broju djece koji se tu minutu zabavljaju. Pri tome
 * učiteljica dobiva popust ako se više djece zabavlja. Unos se sastoji
 * od dva broja n (1 <= n <= 100000) i m (1 <= m <= 1000000). Zatim slijedi
 * n parova brojeva a ib (1 <= a <= b <= 10000) pri čemu svaki par brojeva
 * predstavlja uključni interval vremena unutar kojeg se pojedino dijete
 * zabavlja. Ako se u nekoj minuti zabavlja x djece, učiteljica tu minutu
 * plaća (m-x)*x novaca. (Nikad se neće zabavljati više od m djece.) Koliko
 * novaca će učiteljica ukupno potrošiti?
 */

#include <stdio.h>

int main() {

  int n, m;
  scanf("%d %d", &n, &m);

  int minute[10000 + 2] = {0};
  for (int i = 0; i < n; i++) {

    int a, b;
    scanf("%d %d", &a, &b);
    ++minute[a];
    --minute[b + 1];
  }

  for (int i = 1; i < 10002; i++) {
    minute[i] += minute[i - 1];
  }

  long long suma = 0;
  for (int i = 1; i < 10002; i++) {
    // 10,000 * 1,000,000 = 10,000,000,000 > long
    suma += (m - minute[i]) * (long long)minute[i];
  }

  printf("%lld\n", suma);

  return 0;
}
