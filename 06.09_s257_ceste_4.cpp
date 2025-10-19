/*

Implementacija Kruskalovog algoritma.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

int find(int node, vector<int>& trees) {

  if (trees[node] != node) {
    trees[node] = find(trees[node], trees);
  }
  
  return trees[node];
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<tuple<int, int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.emplace_back(c, a, b);
  }
  sort(edges.begin(), edges.end());

  vector<int> sizes(n, 1);
  vector<int> trees(n);
  iota(trees.begin(), trees.end(), 0);
  
  int total_distance = 0;
  int edges_added = 0;
  for (auto [distance, from, to] : edges) {

    cout << "Node From: " << char('A' + from) << " To: " << char('A' + to) << "\t\t";

    from = find(from, trees);
    to = find(to, trees);

    cout << "Tree From: " << char('A' + from) << " To: " << char('A' + to);

    if (from == to) {
      cout << " (skipping)" << endl;
      continue;
    }
    cout << endl;

    const auto [smaller, bigger] = (sizes[from] < sizes[to])?
      make_pair(from, to) : make_pair(to, from);

    trees[smaller] = bigger;
    sizes[bigger] += sizes[smaller];

    total_distance += distance;
    ++edges_added;

    if (edges_added == n - 1) {
      break;
    }
  }

  cout << total_distance << endl;
  return 0;
}
