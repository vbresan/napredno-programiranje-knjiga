/*
Neprijatelj je napao državu s n (1 <= n <= 100000) gradova i 
m (n-1 <= m <= 1000000) cesta između gradova. Gradovi su međusobno povezani. 
Grad je "bitan" ako bi njegovim osvajanjem neprijatelj razdvojio ostale 
gradove. Ispiši sve "bitne" gradove poredane po veličini. Ulazni podaci su 
n i m, zatim m puta po dva broja a i b (0 <= a,b <= n-1) koji predstavljaju 
dva 0-indeksirana grada povezana cestom.

Output: 2 5 6 8

*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
  bool isArticulation = false;
  int discovery = 0;
  int low = 0;
  vector<int> neighbors;
};

typedef vector<Node> Graph;

int dfs(Graph& graph, int parent, int node, int step) {

  graph[node].discovery = step;
  graph[node].low = step;

  int forks = 0;
  for (int neighbor : graph[node].neighbors) {
    
    if (neighbor == parent) {
      continue;
    }

    if (graph[neighbor].discovery > 0) {
      graph[node].low = min(graph[node].low, graph[neighbor].discovery);
      continue;
    }
    
    ++forks;
    int minDiscovery = dfs(graph, node, neighbor, step + 1);
    graph[node].low = min(graph[node].low, minDiscovery);

    if (graph[node].discovery <= graph[neighbor].low) {
      graph[node].isArticulation = true;
    }
  }

  if (parent == -1 && forks < 2) {
    graph[node].isArticulation = false;
  }

  return graph[node].low;
}

int main() {

  int n, m;
  cin >> n >> m;

  Graph graph(n);

  for (int i = 0; i < m; ++i) {
    
    int a, b;
    cin >> a >> b;
    if (a == b) {
      continue;
    }

    graph[a].neighbors.push_back(b);
    graph[b].neighbors.push_back(a);
  }

  dfs(graph, -1, 0, 1);

  for (int i = 0; i < n; ++i) {
    if(graph[i].isArticulation) {
      cout << i << ' ';
    }
  }

  cout << endl;
  

  return 0;
}