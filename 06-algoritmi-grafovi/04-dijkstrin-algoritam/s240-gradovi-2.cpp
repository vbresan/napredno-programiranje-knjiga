#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main() {

  int n, m, x;
  cin >> n >> m >> x;

  // (index, distance)
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }

  vector<int> distances(n, INF);
  distances[x] = 0;

  // (distance, index) => because set is sorted by the first element
  set<pair<int, int>> closest;
  for (int i = 0; i < n; i++) {
    closest.emplace(INF, i);
  }
  closest.erase({INF, x});
  closest.emplace(0, x);

  vector<bool> visited(n, false);
  vector<int> parent(n, -1);

  for (int i = 0; i < n - 1; i++) {

    const auto [min_distance, min_node] = *closest.begin();
    closest.erase(closest.begin());

    visited[min_node] = true;
    for (auto [neighbor, distance] : graph[min_node]) {
      if (!visited[neighbor]) {
        int updated = min_distance + distance;
        if (distances[neighbor] > updated) {

          closest.erase({distances[neighbor], neighbor});
          closest.emplace(updated, neighbor);
          distances[neighbor] = updated;

          parent[neighbor] = min_node;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    int immediate = parent[i];
    cout << i << " ";
    while (immediate != -1) {
      cout << immediate << " ";
      immediate = parent[immediate];
    }
    cout << " -> udaljenost: " << distances[i] << endl;
  }

  return 0;
}
