/*
Unosi se n (1 <= n <= 1000). U sljedećih n redova nalaze se pozitivni cijeli
brojevi tako da se u x-tom retku nalazi x brojeva. Cilj je u toj "piramidi"
brojeva pronaći put od vrha do dna, kojemu je suma brojeva najveća i ispisati
taj put. Počinjemo u prvom retku (vrh piramide) i možemo se kretati samo
prema dolje ili dolje-desno.

Ispis 1:
25 10 15 30 27

Ispis 2:
1 3 6 10
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

  vector<vector<int>> input(n), dp(n);
  for (int i = 0; i < n; ++i) {
    
    // 0-padding to avoid vector indexing problems and keep the algo. simple.
    dp[i].resize(i + 3, 0); 
    
    for (int j = 0; j <= i; ++j) {
      int x;
      cin >> x;
      input[i].push_back(x);
    }
  }

  // calculate optimum values
  dp[0][1] = input[0][0];
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= i + 1; ++j) {
      dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + input[i][j - 1];
    }
  }

  // backtrack the optimum path
  vector<int> path;
  int column = getIndexMax(dp[n - 1].begin(), dp[n - 1].end() - 1);
  for (int row = n - 1; row > 0; --row) {
    path.push_back(input[row][column - 1]);
    if (dp[row - 1][column - 1] > dp[row - 1][column]) {
      column -= 1;
    }
  }
  path.push_back(input[0][0]);

  // print the path
  reverse(path.begin(), path.end());
  for (int element : path) {
    cout << element << ' ';
  }
  cout << endl;

  return 0;
}
