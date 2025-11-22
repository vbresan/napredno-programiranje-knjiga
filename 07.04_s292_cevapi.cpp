#include <iostream>
#include <vector>
using namespace std;

void add(vector<int> &fwt, int index, int value) {

  for (int max = fwt.size(); index < max; index += index & -index) {
    fwt[index] += value;
  }
}

int peek(vector<int> &fwt, int index) {

  int value = 0;
  for (; index > 0; index -= index & -index) {
    value += fwt[index];
  }
  return value;
}

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> fwt(n);

  for (int i = 0; i < m; ++i) {

    int x, y;
    cin >> x >> y;
    if (x) {
      add(fwt, x, 1);
      add(fwt, y + 1, -1);
    } else {
      cout << (char)((peek(fwt, y) & 1) + 'A') << endl;
    }
  }
  return 0;
}
