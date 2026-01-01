/*
Mirela se natječe u slaganju puzzli. Napredovanje tijekom natjecanja ocjenjuje
komisija koja povremeno dođe do Mirele i projeri je li uspjela povezati neka
dva dijela puzzle (direktno | ili preko nekih trećih dijelova puzzle). Puzzla
koju treba složiti ima n (2 <= n <= 1000000) dijelova. Tijekom natjecanja događa
se m (1 <= m <= 1000000) događaja. Ulazni podaci su n i m, zatim m parova
brojeva x i y (0 <= x,y <= n). Ako je x<y, znači da je Mirela spojila dio puzle
x s dijelom y. Ako je x>y, došla je komisija i treba ispisati '1' ako je Mirela
povezala dio puzle x s dijelom y, a inače '0'. Napomena: Mirela može spojiti
dijelove puzzle koji su već prije spojeni preko nekih drugih dijelova puzzle.

Ispis: 1010111

*/

#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &P, int x) {
  return x == P[x] ? x : (P[x] = find(P, P[x]));
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> P(n), D(n);
  for (int i = 0; i < n; ++i) {
    P[i] = i;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    int Pa = find(P, a), Pb = find(P, b);
    if (a > b) {
      cout << (Pa == Pb);
    } else {
      if (Pa == Pb) {
        continue;
      }
      if (D[Pa] > D[Pb]) {
        P[Pb] = Pa;
      } else if (D[Pa] < D[Pb]) {
        P[Pa] = Pb;
      } else { // D[Pa] == D[Pb]
        P[Pb] = Pa;
        ++D[Pa];
      }
    }
  }

  cout << endl;

  return 0;
}
