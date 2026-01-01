/*
Zadan je tlocrt grada kvadratnog oblika dimenzije n^2. Ulazni podaci se sastoje
od broja n (1 <= n <= 1000), zatim n linija s po n znakova. Svaki znak može biti
'.' (slobodan prostor) ili '#' (zauzet prostor). Ispišite površinu najvećeg
slobodnog pravokutnog (ne kvadratnog) prostora u gradu, čije su stranice
paralelne s tlocrtom grada.

Ispis: 12

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<string> city(n);
  for (string &row : city) {
    cin >> row;
  }

  vector<vector<short>> left(n, vector<short>(n));
  vector<vector<short>> right(n, vector<short>(n));

  for (int i = 0; i < n; ++i) {
    int last = 0;
    for (int j = 0; j < n; ++j) {
      ++last;
      if (city[i][j] == '#') {
        last = 0;
      }
      left[i][j] = last;
    }
    last = 0;
    for (int j = n - 1; j >= 0; --j) {
      ++last;
      if (city[i][j] == '#') {
        last = 0;
      }
      right[i][j] = last;
    }
  }

  int result = 0;
  for (int j = 0; j < n; ++j) {
    int last = 0, canLeft = 1000, canRight = 1000;
    for (int i = 0; i < n; ++i) {
      ++last;
      canLeft = min(canLeft, (int)left[i][j]);
      canRight = min(canRight, (int)right[i][j]);
      if (city[i][j] == '#') {
        last = 0;
        canLeft = canRight = 1000;
      }
      result = max(result, last * (canLeft + canRight - 1));
    }
  }

  cout << result << endl;

  return 0;
}
