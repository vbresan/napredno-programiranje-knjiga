/*
Mirela radi za tajnu organizaciju i mora uočiti pravilnost između dva niza
podataka. Cilj joj je u dvama nizovima brojeva pronaći dužinu najdužeg (ne
obavezno povezanog) podniza koji se pojavljuje u oba niza. Ulazni podaci su
n i m (1 <= n,m <= 1000). n je dužina prvog niza brojeva, a m duzina drugog
niza brojeva. Nakon toga slijedi n cijelih brojeva i zatim m cijelih brojeva.
Ispisite duzinu najduzeg zajednickog podniza.

Ispis: 5
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int &number : a) {
    cin >> number;
  }

  vector<int> b(m);
  for (int &number : b) {
    cin >> number;
  }

  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {

      if (i) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      }
      if (j) {
        dp[i][j] = max(dp[i][j], dp[i][j - 1]);
      }
      if (a[i] == b[j]) {
        dp[i][j] = max(dp[i][j], ((i && j) ? dp[i - 1][j - 1] : 0) + 1);
      }
    }
  }

  cout << dp[n - 1][m - 1] << endl;

  return 0;
}
