/*
Ispisi povrsinu najveceg pravokutnika u histogramu. Histogram je niz "stupica"
odredjene visine. Ulazni podaci su n (1 <= n <= 100000), zatim n brojeva x
(1 <= x <= 1000000) koji predstavljaju visinu pojedinog "stupica".

Ispis: 35
*/

#include <algorithm>
#include <vector>
using namespace std;

vector<int> histograms;
int result;

int tournamentQuery(int a, int b);

void DaC(int a, int b) {

  if (a > b) {
    return;
  }

  if (a == b) {
    result = max(result, histograms[a]);
    return;
  }

  int min = tournamentQuery(a, b);
  result = max(result, (b - a + 1) * histograms[min]);

  DaC(a, min - 1);
  DaC(min + 1, b);
}
