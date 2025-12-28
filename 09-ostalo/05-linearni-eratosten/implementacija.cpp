#include <iostream>
#include <vector>
using namespace std;
int main() {

  int n;
  cin >> n;

  vector<int> value(n + 2), previous(n + 2), next(n + 2);
  for (int i = 2; i <= n; ++i) {
    previous[i] = i - 1;
    next[i] = i + 1;
  }

  for (int i = 2; i * i < n; i = next[i]) {
    for (int j = previous[n / i + 1]; j >= i; j = previous[j]) {
      value[j * i] = i;
      next[previous[j * i]] = next[j * i];
      previous[next[j * i]] = previous[j * i];
    }
  }

  for (int i = 2; i <= n; ++i) {
    if (!value[i]) {
      cout << i << ' ';
    }
  }

  cout << endl;

  return 0;
}
