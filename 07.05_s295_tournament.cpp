#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void add(vector<int> &tournament, int index, int value) {

  tournament[index] = value;
  for (index /= 2; index; index /= 2) {
    tournament[index] = max(tournament[index * 2], tournament[index * 2 + 1]);
  }
}

int maxIndex(vector<int> &tournament) {

  int index = 1;
  while (index * 2 + 1 < tournament.size()) {
    if (tournament[index * 2] > tournament[index * 2 + 1]) {
      index = index * 2;
    } else {
      index = index * 2 + 1;
    }
  }
  return index;
}

int query(vector<int> &tournament, int node, int from, int to, int a, int b) {
  if (from >= a && to <= b) {
    return tournament[node];
  }

  int max1 = -1, max2 = -1;
  if ((from + to) / 2 >= a) {
    max1 = query(tournament, node * 2, from, (from + to) / 2, a, b);
  }
  if ((from + to) / 2 + 1 <= b) {
    max2 = query(tournament, node * 2 + 1, (from + to) / 2 + 1, to, a, b);
  }
  return max(max1, max2);
}

int main() {

  int n;
  cin >> n;

  int pow2 = 1 << (int)(ceil(log2(n)));
  int size = pow2 + n + 1; // one extra element to keep update algo. simple
  vector<int> tournament(size, -1);

  for (int i = 0; i < n; ++i) {
    cin >> tournament[pow2 + i];
  }
  for (int i = pow2 + n - 1; i > 1; --i) {
    if (tournament[i / 2] < tournament[i]) {
      tournament[i / 2] = tournament[i];
    }
  }

  add(tournament, pow2, 7);
  cout << maxIndex(tournament) << endl;
  cout << query(tournament, 1, 0, pow2 - 1, 4, 10) << endl;

  return 0;
}
