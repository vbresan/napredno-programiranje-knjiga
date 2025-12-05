/*
U cijelom selu jedino Domagoj ima traktor. Domagoj iznajmljuje traktor.
Seljani su dali Domagoju svoje zamolbe za iznajmljivanje traktora. Ukupno ima
n zamolbi i svaka se zamolba sastoji od dvaju brojeva a i b, što znači da neki
seljak želi unajmiti traktor na dan a vratio bi ga na dan b (na dan b se
traktor ponovno može unajmiti). Domagoj želi traktor iznajmljivati na takav
način da što više dana bude iznajmljen, kako bi što više zaradio i kako bi on
morao što manje raditi. (Poznato je da se s traktorom mora stalno raditi pa
kad traktor nije iznajmljen, Domagoj mora s njime u polje). Ponekad se događa
da više zamolbi za unajmljivanje traktora počinju na isti dan, pa Domagoj mora
odabrati kome iznajmiti traktor. Ako je traktor slobodan na dan x i postoji
zamolba za unajmljivanje traktora od dana x, onda Domagoj mora iznajmiti
traktor (kako se seljani ne bi ljutili na njega). Ulazni podaci su n
(1 <=n <= 1000000) i m (1 <= m <= 1000000) i zatim n puta po dva broja a i b
koji opisuju pojedinu zamolbu (0 <= a < b <= m). Ispiši koliko najviše dana
traktor može biti iznajmljen.

Ispis: 11
*/

#include <iostream>
#include <vector>
using namespace std;

constexpr int NINF = numeric_limits<int>::min();

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> requests(m + 1);
  vector<bool> hasRequests(m + 1);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    requests[b].push_back(a);
    hasRequests[a] = true;
  }

  vector<int> dp(m + 1, NINF);
  dp[0] = 0;
  for (int i = 1; i <= m; ++i) {
    if (!hasRequests[i - 1]) {
      dp[i] = dp[i - 1];
    }
    for (int j = 0, size = requests[i].size(); j < size; ++j) {
      int start = requests[i][j];
      dp[i] = max(dp[i], dp[start] + (i - start));
    }
  }

  cout << dp[m] << endl;

  return 0;
}
