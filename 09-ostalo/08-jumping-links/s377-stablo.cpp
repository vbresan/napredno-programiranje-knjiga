/*
Zadano je stablo sa n cvorova (stablo sa n cvorova uvijek ima n - 1 bridova).
Treba ispisati udaljenosti između zadanih parova cvorova. Ulazni podaci su
n i m (1 <= n,m <= 100000), zatim n-1 parova brojeva a i b (1 <= a,b < n) koji
opisuju pojedini brid u stablu. Nakon toga slijedi m parova brojeva a i b
(1 <= a,b < n) i za svaki par brojeva treba ispisati najkraći put u stablu
između čvora a i čvora b.

Ispis:
5 5 4 3 2 1 9 4 3 4
*/

#include <iostream>
#include <vector>
using namespace std;

#define LINK_HEIGHT 17 // log2(100000) = 16.61

void dfs(vector<vector<int>> &neighbors, vector<int> link[], vector<int> &d,
         int node, int depth) {

  d[node] = depth;
  for (int i = 0; i < neighbors[node].size(); ++i) {
    if (d[neighbors[node][i]] == -1) {
      link[0][neighbors[node][i]] = node;
      dfs(neighbors, link, d, neighbors[node][i], depth + 1);
    }
  }
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> neighbors(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    neighbors[a].push_back(b);
    neighbors[b].push_back(a);
  }

  vector<int> link[LINK_HEIGHT];
  for (int i = 0; i < LINK_HEIGHT; ++i) {
    link[i].insert(link[i].begin(), n, -1);
  }

  vector<int> d(n, -1);
  dfs(neighbors, link, d, 0, 0);

  for (int i = 1; i < LINK_HEIGHT; ++i) {
    for (int j = 0; j < n; ++j) {
      if (link[i - 1][j] != -1) {
        link[i][j] = link[i - 1][link[i - 1][j]];
      }
    }
  }

  for (int i = 0; i < m; ++i) {
    int result = 0, a, b;
    cin >> a >> b;

    if (d[a] > d[b]) {
      for (int j = LINK_HEIGHT - 1; j >= 0; --j) {
        if (d[a] - (1 << j) >= d[b]) {
          result += (1 << j);
          a = link[j][a];
        }
      }
    }
    if (d[b] > d[a]) {
      for (int j = LINK_HEIGHT - 1; j >= 0; --j) {
        if (d[b] - (1 << j) >= d[a]) {
          result += (1 << j);
          b = link[j][b];
        }
      }
    }
    if (a == b) {
      cout << result << ' ';
      continue;
    }
    for (int j = LINK_HEIGHT - 1; j >= 0; --j) {
      if (link[j][a] != link[j][b]) {
        a = link[j][a];
        b = link[j][b];
        result += 2 * (1 << j);
      }
    }

    cout << result + 2 << ' ';
  }

  cout << endl;
  return 0;
}
