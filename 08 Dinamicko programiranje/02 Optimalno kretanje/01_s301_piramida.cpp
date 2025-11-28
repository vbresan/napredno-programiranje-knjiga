/*
Unosi se n (1 <=n <= 1000). U sljedećih n redova nalaze se pozitivni cijeli
brojevi tako da se u x-tom retku nalazi x brojeva. Cilj je u toj "piramidi"
brojeva pronaći put od vrha do dna, kojemu je suma brojeva najveća i ispisati
taj put. Počinjemo u prvom retku (vrh piramide) i možemo se kretati samo
prema dolje ili dolje-desno.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

typedef vector<int>::iterator Iterator;

int getIndexMax(Iterator first, Iterator last) {

  Iterator iterMax = max_element(first, last);
  return distance(first, iterMax);
}

int main() {

  int n;
  cin >> n;

  vector<vector<int>> input(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      int x;
      cin >> x;
      input[i].push_back(x);
    }
  }

  vector<vector<int>> dp = input;
  for (int i = 0; i < n; ++i) {
    /* add leading and trailing zeros to avoid vector indexing problems
       and keep the algorithm simple. */
    dp[i].insert(dp[i].begin(), 0);
    dp[i].push_back(0);
  }

  // calculate optimum values
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= i + 1; ++j) {
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + dp[i][j];
    }
  }

  // backtrack the optimum path
  vector<int> path;
  for (int i = n - 1, indexMax = dp[i].size() - 1; i >= 0; --i) {
    Iterator last = dp[i].begin() + min(indexMax, (int)(dp[i].size() - 1)) + 1;
    indexMax = getIndexMax(dp[i].begin(), last);
    path.insert(path.begin(), input[i][indexMax - 1]);
  }

  // print the path
  for (int element : path) {
    cout << element << ' ';
  }
  cout << endl;

  return 0;
}
