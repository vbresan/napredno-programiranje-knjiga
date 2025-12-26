/*
Voćnjak se sastoji od stabala jabuka i krušaka i praznih polja raspoređenih u
pravokutnu matricu sa n redaka i m stupaca. Johnny i Save su gladni na početku
igre i nalaze se na gornjem lijevom polju matrice (polje (0,0)). Igra se
sastoji od zajedničkog kretanja kroz voćnjak i jedenja jabuka i krušaka.
Naizmjenično svatko radi jedno kretanje (potez), s time da počinje Johnny. Onaj
tko je na potezu odlučuje hoće li se kretati desno ili dolje i zajedno se
pomaknu za jedno polje u odabranom smjeru. Onaj tko je na potezu pojede 3 jabuke
ako su došli do stabla jabuke, ili 2 kruške ako su došli do stabla kruške. Igra
završava kada dođu do donjeg desnog polja (polje (n-1, m-1)). Pobjednik je onaj
tko se više najede (pojede više plodova) i gubitnik ga mora nositi kući. Ulazni
podaci su n i m (1 <= n,m <= 1000), zatim n redova s po m znakova koji mogu biti
'.' (prazno), '3' (jabuka) ili '2' (kruška). Johnny i Save igraju optimalno.
Treba ispisati, "Johnny" ili "Save", ovisno tko je pobjedio. Ako je izjednačeno,
onda Save pobjeđuje jer je Johnny prvi krenuo.

Ispis: Johnny
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main() {

  int n, m;
  cin >> n >> m;

  vector<string> field(n);
  for (int i = 0; i < n; ++i) {
    cin >> field[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == '.') {
        field[i][j] = '0';
      }
      field[i][j] -= '0';
    }
  }

  vector<vector<int>> dp(n, vector<int>(m));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = m - 1; j >= 0; --j) {
      if (i == n - 1 && j == m - 1) {
        continue;
      }
      if ((i + j) & 1) { // odd moves are by Save
        dp[i][j] = INF;
        if (i < n - 1) {
          dp[i][j] = min(dp[i][j], dp[i + 1][j] - field[i + 1][j]);
        }
        if (j < m - 1) {
          dp[i][j] = min(dp[i][j], dp[i][j + 1] - field[i][j + 1]);
        }
      } else { // even moves are by Johnny
        dp[i][j] = -INF;
        if (i < n - 1) {
          dp[i][j] = max(dp[i][j], dp[i + 1][j] + field[i + 1][j]);
        }
        if (j < m - 1) {
          dp[i][j] = max(dp[i][j], dp[i][j + 1] + field[i][j + 1]);
        }
      }
    }
  }

  cout << ((dp[0][0] > 0) ? "Johnny" : "Save") << endl;

  return 0;
}
