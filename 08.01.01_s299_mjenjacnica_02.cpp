/*
Banka je odlučila kako će sljedećih n dana mijenjati omjer dolara i eura u
svojim mjenjačnicama. Doznali ste tu povjerljivu informaciju i želite je
iskoristiti kako biste što više zaradili. Na raspolaganju imate 1000 eura.
Koliko najviše eura možete imati n-tog dana ako svaki dan po želji možete
mijenjati novce iz jedne valute u drugu? Ulazni podaci su n (1 <=n<= 100000),
zatim n pozitivnih decimalnih brojeva x. Pojedini dan 1 euro vrijedi x dolara.
Ako je x npr. 1.5 to znači da taj dan možete npr. 10 eura promjeniti u 15
dolara ili obrnuto.

Ispis:
1176.51
*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  double dollars = 0;
  double euros = 1000;

  for (int i = 0; i < n; ++i) {

    double rate, dollarsPrevious = dollars, eurosPrevious = euros;
    cin >> rate;
    dollars = max(dollarsPrevious, eurosPrevious * rate);
    euros = max(eurosPrevious, dollarsPrevious / rate);
  }

  cout << euros << endl;

  return 0;
}
