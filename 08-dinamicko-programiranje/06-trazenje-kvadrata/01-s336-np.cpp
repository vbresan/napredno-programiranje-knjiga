/*
Država pravokutnog oblika dimenzije n x n odlučila je što veći dio svog
teritorija, kvadratnog oblika, proglasiti nacionalnim parkom. Ulazni podaci su
n (1 <= n <= 1000) i zatim n linija s po n znakova koji opisuju izgled države.
Svaki znak može predstavljati slobodan prostor '.', ili naseljen prostor '#'.
Treba pronaći najveći nenaseljeni dio državnog teritorija koji je kvadratnog
oblika. Ispišite veličinu stranice najvećeg nenaseljenog dijela teritorija
kvadratnog oblika. (Napomena: Pronađeni kvadrat mora biti orijentiran
paralelno s rubovima države.)

Ispis: 4
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

inline int min3(int a, int b, int c) { return min(min(a, b), c); }

inline int get(const vector<vector<int>> &dp, int x, int y) {
  return (x < 0 || y < 0) ? 0 : dp[x][y];
}

int main() {

  int n;
  cin >> n;

  vector<string> input(n);
  for (int i = 0; i < n; ++i) {
    cin >> input[i];
  }

  vector<vector<int>> dp(n, vector<int>(n));
  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (input[i][j] == '.') {
        dp[i][j] =
            min3(get(dp, i - 1, j), get(dp, i, j - 1), get(dp, i - 1, j - 1)) +
            1;
        result = max(result, dp[i][j]);
      }
    }
  }

  cout << result << endl;

  return 0;
}
