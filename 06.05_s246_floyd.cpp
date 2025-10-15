#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main() {

  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<int>> graph(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    graph[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c < graph[a][b]) {
      graph[a][b] = graph[b][a] = c;
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int updated = graph[i][k] + graph[k][j];
        if (graph[i][j] > updated) {
          graph[i][j] = updated;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
