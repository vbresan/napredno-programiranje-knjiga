/*
Miš se nalazi u eksperimentalnom labirintu oblika stabla s n čvorova. U svakom
čvoru nalazi se sir, a miš želi pojesti sve sireve i ujedno prijeći što manji
put. Miš se na početku nalazi u čvoru x, a kad pojede sve sireve ne mora se
vratiti u početni čvor. Ulazni podaci su n (1 <= n <= 1000000) i x, a zatim
n-1 puta po tri broja a, b i c (1 <= c <= 10000) koji označuju da su
1-indeksirani čvorovi a i b povezani dvosmjernim bridom dužine c. Graf će biti
povezan. Kolika je minimalna udaljenost koju miš mora prijeći da bi pojeo sve
sireve?

Output: 256

*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

long long dfs(const vector<vector<pair<int, int>>>& tree, int parent, int node) {

  long long maxDistance = 0;

  for (const auto& [neighbor, weight] : tree[node]) {
    if (neighbor != parent) {
      maxDistance = max(maxDistance, dfs(tree, node, neighbor) + weight);
    }
  }

  return maxDistance;
}

int main() {

  int n, x;
  cin >> n >> x;

  vector<vector<pair<int, int>>> tree(n);

  long long edgeSum = 0;
  for (int i = 0; i < n - 1; ++i) {

    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;

    tree[a].emplace_back(b, c);
    tree[b].emplace_back(a, c);

    edgeSum += c;
  }

  cout << 2 * edgeSum - dfs(tree, -1, x - 1) << endl;

  return 0;
}
