/*
Na slici grada nalazi se n nebodera pravokutnog oblika (mogu se preklapati).
Svaki neboder je definiran početnom i krajnjom x koordinatom i visinom. Koliku
površinu prekrivaju? Ulazni podaci su n (1 <= n <= 100000), zatim n puta po tri
broja a, b (O <= a < b <=10^9) i c (1 <= c <= 10^9) koji opisuju pojedini
pravokutnik. a je početna x koordinata pravokutnika, b je krajnja x koordinata
pravokutnika, dok je c visina. Ispišite koliku površinu slike prekrivaju
neboderi (pravokutnici).

Ispis: 59
*/

#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<pair<int, int>> events;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    events.emplace_back(a, c);
    events.emplace_back(b, -c);
  }
  sort(events.begin(), events.end());

  long long result = 0;
  multiset<int> sweep;
  sweep.insert(0);
  sweep.insert(events[0].second);
  int previousX = events[0].first;
  for (int i = 1; i < events.size(); ++i) {
    int x = events[i].first;
    result += ((long long)x - previousX) * *(--sweep.end());
    previousX = x;

    int height = events[i].second;
    if (height < 0) {
      sweep.erase(sweep.find(-height));
    } else {
      sweep.insert(height);
    }
  }

  cout << result << endl;

  return 0;
}
