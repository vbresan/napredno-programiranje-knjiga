/*
U pekari se prodaje burek. Na početku dana ispečeno je n bureka, svaki
kvalitete x. Kako vrijeme prolazi peku se novi bureci različite kvalitete,
dolaze kupci i kupuju burek. Kada kupac dođe, kaže prodavačici: "Daj mi
najbolji burek koji imaš". Prodavačica odabere najbolji burek koji ima i
proda mu ga. Pomozi pekari što bolje poslovati tako što će prodavačica uvijek
dati kupcima najbolji burek. Zadan je n (1 <= n <= 100000) i nakon toga n
brojeva x. Broj x opisuje kvalitetu bureka. Nakon toga slijedi broj m, zatim
m (1 <=m <= 100000) brojeva y. y opisuje događaje tijekom dana. Ako je y nula,
znači da je došao kupac i kupio nabolji burek pa treba ispisati kvalitetu
prodanog bureka ili "Nema!" ako nema bureka. Ako y nije nula, znači da je
ispečen novi burek kvalitete y koji se od tog trenutka može kupiti.

Odgovarajuci ispis:
39 29 50 97 24 18 15 4 Nema!
*/

#include <iostream>
#include <vector>
using namespace std;

void push(int x, vector<int> &heap) {

  heap.push_back(x);

  int index = heap.size() - 1;
  while (index / 2 && heap[index] > heap[index / 2]) {

    heap[index] = heap[index / 2];
    heap[index / 2] = x;
    index /= 2;
  }
}

void pop(vector<int> &heap) {

  heap[1] = heap.back();
  heap.pop_back();

  int from = 1, to;
  while (true) {
    if (from * 2 + 1 < heap.size()) {
      if (heap[from * 2] > heap[from * 2 + 1]) {
        to = from * 2;
      } else {
        to = from * 2 + 1;
      }
    } else if (from * 2 < heap.size()) {
      to = from * 2;
    } else {
      break;
    }

    if (heap[to] > heap[from]) {

      int temp = heap[to];
      heap[to] = heap[from];
      heap[from] = temp;
      from = to;
    } else {
      break;
    }
  }
}

int main() {

  vector<int> heap;
  heap.push_back(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {

    int x;
    cin >> x;
    push(x, heap);
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {

    int y;
    cin >> y;
    if (y) {
      push(y, heap);
    } else {
      if (heap.size() > 1) {
        cout << heap[1] << ' ';
        pop(heap);
      } else {
        cout << "Nema!";
      }
    }
  }

  cout << endl;
  return 0;
}
