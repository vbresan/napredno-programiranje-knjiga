/*
Ekipa kupuje ulaznice za popularni koncert. Radnja se odvija tako da pojedinac
stane u red i ceka da svi ispred njega kupe ulaznice, tada i on kupi ulaznicu i
napusti red. Koncert je medijski popraćen i ponekad se neki kamerman izdere:
"Ej, ti visoki, sagni se!". Zato je potrebn uvijek znati koliko je visoka
najviša osoba u redu za kupnju ulaznica. Ulazni podaci sastoje se od broja n (1
<= n <= 1000000), zatim n cijelih brojeva x koji opisuju pojedine događaje. Ako
je x=0, prodana je još jedna karta, ako je x=-1 treba ispisati veličinu najviše
osobe koja čeka u redu, a ako je x>0, na kraj reda je stala osoba visine x.

Ispis:
5 7 7 9 9 9 4
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main() {

  int n;
  cin >> n;

  queue<int> buyers;
  list<int> tallest;

  for (int i = 0; i < n; ++i) {

    int x;
    cin >> x;

    if (x == -1) {
      cout << tallest.front() << ' ';
    } else if (x == 0) {
      if (tallest.front() == buyers.front()) {
        tallest.pop_front();
      }
      buyers.pop();
    } else {
      buyers.push(x);
      while (!tallest.empty() && tallest.back() < x) {
        tallest.pop_back();
      }
      tallest.push_back(x);
    }
  }

  cout << endl;

  return 0;
}
