/*

Mala država želi povezati svoje gradove tako da izgradi ceste između njih.
Cilj je da svi gradovi budu povezani uz što manje troškove pri izgradnji
cesta. Ukupno postoji n gradova i postoji plan izgradnje za m cesta od
kojih treba neke izabrati. Ulazni podaci u prvoj liniji imaju brojeve n
(1 <= n <= 1000) i m (1 <= m <= n^2). Zatim se nalazi m puta po tri broja
a, b (0 <= a,b < n) i c (1 <= c <= 1000) koji opisuju plan za izgradnju
dvosmjerne ceste između gradova a i b koja košta c novaca. Ispiši najmanji
potreban trošak za povezivanje svih n gradova. (Gradovi će se moći povezati.)

output: 32

*/

#include <iostream>
#include <limits>
#include <vector>
using namespace std;

constexpr int INF = numeric_limits<int>::max();

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n, vector<int>(n, INF));
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a][b] = graph[b][a] = c;
  }

  vector<bool> visited(n, false);
  vector<int> costs(n, INF);
  costs[0] = 0;

  int total_cost = 0;
  for (int i = 0; i < n; ++i) {
    int min_cost = INF;
    int min_node = 0;
    for (int j = 0; j < n; ++j) {
      if (!visited[j] && min_cost > costs[j]) {
        min_cost = costs[j];
        min_node = j;
      }
    }

    total_cost += min_cost;
    visited[min_node] = true;

    for (int j = 0; j < n; ++j) {
      if (costs[j] > graph[min_node][j]) {
        costs[j] = graph[min_node][j];
      }
    }
  }

  cout << total_cost << endl;
  return 0;
}
