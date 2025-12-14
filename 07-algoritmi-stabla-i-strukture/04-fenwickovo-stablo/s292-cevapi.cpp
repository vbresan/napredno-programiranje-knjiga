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

void add(vector<int> &fenwick, int index, int value) {

  for (int max = fenwick.size(); index < max; index += index & -index) {
    fenwick[index] += value;
  }
}

int peek(vector<int> &fenwick, int index) {

  int value = 0;
  for (; index > 0; index -= index & -index) {
    value += fenwick[index];
  }
  return value;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> fenwick(n + 2); 
  // Fenwick tree is 1-indexed. Also, we modify y + 1, and y can be n.

  for (int i = 0; i < m; ++i) {

    int x, y;
    cin >> x >> y;
    if (x) {
      add(fenwick, x, 1);
      add(fenwick, y + 1, -1);
    } else {
      cout << (char)((peek(fenwick, y) & 1) + 'A') << endl;
    }
  }
  return 0;
}
