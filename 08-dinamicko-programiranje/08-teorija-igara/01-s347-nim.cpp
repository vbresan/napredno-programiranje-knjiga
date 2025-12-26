/*
Na hrpi se nalazi n (0 <= n <= 10^9) šibica. Dva igrača naizmjenično uzimaju
jednu, dvije ili tri šibice s hrpe. Igru počinje igrač A, a zatim se
izmjenjuju B, pa A, pa B, itd. Onaj tko ne moze uzeti niti jednu šibicu je
izgubio. Ulazni podatak je n. Treba ispisati tko će pobijediti (A ili B) ako
oba igrača igraju optimalno.

Ispis: B
*/

#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  cout << (char)(!(n % 4) + 'A') << endl;
  return 0;
}
