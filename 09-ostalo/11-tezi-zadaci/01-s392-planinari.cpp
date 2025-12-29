/*
Udruga planinara posjeduje teritorij kvadratnog oblika dimenzije n^2.
Teritorij se sastoji od kvadratića 1x1 od kojih je svaki zadane visine.
Planinari su vrlo ponosne osobe te se uvijek samo penju ili kreću po teritoriju
iste visine (u 4 smjera). Kako bi planinari mogli obilaziti cijeli teritorij
koji je u vlasništvu udruge, udruga je odlučila postaviti nekoliko tobogana po
teritoriju. Tobogan omogućuje planinarima da se s određene lokacije, na kojoj
postoji tobogan, spuste na neku nižu lokaciju na koju tobogan vodi. Pojedini
tobogan povezuje točno dvije lokacije. Ulazni podaci su n (1 <= n <= 1000),
zatim n redaka s po n znakova x ('a' <= x <= 'z'). Svaki kvadratić teritorija je
visine x - 'a' (od 0 do 25). Treba ispisati minimalan broj tobogana potreban da
bi planinari mogli sa svake lokacije doći do svake druge.

Ispis: 4
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void floodFill(vector<string> &territory, vector<vector<short>> &a, const int x,
               const int y, const int height, const int n, bool &hasTaller,
               bool &hasShorter) {

  territory[x][y] = '-';
  a[x][y] = height;

  for (int i = 0; i < 4; ++i) {

    const int sX[] = {0, 0, -1, 1};
    const int sY[] = {-1, 1, 0, 0};
    const int nX = x + sX[i];
    const int nY = y + sY[i];

    if (nX < 0 || nY < 0 || nX >= n || nY >= n) {
      continue;
    }

    int nHeight;
    if (territory[nX][nY] == '-') {
      nHeight = a[nX][nY];
    } else {
      nHeight = territory[nX][nY] - 'a';
    }

    if (nHeight > height) {
      hasTaller = true;
    } else if (nHeight < height) {
      hasShorter = true;
    } else if (nHeight == height && territory[nX][nY] != '-') {
      floodFill(territory, a, nX, nY, height, n, hasTaller, hasShorter);
    }
  }
}

int main() {

  int n;
  cin >> n;

  vector<string> territory;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    territory.push_back(s);
  }

  vector<vector<short>> a(n, vector<short>(n));
  bool hasTaller = false, hasShorter = false;
  int peaks = 0, bottoms = 0;
  int height;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (territory[i][j] != '-') {
        height = territory[i][j] - 'a';
        hasTaller = hasShorter = false;
        floodFill(territory, a, i, j, height, n, hasTaller, hasShorter);
        if (hasTaller && !hasShorter) {
          ++bottoms;
        }
        if (!hasTaller && hasShorter) {
          ++peaks;
        }
      }
    }
  }

  cout << max(peaks, bottoms) << endl;

  return 0;
}
