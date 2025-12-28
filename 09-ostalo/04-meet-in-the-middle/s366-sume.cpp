/*
Ulazni podaci su n (2 <= n <= 31) i m (1 <= m <= 10^9), zatim n brojeva x
(1 <= x <= 6 * 10^7). Ispisi koliko podskupova zadanih brojeva ima sumu manju
ili jednaku m.

Ispis: 444
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {

  int n, m;
  cin >> n >> m;

  vector<int> numbers(n);
  for (int &number : numbers) {
    cin >> number;
  }

  int a = n / 2;
  vector<int> A;
  for (int i = 0; i < (1 << a); ++i) {
    int sum = 0;
    for (int j = 0; j < a; ++j) {
      if ((i >> j) & 1) {
        sum += numbers[j];
      }
    }
    A.push_back(sum);
  }

  vector<int> B;
  for (int i = 0, b = n - a; i < (1 << b); ++i) {
    int sum = 0;
    for (int j = 0; j < b; ++j) {
      if ((i >> j) & 1) {
        sum += numbers[a + j];
      }
    }
    B.push_back(sum);
  }

  sort(B.begin(), B.end());
  int result = 0;
  for (int a : A) {
    result += upper_bound(B.begin(), B.end(), m - a) - B.begin();
  }

  cout << result << endl;

  return 0;
}
