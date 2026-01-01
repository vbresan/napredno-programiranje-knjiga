/*
Na olimpijadi starih sportova održava se natjecanje u nošenju lanca s utezima.
Tim natjecatelja treba što prije prenijeti lanac s utezima od starta do cilja.
Budući da se radi o lancu, svaki član tima uzme nekoliko utega koji su uzastopno
postavljeni na lancu. Svaki uteg je kod nekog člana tima i cilj je što prije,
krećući se zajedno, prenijeti utege do cilja. Svi članovi tima su jednako jaki i
brzina nošenja utega ovisi o najopterećenijem članu tima, jer se on najsporije
kreće. Zadan je broj utega na lancu n (1 <= n <= 100000) i broj članova tima m
(1 <= m <= 10000), zatim n brojeva x (1 <= x <= 1000) koji predstavljaju težinu
pojedinog utega. Utezi su poredani po lancu onim redom kojim su navedeni u
unosu. Ispišite najveću težinu koju netko mora nositi ako se utezi rasporede
optimalno (najveća težina koju netko nosi treba biti što manja, kako bi tim bio
što brži).

Ispis: 20
*/

#include <iostream>
#include <vector>
using namespace std;

int test(int allowed, const vector<int> &weights) {

  int people = 1, load = 0;
  for (int weight : weights) {
    if (load + weight <= allowed) {
      load += weight;
    } else {
      ++people;
      load = weight;
      if (load > allowed) {
        return 10001;
      }
    }
  }

  return people;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> weights(n);
  for (int &weight : weights) {
    cin >> weight;
  }

  int low = 0, high = 1000 * 100000;
  while (high != low) {
    int mid = (high + low) / 2;
    if (test(mid, weights) <= m) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  cout << low << endl;

  return 0;
}
