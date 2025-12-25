/*
Država pravokutnog oblika dimenzije n x n je za potrebe proglašavanja
nacionalnog parka odlučila analizirati svoj teritorij. Ulazni podaci su
n (1 <= n <= 1000) i zatim n linija s po n znakova koji opisuju izgled države.
Svaki znak može predstavljati slobodan prostor '.', ili naseljen prostor '#'.
Treba ispisati koliko različitih kvadratnih nenaseljenih područja svake
veličine postoji. Za potrebu analize se pronađena kvadratna područja mogu
preklapati. (Napomena: Pronađena kvadratna područja moraju biti orijentirana
paralelno s rubovi- i ma države.)

Ispis:
Velicine 1 x 1 : 44
Velicine 2 x 2 : 19
Velicine 3 x 3 : 5
Velicine 4 x 4 : 1

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
  vector<int> result(n + 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (input[i][j] == '.') {
        dp[i][j] =
            min3(get(dp, i - 1, j), get(dp, i, j - 1), get(dp, i - 1, j - 1)) +
            1;
        ++result[dp[i][j]];
      }
    }
  }

  for (int i = n - 1; i; --i) {
    result[i] += result[i + 1];
  }

  for (int i = 1; i <= n; ++i) {
    if (result[i]) {
      cout << "Velicine " << i << " x " << i << " : " << result[i] << endl;
    }
  }

  return 0;
}
