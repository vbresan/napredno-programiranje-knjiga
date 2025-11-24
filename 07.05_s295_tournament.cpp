#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
  
  int n;
  cin >> n;

  int pow2 = 1 << (int) (ceil(log2(n)));
  int size = pow2 + n + 1; // one extra element to keep update algo. simple
  vector<int> tournament(size, -1);

  for (int i = 0; i < n; ++i) {
    cin >> tournament[pow2 + i];
  }
  for (int i = pow2 + n - 1; i > 1; --i)  {
    if (tournament[i/2] < tournament[i]) {
      tournament[i/2] = tournament[i];
    }
  }
  
  

  cout << pow2 << endl;

  return 0;    
}