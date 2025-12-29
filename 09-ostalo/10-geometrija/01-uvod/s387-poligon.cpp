/*
Ulazni podaci su n (3 <= n <= 100000), Qx i Qy, zatim n puta po dva broja  x i
y. x i y predstavljaju koordinate točaka konveksnog poligona. Točke poligona
navedene su redom tako da svake dvije uzastopne točke iz ulaza čine stranicu
poligona. Prva i zadnja točka također čine stranicu. Ispišite je li točka
(Qx,Qy) unutar poligona.

Ispis:
Q je unutar poligona
*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

inline int ccw(double Ax, double Ay, double Bx, double By, double Cx,
               double Cy) {
  double value =
      (Ax * By - Ay * Bx) + (Bx * Cy - By * Cx) + (Cx * Ay - Cy * Ax);
  double eps = max(max(abs(Ax), abs(Ay)),
                   max(max(abs(Bx), abs(By)), max(abs(Cx), abs(Cy)))) /
               1e9;
  if (value <= -eps) {
    return -1;
  }
  if (value >= eps) {
    return 1;
  }

  return 0;
}

int main() {

  int n, Qx, Qy;
  cin >> n >> Qx >> Qy;

  vector<double> Px(n), Py(n);
  for (int i = 0; i < n; ++i) {
    cin >> Px[i] >> Py[i];
  }

  int orientation = ccw(Px[n - 1], Py[n - 1], Px[0], Py[0], Qx, Qy);

  int i = 0;
  for (; i < n - 1; ++i) {
    if (ccw(Px[i], Py[i], Px[i + 1], Py[i + 1], Qx, Qy) != orientation) {
      break;
    }
  }

  if (i == n - 1) {
    cout << "Q je unutar poligona" << endl;
  } else {
    cout << "Q je van poligona ili na stranici" << endl;
  }

  return 0;
}
