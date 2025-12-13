/*
Potrebno je procijeniti koliko je neki skup novčanica koristan (koliko
različitih iznosa se može njime isplatiti). Zadan je broj različitih
novčanica n (1 <= n <= 10) i broj x ( 1 <= x <= 100000). Zatim slijedi n
brojeva a (1 <= a <= x) koji predstavljaju vrijednost pojedine novčanice.
Potrebno je ispisati koliko se različitih iznosa iz intervala [1,x] može
isplatiti pomoću zadanog skupa novčanica.

Ispis: 11
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, x;
  cin >> n >> x;

  vector<int> dp(x + 1);
  dp[0] = 1;

  vector<int> bills(n);
  for (int i = 0; i < n; ++i) {
    cin >> bills[i];
  }

  int count = 0;
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - bills[j] >= 0) {
        dp[i] |= dp[i - bills[j]];
      }
    }
    count += dp[i];
  }

  cout << count << endl;

  return 0;
}
