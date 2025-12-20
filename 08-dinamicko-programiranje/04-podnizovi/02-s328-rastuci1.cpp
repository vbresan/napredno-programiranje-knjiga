/*
Dan je niz brojeva. Treba pronaci najduzi (ne obavezno uzastopan) neopadajuci
podniz. Ulazni podaci su n (1 <= n <= 100000) i zatim n brojeva x
(-1000000 <= x <= 1000000).

Ispis: 6
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> numbers(n);
  for (int &number : numbers) {
    cin >> number;
  }

  vector<int> dp(n, 1);
  for (int k = 1; k < n; ++k) {
    for (int i = 0; i < k; ++i) {
      if (numbers[i] <= numbers[k]) {
        dp[k] = max(dp[k], dp[i] + 1);
      }
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << endl;

  return 0;
}
