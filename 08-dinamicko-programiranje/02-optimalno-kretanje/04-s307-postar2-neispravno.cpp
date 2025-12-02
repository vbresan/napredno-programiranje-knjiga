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
#include <vector>
using namespace std;

int toint(char c) {
  return c - '0';
}


int main() {

  int n, m;
  cin >> n >> m;

  vector<vector<int>> room(n);
  for (int row = 0; row < n; ++row) {
    
    string s;
    cin >> s;

    for (int column = 0; column < m; ++column) {
      room[row].push_back(toint(s[column]));
    }
  }

  int total = 0;
  for (int i = 0; i < 3; ++i) {

    // find the best solution
    vector<vector<int>> dp = room;
    for (int column = 1; column < m; ++column) {
      dp[0][column] += dp[0][column - 1];
    }
    for (int row = 1; row < n; ++row) {
      dp[row][0] += dp[row - 1][0];
      for (int column = 1; column < m; ++column) {
        dp[row][column] += max(dp[row][column - 1], dp[row - 1][column]);
      }
    }

    total += dp[n - 1][m - 1];

    // backtrack the path and set it to 0's
    for (int row = n - 1, column = m - 1;;) {
      room[row][column] = 0;
      if (row == 0 && column == 0) {
        break;
      } else if (row == 0 && column > 0) {
        --column;
      } else if(row > 0 && column == 0) {
        --row;
      } else {
        if (dp[row][column - 1] > dp[row - 1][column]) {
          --column;
        } else {
          --row;
        }
      }
    }
  }

  cout << total << endl;
  return 0;
}