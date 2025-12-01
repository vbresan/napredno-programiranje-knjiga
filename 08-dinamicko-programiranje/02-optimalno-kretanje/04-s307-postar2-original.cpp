#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int DP[50][50][50][50];

int main() {

  int n, m;
  cin >> n >> m;

  vector<string> unos(n);
  for (int i = 0; i < n; ++i) {
    cin >> unos[i];
  }

  for (int i = 0; i < n; ++i) {
    for (int j1 = 0; j1 < m; ++j1) {
      for (int j2 = 0; j2 < j1; ++j2) {
        for (int j3 = 0; j3 < j2; ++j3) {
          DP[i][j3][j2][j1] = ((i == 0) ? 0 : DP[i - 1][j3][j2][j1]) +
                              unos[i][j3] - '0' + unos[i][j2] - '0' +
                              unos[i][j1] - '0';
        }
      }
    }
    for (int j1 = 0; j1 < m; ++j1) {
      for (int j2 = 0; j2 < j1; ++j2) {
        for (int j3 = 0; j3 < j2; ++j3) {
          if (j3 - 1 >= 0) {
            DP[i][j3][j2][j1] = max(DP[i][j3][j2][j1],
                                    DP[i][j3 - 1][j2][j1] + unos[i][j3] - '0');
          }
        }
      }
    }
    for (int j1 = 0; j1 < m; ++j1) {
      for (int j2 = 0; j2 < j1; ++j2) {
        for (int j3 = 0; j3 < j2; ++j3) {
          if (j2 - 1 >= j3) {
            DP[i][j3][j2][j1] = max(DP[i][j3][j2][j1],
                                    DP[i][j3][j2 - 1][j1] + unos[i][j2] - '0');
          }
        }
      }
    }
    for (int j1 = 0; j1 < m; ++j1) {
      for (int j2 = 0; j2 < j1; ++j2) {
        for (int j3 = 0; j3 < j2; ++j3) {
          if (j1 - 1 >= j2) {
            DP[i][j3][j2][j1] = max(DP[i][j3][j2][j1],
                                    DP[i][j3][j2][j1 - 1] + unos[i][j1] - '0');
          }
        }
      }
    }
  }

  cout << DP[n - 1][m - 3][m - 2][m - 1] << endl;

  return 0;
}
