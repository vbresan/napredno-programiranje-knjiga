/*

Unosi se dva broja: n (1 <= n <= 1000) i m (1 <= m <= 1000), a zatim n
linija dužine m znakova. Svaki znak je '.' ili 'x' ili '#'. Ti znakovi
opisuju tlocrt krajolika. '.' predstavlja prohodnu travu i pri prelasku
preko tog polja ne trošimo vrijeme. 'x' predstavlja šumu kroz koju nam
treba jedan sat, dok je '#' stijena kroz koju ne možemo proći. Koliko sati
nam treba da bismo došli od gornjeg lijevog polja do donjeg desnog
najbržim putem? S pojedinog polja možemo prijeći na bilo koje od
susjednih 8 polja (ako je prohodno). Donje desno i gornje lijevo polje
bit će trava i moći će se doći od jednog do drugog.

output: 4

*/

#include <iostream>
#include <list>
#include <utility>
#include <vector>
using namespace std;

const struct Step {
  int x, y;
} steps[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
             {1, 1},   {1, 0},  {1, -1}, {0, -1}};

int main() {

  int n, m;
  cin >> n >> m;

  vector<string> map(n);
  for (int i = 0; i < n; ++i) {
    cin >> map[i];
  }

  list<pair<pair<int, int>, int>> nodes; // ((x, y), distance)
  nodes.emplace_back(make_pair(0, 0), 0);

  while (!nodes.empty()) {

    const auto [coordinates, distance] = nodes.back();
    const auto [x, y] = coordinates;
    nodes.pop_back();

    if (x == n - 1 && y == m - 1) {
      cout << distance << endl;
      break;
    }

    map[x][y] = '#'; // mark as visited
    for (int i = 0; i < 8; ++i) {

      const int neighbor_x = x + steps[i].x;
      const int neighbor_y = y + steps[i].y;
      if (map[neighbor_x][neighbor_y] == '#' ||
          (neighbor_x < 0 || neighbor_x >= n) ||
          (neighbor_y < 0 || neighbor_y >= m)) {
        continue;
      }

      if (map[neighbor_x][neighbor_y] == 'x') {
        nodes.emplace_front(make_pair(neighbor_x, neighbor_y), distance + 1);
      } else {
        nodes.emplace_back(make_pair(neighbor_x, neighbor_y), distance);
      }
    }
  }

  return 0;
}
