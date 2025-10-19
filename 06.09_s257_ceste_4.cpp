/*

Implementacija Kruskalovog algoritma.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  set<pair<int, pair<int, int>>> edges;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.emplace(c, make_pair(a, b));
  }

  vector<int> count(n, 1);
  vector<int> trees(n);
  iota(trees.begin(), trees.end(), 0);
  
  int total_distance = 0;
  for (int i = 0; i < n - 1; ++i) {

    const auto [distance, nodes] = *edges.begin();
    auto [from_node, to_node] = nodes;
    edges.erase(edges.begin());

    cout << "Node From: " << char('A' + from_node) << " To: " << char('A' + to_node) << "\t\t";

    while (trees[from_node] != from_node) {
      from_node = trees[from_node];
    }
    while (trees[to_node] != to_node) {
      to_node = trees[to_node];
    }
    
    cout << "Tree From: " << char('A' + trees[from_node]) << " To: " << char('A' + trees[to_node]);

    if (trees[from_node] == trees[to_node]) {
      cout << " (skipping)" << endl;
      --i;
      continue;
    }
    cout << endl;

    total_distance += distance;
    
    const int smaller = (count[from_node] < count[to_node])? from_node : to_node;
    const int bigger = (count[from_node] >= count[to_node])? from_node : to_node;

    trees[smaller] = trees[bigger];
    count[bigger] += count[smaller];
  }

  cout << total_distance << endl;
  return 0;
}
