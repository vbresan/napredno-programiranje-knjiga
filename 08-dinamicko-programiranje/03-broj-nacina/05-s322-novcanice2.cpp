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

  vector<bool> dp(x + 1);
  dp[0] = true;

  vector<int> denominations(n);
  for (int & denomination : denominations) {
    cin >> denomination;
  }

  int count = 0;
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i - denominations[j] >= 0) {
        dp[i] = dp[i] || dp[i - denominations[j]];
      }
    }
    count += dp[i]? 1 : 0;
  }

  cout << count << endl;

  return 0;
}
