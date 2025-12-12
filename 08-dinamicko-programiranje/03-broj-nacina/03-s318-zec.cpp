/*
Zec trči kroz šumu pravokutnog oblika. Šuma ima prohodna polja i polja na
kojima je kamen. Zec se ne može kretati poljima na kojima je kamen. Na koliko
načina zec može doći iz gornjeg lijevog kuta šume do donjeg desnog, ako se
kreće isključivo prema dolje ili desno. Ulazni podaci su n i m
(1 <= n,m <=1000), zatim n redova od po m znakova '.' ili 'x'. '.' je
prohodno polje, a 'x' je kamen. Ispišite ostatak pri dijeljenju broja načina
na koji zec može doći od gornjeg lijevog polja šume do donjeg desnog,
s 1000000.

Napomene: Moguće je da je broj načina 0, zbog kamenja. Gornje lijevo polje i
donje desno će uvijek biti prohodno.

Ispis: 8
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> dp[2];
  dp[0].resize(m, 0);
  dp[1].resize(m, 0);

  string s;
  cin >> s;

  for (int i = 0; i < m && s[i] == '.'; ++i) {
    dp[0][i] = 1;
  }

  for (int i = 1; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '.') {
        dp[i & 1][j] = dp[(i - 1) & 1][j] + (j ? dp[i & 1][j - 1] : 0);
        dp[i & 1][j] %= 1000000;
      } else {
        dp[i & 1][j] = 0;
      }
    }
  }

  cout << dp[(n - 1) & 1][m - 1] << endl;
  return 0;
}
