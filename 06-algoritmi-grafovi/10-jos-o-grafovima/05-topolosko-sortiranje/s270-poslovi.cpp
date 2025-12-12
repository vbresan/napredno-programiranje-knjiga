/*
Treba napraviti n (1 <= n <= 100000) poslova koji su međusobno povezani. U 
prvoj su liniji brojevi n i m (1 <= m <= 1000000), zatim m parova 
0-indeksiranih poslova a i b koji znače da se posao a mora obaviti prije posla 
b. Treba ispisati neki poredak poslova ili "ERR" ako se poslovi nikako ne mogu 
posložiti.

Ispis:
1 9 3 5 7 4 2 0 6 8 10 11

*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
  bool isVisiting = false;
  bool isAdded = false;
  vector<int> predecessors;
};

typedef vector<Node> Graph;

bool dfs(Graph& graph, int node, vector<int>& sorted) {

  if (graph[node].isAdded) {
    return false;
  }

  if (graph[node].isVisiting) {
    return true;
  }
  
  graph[node].isVisiting = true;
  for (const int predecessor : graph[node].predecessors) {
    if (dfs(graph, predecessor, sorted)) {
      return true;
    }
  }

  graph[node].isVisiting = false;
  graph[node].isAdded = true;
  sorted.push_back(node);

  return false;
}

int main() {

  int n, m;
  cin >> n >> m;
  Graph graph(n);

  for (int i = 0; i < m; ++i) {

    int a, b;
    cin >> a >> b;
    graph[b].predecessors.push_back(a);
  }

  vector<int> sorted;
  bool hasCycle = false;
  for (int i = 0; i < n; ++i) {
    if (dfs(graph, i, sorted)) {
      hasCycle = true;
      break;
    }
  }

  if (hasCycle) {
    cout << "ERR" << endl;
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    cout << sorted[i] << ' ';
  }
  cout << endl;

  return 0;
}