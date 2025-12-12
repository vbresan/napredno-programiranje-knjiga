/*

Učenici iz razreda dodaju se loptom. Svaki učenik slučajno odabire nekog od
svojih prijatelja i doda mu loptu. Nisu svi u razredu međusobno prijatelji.
Koliko najmanje lopti profesor treba dati učenicima tako da svatko može
dobiti loptu? Ulazni podaci se sastoje od broja učenika: n (2 <= n <=10000)
i m (1 <= m <= 100000), a zatim m parova brojeva a i b (1 <= a, b<=n).
a i b su dva učenika koji su međusobno prijatelji.

*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> visited;

void floodFill(int index) {

  visited[index] = 1;
  for (int i = 0; i < graph[index].size(); i++) {
    if (!visited[graph[index][i]]) {
      floodFill(graph[index][i]);
    }
  }
}

int main() {

  int n, m;
  cin >> n >> m;

  graph.resize(n, vector<int>());
  visited.insert(visited.begin(), n, 0);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      count++;
      floodFill(i);
    }
  }

  cout << count << endl;
  return 0;
}
