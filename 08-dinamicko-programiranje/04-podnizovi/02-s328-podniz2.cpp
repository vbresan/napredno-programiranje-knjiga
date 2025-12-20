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

constexpr int NINF = numeric_limits<int>::min();

int main() {

  vector<int> minimums;
  minimums.push_back(NINF);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {

    int number;
    cin >> number;

    if (minimums.back() <= number) {
      minimums.push_back(number);
    }

    for (int j = minimums.size() - 2; j >= 0; --j) {
      if (minimums[j] <= number) {
        minimums[j + 1] = min(minimums[j + 1], number);
      }
    }
  }

  cout << minimums.size() - 1 << endl;

  return 0;
}
