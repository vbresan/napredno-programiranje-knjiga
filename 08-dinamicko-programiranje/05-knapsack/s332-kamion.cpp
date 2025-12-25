/*
U kamion se tovari pijesak. U kamion stane x kubika pijeska. Ukupno
raspolažemo s n vrsta pijeska. Ulazni podaci su n (1 <=n <= 100000) i x,
zatim n parova brojeva a i b koji opisuju pojedinu vrstu pijeska. a je
količina pijeska u kubicima kojom raspolažemo, dok je b ukupna vrijednost
tih a kubika pijeska. Kamion valja natovariti tako da je ukupna vrijednost
pijeska u njemu što veća. Od svake vrste pijeska možemo uzeti onoliko kubika
koliko želimo (ne moramo uzeti svih a).

Ispis: 175
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {

  int n, x;
  cin >> n >> x;

  vector<pair<double, int>> sandTypes;
  for (int i = 0; i < n; ++i) {

    int a, b;
    cin >> a >> b;

    sandTypes.emplace_back((double)b / a, a);
  }

  sort(sandTypes.rbegin(), sandTypes.rend());

  double totalValue = 0;
  int remainingCapacity = x;
  for (const auto &[valuePerCubic, availableAmount] : sandTypes) {
      
    if (remainingCapacity == 0) {
      break;
    } 
      
    int currentAmount = min(remainingCapacity, availableAmount);
    totalValue += currentAmount * valuePerCubic;
    remainingCapacity -= currentAmount;
  }

  cout << totalValue << endl;

  return 0;
}
