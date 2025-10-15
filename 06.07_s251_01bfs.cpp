#include <iostream>
#include <list>
#include <utility>
#include <vector>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main() {

  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }

  list<pair<int, int>> nodes;
  nodes.emplace_back(x, 0);

  vector<bool> visited(n, false);
  vector<int> distances(n, INF);
  while (!nodes.empty()) {

    const auto [node, distance] = nodes.back();
    nodes.pop_back();

    if (visited[node]) {
      continue;
    }

    visited[node] = true;
    distances[node] = distance;

    for (const auto [neighbor_node, neighbor_distance] : graph[node]) {
      if (visited[neighbor_node]) {
        continue;
      }

      if (neighbor_distance == 1) {
        nodes.emplace_front(neighbor_node, distance + 1);
      } else {
        nodes.emplace_back(neighbor_node, distance);
      }
    }
  }

  for (int distance : distances) {
    cout << distance << ' ';
  }
  cout << endl;

  return 0;
}
