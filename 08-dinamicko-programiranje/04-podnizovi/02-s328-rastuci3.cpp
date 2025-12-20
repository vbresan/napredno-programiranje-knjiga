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

  vector<int> mins;
  mins.push_back(NINF);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {

    int number;
    cin >> number;

    vector<int>::iterator upper = upper_bound(mins.begin(), mins.end(), number);
    if (upper == mins.end()) {
      mins.push_back(number);
    } else {
      *upper = number;
    }
  }

  cout << mins.size() - 1 << endl;

  return 0;
}
