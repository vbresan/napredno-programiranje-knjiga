/*
Implementacija Kruskalovog algoritma.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n);
  set<pair<int, pair<int, int>>> edges(m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].emplace_back(c, b);
    graph[b].emplace_back(c, a);

    edges.emplace_back(c, a, b);
  }

  return 0;
}
