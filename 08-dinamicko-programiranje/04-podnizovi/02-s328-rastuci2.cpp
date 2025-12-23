/*
Dan je niz brojeva. Treba pronaci najduzi (ne obavezno uzastopan) neopadajuci
podniz. Ulazni podaci su n (1 <= n <= 100000) i zatim n brojeva x
(-1000000 <= x <= 1000000).

Ispis: 6
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

constexpr int NINF = numeric_limits<int>::min();

int main() {

  // the smallest ending value for each subsequence length
  vector<int> mins;
  mins.push_back(NINF);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {

    int number;
    cin >> number;

    if (mins.back() <= number) {
      mins.push_back(number);
    }

    for (int j = mins.size() - 2; j >= 0; --j) {
      if (mins[j] <= number) {
        mins[j + 1] = min(mins[j + 1], number);
      }
    }
  }

  cout << mins.size() - 1 << endl;

  return 0;
}
