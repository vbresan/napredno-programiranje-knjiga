/*
Poštanski ured ima posebnu prostoriju oblika matrice n x m. Na svakom polju
te matrice nalazi se od 0 do 9 pisama koja treba raznijeti. Prije nego krene
raznositi pisma, poštar uđe u opisanu prostoriju s namjerom da uzme što više
pisama obilazeći prostoriju (matricu) triput. Prvi se put kreće od gornjeg
lijevog kuta do donjeg desnog kuta, isključivo prema dolje ili desno. Nakon
toga se kreće obrnuto, tj. od donjeg desnog kuta do gornjeg lijevog
isključivo prema gore ili lijevo. Nakon toga se ponovno kreće od gornjeg
lijevog kuta prema donjem desnom isključivo prema dolje ili desno. Ista se
pisma ne mogu pokupiti dvaput. Koliko najviše pisama poštar može uzeti?
Ulazni podaci su n i m (3 <= n,m <= 50), zatim n redova koji sadrže niz od m
brojeva t (0 <= t <= 9).

Ispis: 196

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<string> unos(n);
  for (int i = 0; i < n; ++i) {
    cin >> unos[i];
  }

  vector<vector<vector<vector<int>>>> DP(n, 
    vector<vector<vector<int>>>(m, 
      vector<vector<int>>(m, 
        vector<int>(m, 0))));

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

  /*
  for (int i = 0; i < n; ++i) {
    for (int j1 = 0; j1 < m; ++j1) {
      for (int j2 = 0; j2 < m; ++j2) {
        for (int j3 = 0; j3 < m; ++j3) {
          if (DP[i][j3][j2][j1] ) {
            cout << "DP[" << i << "][" << j3 << "][" << j2 << "][" << j1 << "] = " << DP[i][j3][j2][j1] << endl;
          }
        }
      }
    }
  }
  */

  return 0;
}
