/*
Ispišite u rastućem poretku sve iznose od 1 do x (uključno) koji se mogu
isplatiti pomocu unesenih novčanica. Imate točno jednu od svake novčanice.
Ulazni podaci su broj novcanica n (1 <= n <= 100) i x (1 <= x <= 10000).
Zatim slijedi n cijelih brojeva a (1 <= a <= x) koji opisuju iznos pojedine
novcanice.

Ispis:
2 4 5 6 7 9 11 35 36 37 38 39 40 41 42 43 44 45 46 47 71 73 75 76 77 78 80 82
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, x;
  cin >> n >> x;

  vector<bool> dp(x + 1);
  dp[0] = true;

  for (int i = 0; i < n; ++i) {

    int bill;
    cin >> bill;

    for (int j = x - bill; j >= 0; --j) {
      if (dp[j]) {
        dp[j + bill] = true;
      }
    }
  }

  for (int i = 1; i <= x; ++i) {
    if (dp[i]) {
      cout << i << ' ';
    }
  }

  cout << endl;

  return 0;
}
