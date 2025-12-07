/*
Stubište se sastoji od n stuba. Na koliko se načina možemo popeti od dna do
vrha stubišta ako svaki put možemo birati želimo li zakoračiti po jednu ili
dvije stube. Na pocetku se nalazimo ispred prve stube. Ulazni podatak je n
(2 <= n <= 1000000). Treba ispisati ostatak pri dijeljenju broja načina
penjanja uz stube s 1000000 (zato što broj nacina penjanja može biti vrlo
velik).

Unos: 15
Ispis: 987

*/

#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int dp0, dp1 = 1, dp2 = 2;
  for (int i = 3; i <= n; ++i) {
    dp0 = dp1;
    dp1 = dp2;
    dp2 = (dp1 + dp0) % 1000000;
  }

  cout << dp2 << endl;
  return 0;
}
