/*

Mala država želi povezati svoje gradove tako da izgradi ceste između njih.
Cilj je da svi gradovi budu povezani uz što manje troškove pri izgradnji
cesta. Ukupno postoji n gradova i postoji plan izgradnje za m cesta od
kojih treba neke izabrati. Ulazni podaci u prvoj liniji imaju brojeve n
(1 <= n <= 1000) i m (1 <= m <= n^2). Zatim se nalazi m puta po tri broja
a, b (0 <= a,b < n) i c (1 <= c <= 1000) koji opisuju plan za izgradnju
dvosmjerne ceste između gradova a i b koja košta c novaca. Ispiši najmanji
potreban trošak za povezivanje svih n gradova. (Gradovi će se moći povezati.)

*/

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1000000;

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }

  vector<bool> visited(n, false);
  vector<int> nodes(n);
  nodes.push_back(0);
  visited[0] = true;

  int total_cost = 0;
  for (int i = 0; i < n - 1; ++i) {
    int min_cost = INF;
    int min_node = 0;
    for (const int from : nodes) {
      for (const auto [to, cost] : graph[from]) {

        if (visited[to]) {
          continue;
        }

        if (cost <= min_cost) {
          min_cost = cost;
          min_node = to;
        }
      }
    }

    total_cost += min_cost;
    visited[min_node] = true;
    nodes.push_back(min_node);
  }

  cout << total_cost << endl;
  return 0;
}
