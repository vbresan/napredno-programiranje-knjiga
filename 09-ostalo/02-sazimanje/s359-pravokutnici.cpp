/*
Iz papira smo izrezali n pravokutnika i stavljamo ih na stol paralelno s
rubovima stola. Ulazni podaci su n (1 <= n <= 100), zatim n puta po četiri
prirodna broja Ax, Ay, Bx i By, manja od 1000000. Brojevi Ax, Ay, Bx i By
predstavljaju gornju lijevu i donju desnu koordinatu koju će pravokutnik zauzeti
na stolu. Pravokutnike stavljamo jedan preko drugog na stol, počevši od prvog
unesenog. Ispišite redom za svaki pravokutnik koliki postotak njegove površine
je vidljiv nakon što sve pravokutnike stavimo na stol.

Ispis:
45%
66.6667%
100%
87.5%
100%

*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> Ax(n), Ay(n), Bx(n), By(n);
  vector<int> X, Y;

  for (int i = 0; i < n; ++i) {

    cin >> Ax[i] >> Ay[i] >> Bx[i] >> By[i];
    X.push_back(Ax[i]);
    Y.push_back(Ay[i]);
    X.push_back(Bx[i]);
    Y.push_back(By[i]);
  }

  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  sort(Y.begin(), Y.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());

  vector<vector<int>> table(Y.size() - 1, vector<int>(X.size() - 1));
  for (int k = 0; k < n; ++k) {
    int Xstart = lower_bound(X.begin(), X.end(), Ax[k]) - X.begin();
    int Xend = lower_bound(X.begin(), X.end(), Bx[k]) - X.begin();
    int Yend = lower_bound(Y.begin(), Y.end(), Ay[k]) - Y.begin();
    int Ystart = lower_bound(Y.begin(), Y.end(), By[k]) - Y.begin();
    for (int i = Ystart; i < Yend; ++i) {
      for (int j = Xstart; j < Xend; ++j) {
        table[i][j] = k + 1;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    int surface = (Bx[i] - Ax[i]) * (Ay[i] - By[i]);
    int visible = 0;
    for (int j = 0; j < table.size(); ++j) {
      for (int k = 0; k < table[j].size(); ++k) {
        if (table[j][k] == i + 1) {
          visible += (Y[j + 1] - Y[j]) * (X[k + 1] - X[k]);
        }
      }
    }

    cout << (100. * visible) / surface << '%' << endl;
  }

  return 0;
}
