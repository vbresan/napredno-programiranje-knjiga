/*
Na roštilju se nalazi n 1-indeksiranih ćevapa. Svaki ćevap ima dvije strane 
A i B. Na početku su svi ćevapi okrenuti na stranu A. Unos se sastoji od 
brojeva n (1 <= n <= 100000) i m (1 <= m <= 100000), zatim m parova brojeva 
x i y. Par brojeva x i y opisuje jedan od dva moguća događaja. Ako je x==0 
onda treba ispisati na koju stranu je okrenut ćevap y (A ili B). Ako x
nije nula, onda na roštilju okrećemo sve ćevape od x do y, uključno.

Ispis:
B
B
A

*/

#include <iostream>
#include <vector>
using namespace std;

void add(vector<int> &fwt, int index, int value) {

  for (int max = fwt.size(); index < max; index += index & -index) {
    fwt[index] += value;
  }
}

int peek(vector<int> &fwt, int index) {

  int value = 0;
  for (; index > 0; index -= index & -index) {
    value += fwt[index];
  }
  return value;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> fwt(n);

  for (int i = 0; i < m; ++i) {

    int x, y;
    cin >> x >> y;
    if (x) {
      add(fwt, x, 1);
      add(fwt, y + 1, -1);
    } else {
      cout << (char)((peek(fwt, y) & 1) + 'A') << endl;
    }
  }
  return 0;
}
