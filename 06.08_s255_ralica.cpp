/*

Pao je snijeg koji ralica mora počistiti sa svih međugradskih cesta.
Postoji n gradova i m jednosmjernih cesta. Ispiši neku stazu kojom
ralica može obići svaku cestu točno jednom. Takva staza će postojati.
U prvom redu ulaznih podataka se nalaze dva broja n (1 <= n <= 1000)
i m (1 <= m <= n*n). Zatim se nalazi m puta po dva broja a i b
(0 <= a,b < n) koja označavaju da su gradovi a i b povezani cestom od
a prema b.

output:
1 6 4 1 3 2 6 3 5 2 0
(2 3 6 2 5 3 1 4 6 1 0)

*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> path;

void euler(int from) {
  while (!graph[from].empty()) {
    int to = graph[from].back();
    graph[from].pop_back();
    euler(to);
    path.emplace_back(from);
  }
}

int main() {

  int n, m;
  cin >> n >> m;

  graph.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[b].emplace_back(a);
  }

  euler(0);

  for (int node : path) {
    cout << node << ' ';
  }
  cout << endl;

  return 0;
}
