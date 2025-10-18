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

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].emplace_back(c, b);
    graph[b].emplace_back(c, a);
  }

  vector<bool> visited(n, false);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      edges; // (cost, node)
  edges.emplace(0, 0);

  int total_cost = 0;
  int nodes_added = 0;
  while (nodes_added < n) {

    const auto [min_cost, min_node] = edges.top();
    edges.pop();

    if (visited[min_node]) {
      continue;
    }

    total_cost += min_cost;
    ++nodes_added;
    visited[min_node] = true;

    for (const auto &[cost, next_node] : graph[min_node]) {
      if (!visited[next_node]) {
        edges.emplace(cost, next_node);
      }
    }
  }

  cout << total_cost << endl;
  return 0;
}
