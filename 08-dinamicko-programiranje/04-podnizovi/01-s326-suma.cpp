/*
Nogometni klub vodi evidenciju o financijskim dobicima i gubicima. Svaki
tjedan zabilježi se neki broj x (-1000 <= x <= 1000) koji predstavlja dobitak
ili gubitak ostvaren tijekom prošlog tjedna. Upravu kluba zanima koliko je
klub ikad najviše zaradio u nekom vremenskom intervalu. Ulazni podaci su n
(1 <= n <= 1000000) i zatim n brojeva x (barem će jedan x biti pozitivan).
Ispišite najveću sumu nekih uzastopnih brojeva u unesenom nizu.

Ispis: 21
*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int dp = 0, maximum = 0;
  for (int i = 0; i < n; ++i) {

    int input;
    cin >> input;

    dp = max(dp + input, 0);
    maximum = max(maximum, dp);
  }

  cout << maximum << endl;

  return 0;
}
