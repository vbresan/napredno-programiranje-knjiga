/* Napravi program koji unosi datum u obliku dan.mjesec.godina i ispisuje
 * koji je dan u tjednu. Uneseni datum ce biti poslije 1.1.1900. 1.1.1900 je
 * bio ponedjeljak.
 */

#include <stdio.h>

int prijestupna(int godina) {
  if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

int main() {

  int dan, mjesec, godina;
  scanf("%d.%d.%d", &dan, &mjesec, &godina);

  int razlika = 0;
  for (int i = 1900; i < godina; i++) {
    razlika += 365 + prijestupna(i);
  }

  int mjeseci[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  mjeseci[1] += prijestupna(godina);
  for (int i = 1; i < mjesec; i++) {
    razlika += mjeseci[i];
  }

  razlika += dan - 1;

  char *dani[] = {"ponedjeljak", "utorak", "srijeda", "cetvrtak",
                  "petak",       "subota", "nedjelja"};
  printf("%s\n", dani[razlika % 7]);

  return 0;
}
