/*
Zadani su n, m, x i y ,zatim m puta tri broja a, b i c. U jednostavnom
povezanom usmjerenom grafu s m bridova i n čvorova, pronađi i ispiši Network
flow od čvora x do čvora y. Brojevi a, b i c označavaju da od čvora a do
čvora b postoji usmjeren brid težine c. Čvorovi su 0-indeksirani.

Ispis: 87
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

constexpr int INF = numeric_limits<int>::max();

int main() {

  int n, m, start, end;
  cin >> n >> m >> start >> end;

  vector<vector<int>> graph(n, vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {

    int a, b, c;
    cin >> a >> b >> c;
    graph[a][b] = c;
  }

  vector<int> parent(n);
  int networkFlow = 0;
  while (true) {

    vector<bool> visited(n);
    vector<int> maxFlowToNode(n);
    maxFlowToNode[start] = INF;

    for (int i = 0; i < n - 1; ++i) {

      int node, maxFlow = -1;
      for (int j = 0; j < n; ++j) {
        if (!visited[j] && maxFlowToNode[j] > maxFlow) {
          node = j;
          maxFlow = maxFlowToNode[j];
        }
      }
      visited[node] = true;
      for (int j = 0; j < n; ++j) {

        int minFlow = min(maxFlow, graph[node][j]);
        if (minFlow > maxFlowToNode[j]) {
          maxFlowToNode[j] = minFlow;
          parent[j] = node;
        }
      }
    }

    if (maxFlowToNode[end] == 0) {
      break;
    }

    int flow = maxFlowToNode[end];
    networkFlow += flow;

    int node = end;
    while (node != start) {
      graph[parent[node]][node] -= flow;
      graph[node][parent[node]] += flow;
      node = parent[node];
    }
  }

  cout << networkFlow << endl;

  return 0;
}
