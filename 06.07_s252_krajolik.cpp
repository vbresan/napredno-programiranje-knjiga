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

#include <array>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct Step {
  int x, y;
};

constexpr array<Step, 8> STEPS = {
    {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}}};

struct Node {
  int x, y, distance;
};

int main() {

  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (int i = 0; i < n; ++i) {
    cin >> grid[i];
  }

  deque<Node> queue;
  queue.push_back({0, 0, 0});
  grid[0][0] = '#';

  while (!queue.empty()) {

    const auto [x, y, distance] = queue.back();
    queue.pop_back();

    if (x == n - 1 && y == m - 1) {
      cout << distance << endl;
      break;
    }

    for (const auto &step : STEPS) {

      const int nx = x + step.x;
      const int ny = y + step.y;
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') {
        continue;
      }

      if (grid[nx][ny] == 'x') {
        queue.push_front({nx, ny, distance + 1});
      } else {
        queue.push_back({nx, ny, distance});
      }
      grid[nx][ny] = '#';
    }
  }

  return 0;
}
