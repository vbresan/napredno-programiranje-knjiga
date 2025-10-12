/*

Tvornica pravokutnog oblika sastoji se od n (1 <= n <= 1000) redova i m
(1 <= m <= 1000) stupaca. Ukupno n * m dijelova. Svaki dio tvornice ima
zidove s nekih strana. Unosi se n i m i zatim n redova od po m brojeva.
Svaki broj od 0 do 15 opisuje jedan dio tvornice. Binarni zapis broja
opisuje s kojih strana tog dijela tvornice se nalaze zidovi. Ako je dan
npr. broj 10, onda je njegov binarni zapis 1010, što znači da ima zid sa
sjevera, nema s istoka, ima s juga i nema sa zapada. Opis će biti takav
da tvornica ima zidove s vanjske strane. Ispiši za svaku prostoriju njenu
veličinu. Ispiši prostorije od veće prema manjoj.

Ako je tvornica opisana sa:
9 14 11 12 13
5 15 11  6  7
5  9 14  9 14
3  2 14  3 14

onda je u pitanju izgled:

┌─────────┬─────────┬────┐
│1001 1110│1011 1100│1101│
│    ┌────┼────     │    │
│0101│1111│1011 0110│0111│
│    ├────┴────┬────┴────┤
│0101│1001 1110│1001 1110│
│          ────┤     ────┤
│0011 0010 1110│0011 1110│
└──────────────┴─────────┘


out: 9 4 4 2 1

*/

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> factory;
vector<vector<int>> visited;

struct Move {
  int x, y, wall;
};
const struct Move moves[] = {
    {-1, 0, 0b1000}, {1, 0, 0b0010}, {0, -1, 0b0001}, {0, 1, 0b0100}};

int floodFill(int x, int y) {

  if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) {
    return 0;
  }

  visited[x][y] = 1;
  int roomSize = 1;

  for (int i = 0; i < 4; i++) {
    if (!(factory[x][y] & moves[i].wall)) {
      roomSize += floodFill(x + moves[i].x, y + moves[i].y);
    }
  }

  return roomSize;
}

int main() {

  cin >> n >> m;
  factory.resize(n, vector<int>(m));
  visited.resize(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      factory[i][j] = *istream_iterator<int>(cin);
    }
  }

  vector<int> solutions;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j]) {
        solutions.push_back(floodFill(i, j));
      }
    }
  }

  sort(solutions.begin(), solutions.end(), greater<int>());
  for (int roomSize : solutions) {
    cout << roomSize << ' ';
  }
  cout << endl;

  return 0;
}
