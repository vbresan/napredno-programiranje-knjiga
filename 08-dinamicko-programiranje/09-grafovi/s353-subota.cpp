/*
Subota je, pa su Kova i Kuso, kao i svake subote, krenuli u obilazak kafića.
Kafići se nalaze u dugačkoj ulici koja se proteže od zapada prema istoku. Kova i
Kuso kreću iz početnog kafića koji je najzapadniji u ulici. Kafiće obilaze tako
da se prvo kreću samo prema istoku sve do najistočnijeg kafića i vraćaju se samo
prema zapadu do početnog, najzapadnijeg kafića. Cilj im je ući u što više
kafića, tako da u niti jedan, osim početnog, ne uđu dvaput. Kova i Kuso za svaki
kafić imaju omiljeno piće koje uvijek piju u tom kafiću. Problem je u tome što
ne mogu nakon svakog kafića ući u bilo koji drugi, jer bi se od nekih
kombinacija uzastopnih pića, koja ne idu zajedno, osjećali loše i uništili si
večer. Ulazni podaci se sastoje od broja n (1 <= n <= 400) i m (1 <= m <= 2500).
n je broj kafića, a m je broj različitih veza koje opisuju iz kojeg u koji kafić
se može ići. Slijedi m parova brojeva a i b (0 <= a,b < n) koji opisuju da se iz
kafića a može otići u kafić b (ne i obratno). Za svaki par kafića x i y, ako je
x < y, vrijedi da je kafić x zapadnije od kafića y. Kafić 0 je najzapadniji, a
kafić n-1 je najistočniji. Ispišite koliko najviše kafića Kova i Kuso mogu
posjetiti (početni kafić se broji samo jednom). Ulaz će biti takav da će se
uvijek moći otići do najistočnijeg kafica i natrag.

Ispis: 9
*/

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

constexpr int NINF = numeric_limits<int>::min() / 2;

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n), rgraph(n);
  for (int i = 0; i < m; ++i) {

    int a, b;
    cin >> a >> b;

    if (a == b) {
      continue;
    }

    graph[a].push_back(b);
    rgraph[b].push_back(a);
  }

  vector<vector<int>> dp(n, vector<int>(n, NINF));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j && i) {
        continue;
      }
      for (int k = 0; k < graph[i].size(); ++k) {
        if (graph[i][k] >= i && graph[i][k] >= j) {
          dp[graph[i][k]][j] = max(dp[graph[i][k]][j], dp[i][j] + 1);
        }
      }
      for (int k = 0; k < rgraph[j].size(); ++k) {
        if (rgraph[j][k] >= i && rgraph[j][k] >= j) {
          dp[i][rgraph[j][k]] = max(dp[i][rgraph[j][k]], dp[i][j] + 1);
        }
      }
    }
  }

  cout << dp[n - 1][n - 1] - 1 << endl;

  return 0;
}
