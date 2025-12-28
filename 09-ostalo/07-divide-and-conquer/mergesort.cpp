#include <vector>
using namespace std;

void mergesort(vector<int> v, int a, int b) {

  if (b - 1 == 1) {
    return;
  }

  int s = (a + b) / 2;
  mergesort(v, a, s);
  mergesort(v, s, b);

  vector<int> q;
  int x = a, y = s;
  for (int i = 0; i < b - a; ++i) {
    if (x == s) {
      q.push_back(v[y++]);
    } else if (y == b) {
      q.push_back(v[x++]);
    } else {
      if (v[x] < v[y]) {
        q.push_back(v[x++]);
      } else {
        q.push_back(v[y++]);
      }
    }
  }

  for (int i = 0; i < b - a; ++i) {
    v[a + i] = q[i];
  }
}
