/*
Ivan ima pilu i reze ploce. Kad dobije ploču dimenzija AxB, on je u minimalno
poteza pilom razreže na ploče kvadratnog oblika. Svaki potez pilom paralelan
je s rubovima ploče i rezanjem nastaju ploče cjelobrojnih dimenzija (ploča
5x6 može se razrezati u ploče 2x6 i 3x6 ili npr. u 5x1 i 5x5, ali se ne može
razrezati na 2.3x6 i 2.7x6). Razrezane ploče ne mogu se zajedno rezati, tj.
reže se jedna po jedna (za rezanje ploče 4x4 na 4 ploče 2x2 treba 3 poteza
pilom, a ne 2). Ulazni podaci su A i B (1 <= A,B <= 100). Ispišite koliko
minimalno poteza pilom Ivan mora napraviti da bi ploču AxB razrezao na ploče
kvadratnog oblika.

Ispis: 5
*/

#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

constexpr int INF = numeric_limits<int>::max();

inline void order(int &a, int &b) {
  if (a > b) {
    swap(a, b);
  }
}

inline int get(const vector<vector<int>> &dp, int a, int b) {
  order(a, b);
  return dp[a][b];
}

int main() {

  int n, m;
  cin >> n >> m;
  order(n, m);

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= m; ++j) {
      dp[i][j] = INF;
      for (int k = 1; k <= i / 2; ++k) {
        dp[i][j] = min(dp[i][j], get(dp, k, j) + get(dp, i - k, j) + 1);
      }
      for (int k = 1; k <= j / 2; ++k) {
        dp[i][j] = min(dp[i][j], get(dp, i, k) + get(dp, i, j - k) + 1);
      }
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}
