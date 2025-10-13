#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1'000'000;

int main() {

  int n, m, x;
  cin >> n >> m >> x;

  // (index, distance)
  vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }

  vector<int> distances(n, INF);
  distances[x] = 0;

  // (distance, index) => because set is sorted by the first element
  set<pair<int, int>> closest;
  for (int i = 0; i < n; i++) {
    closest.insert(make_pair(INF, i));
  }
  closest.erase(make_pair(INF, x));
  closest.insert(make_pair(0, x));

  vector<bool> visited(n, 0);
  vector<int> parent(n, -1);

  for (int i = 0; i < n - 1; i++) {

    int min_distance = closest.begin()->first;
    int min_node = closest.begin()->second;
    closest.erase(closest.begin());

    visited[min_node] = true;
    for (pair<int, int> neighbor : graph[min_node]) {
      if (!visited[neighbor.first]) {
        int updated = min_distance + neighbor.second;
        if (distances[neighbor.first] > updated) {

          closest.erase(make_pair(distances[neighbor.first], neighbor.first));
          closest.insert(make_pair(updated, neighbor.first));
          distances[neighbor.first] = updated;

          parent[neighbor.first] = min_node;
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
