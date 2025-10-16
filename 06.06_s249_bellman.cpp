/*

U prvoj liniji su zadana tri broja n (1 <= n <= 200), m (1 <= m <= n*n) i
x (0 <= x < n). n je broj čvorova, a m broj bridova u grafu. Zatim se m puta
unosi po 3 broja a, b (0 <= a,b < n) i c (-1000 <= c <= 1000). a i b su
0-indeksirani čvorovi povezani usmjerenim bridom (od a prema b) težine c.
Ispiši najkraću udaljenost od čvora x do svakog drugog čvora (svi čvorovi
bit će dohvatljivi od čvora x), ili ERR ako postoji negativni ciklus.

output:
7 4 -2 0 2

*/

#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, distance;
};

constexpr int INF = numeric_limits<int>::max() / 2;

int main() {

  int n, m, x;
  cin >> n >> m >> x;

  vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].from >> edges[i].to >> edges[i].distance;
  }

  vector<int> distances(n, INF);
  distances[x] = 0;

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m; j++) {
      int updated = distances[edges[j].from] + edges[j].distance;
      if (distances[edges[j].to] > updated) {
        distances[edges[j].to] = updated;
      }
    }
  }

  for (int j = 0; j < m; j++) {
    if (distances[edges[j].to] > distances[edges[j].from] + edges[j].distance) {
      cout << "ERR" << endl;
      return 0;
    }
  }

  for (int distance : distances) {
    cout << distance << ' ';
  }
  cout << endl;

  return 0;
}
