/*
Na koliko načina možete isplatiti x (1 <=x <= 10000) kuna, koristeći n
(1 <= n <= 100) vrsta novčanica? Ulazni podaci su n i x, zatim n cijelih
brojeva a (1 <= a <= x) koje opisuju s kojim vrstama novčanica raspolažemo
(novčanice će biti međusobno različite). Kao rješenje ispisite ostatak pri
dijeljenju nacina isplate s 1000000.

Ispis: 17
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, x;
  cin >> n >> x;

  vector<int> dp(x + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < n; ++i) {

    int bill;
    cin >> bill;

    for (int j = bill; j <= x; ++j) {
      dp[j] = (dp[j] + dp[j - bill]) % 1000000;
    }
  }

  cout << dp[x] << endl;
  return 0;
}
