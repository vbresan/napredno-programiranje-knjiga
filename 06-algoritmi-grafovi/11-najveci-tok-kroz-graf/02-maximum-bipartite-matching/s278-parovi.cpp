/*
Unosi se n1 (broj čvorova iz prvog skupa), n2 (broj čvorova iz drugog skupa)
i m, zatim m bridova opisanih s po dva broja a i b. Čvor a (0 < = a < n) iz
prvog skupa je povezan bridom s čvorom b (0 < = b < n2) iz drugog skupa.
Ispiši koliko najviše parova čvorova se može povezati (nekim od postojećih
bridova) tako da je svaki čvor povezan s najviše jednim čvorom.

Odgovarajuci ispis:
5
  Slijedi dodani ispis:
A + 4
B + 2
C + 3
D + 1
E + 5
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> pairs;

int dfs(int node) {

  visited[node] = true;
  for (int neighbor : graph[node]) {
    if (pairs[neighbor] == -1 ||
        (!visited[pairs[neighbor]] && dfs(pairs[neighbor]))) {
      pairs[neighbor] = node;
      return 1;
    }
  }
  return 0;
}

int main() {

  int n1, n2, m;
  cin >> n1 >> n2 >> m;

  graph.resize(n1);
  pairs.resize(n2, -1);

  for (int i = 0; i < m; ++i) {

    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
  }

  int paired = 0;
  for (int i = 0; i < n1; ++i) {
    visited = vector<bool>(n1);
    paired += dfs(i);
  }

  cout << paired << endl;
  cout << "  Slijedi dodani ispis:" << endl;
  for (int i = 0; i < n2; ++i) {
    cout << (char)(i + 'A') << " + " << pairs[i] + 1 << endl;
  }

  return 0;
}
