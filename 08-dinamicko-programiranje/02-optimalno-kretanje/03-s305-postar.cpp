/*
Poštanski ured ima posebnu prostoriju oblika matrice n x m. Na svakom polju
te matrice nalazi se od 0 do 9 pisama koja poštari trebaju raznijeti. Prije
nego krene raznositi pisma, poštar uđe u opisanu prostoriju s namjerom da
uzme što više pisama krećući se kroz prostoriju (matricu) isključivo prema
dolje ili desno. Poštar kreće iz gornjeg lijevog kuta prostorije i završava
s uzimanjem pisama u donjem desnom kutu prostorije. Koliko najviše pisama
poštar može uzeti? Ulazni podaci su n i m (1 <= n,m <= 1000), zatim n redova
koji sadrze niz od m brojeva x (0 <= x <= 9).

Ispis: 98
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

  vector<int> row(m);
  string s;
  cin >> s;

  row[0] = toint(s[0]);
  for (int i = 1; i < m; ++i) {
    row[i] = row[i - 1] + toint(s[i]);
  }

  for (int i = 1; i < n; ++i) {
    
    cin >> s;

    vector<int> previous = row;
    row[0] = previous[0] + toint(s[0]);
    for (int j = 1; j < m; ++j) {
      row[j] = max(row[j - 1], previous[j]) + toint(s[j]);
    }
  }

  cout << row[m - 1] << endl;

  return 0;
}