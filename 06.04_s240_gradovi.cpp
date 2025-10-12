/*

Pronađi najkraći put od zadanog grada do svih ostalih i ispiši udaljenosti
od zadanog grada do svih gradova poredanih po njihovu indeksu. Ukupno
postoji n (1 <= n <= 1000) gradova i m (1 <= m <= n*n) cesta. Gradovi su
0-indeksirani. Ulazni podaci su n, m i x. x je početni grad. Zatim
slijedi m puta po tri broja a, b i c (0 <= a,b < n), (1 <= c <= 1000)
koji opisuju dvosmjernu cestu dužine c koja povezuje gradove a i b.
Postojat će put od svakog grada do svakog drugog.

out:
0 10 13 4 12 10 6 9 20

*/

#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

const int INF = 1'000'000;

int main() {

  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<int>> graph(n, vector<int>(n, INF));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (graph[a][b] > c) {
      graph[a][b] = graph[b][a] = c;
    }
  }

  vector<bool> visited(n, false);
  vector<int> distances(n, INF);
  distances[x] = 0;

  for (int i = 0; i < n - 1; i++) {

    int distance = INF + 1, node;
    for (int j = 0; j < n; j++) {
      if (distances[j] < distance && !visited[j]) {
        distance = distances[j];
        node = j;
      }
    }

    visited[node] = true;
    for (int j = 0; j < n; j++) {
      int updated = distance + graph[node][j];
      if (distances[j] > updated) {
        distances[j] = updated;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << distances[i] << " ";
  }
  cout << endl;

  return 0;
}
