/*
Miš se nalazi u eksperimentalnom labirintu oblika stabla s n čvorova. U svakom
čvoru nalazi se sir, a miš želi pojesti sve sireve i ujedno prijeći što manji
put. Miš se na početku nalazi u čvoru x, a kad pojede sve sireve ne mora se
vratiti u početni čvor. Ulazni podaci su n (1 <= n <= 1000000) i x, a zatim
n-1 puta po tri broja a, b i c (1 <= c <= 10000) koji označuju da su
1-indeksirani čvorovi a i b povezani dvosmjernim bridom dužine c. Graf će biti
povezan. Kolika je minimalna udaljenost koju miš mora prijeći da bi pojeo sve
sireve?

Ulazni podaci nemaju broj x. Mis moze krenuti iz bilo kojeg cvora i zavrsiti
u bilo kojem cvoru. Kolika je minimalna udaljenost koju mis mora prijeci da
bi pojeo sve sireve.

Output: 225

*/

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef vector<vector<pair<int, int>>> Tree;
long long diameter = 0;

long long dfs(const Tree &tree, int parent, int node) {

  long long max1 = 0, max2 = 0;

  for (const auto &[neighbor, weight] : tree[node]) {
    if (neighbor != parent) {
      long long pathLength = dfs(tree, node, neighbor) + weight;

      if (pathLength >= max1) {
        max2 = max1;
        max1 = pathLength;
      } else if (pathLength > max2) {
        max2 = pathLength;
      }
    }
  }

  diameter = max(diameter, max1 + max2);

  return max1;
}

int main() {

  int n;
  cin >> n;
  Tree tree(n);

  long long edgesSum = 0;
  for (int i = 0; i < n - 1; ++i) {

    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;

    tree[a].emplace_back(b, c);
    tree[b].emplace_back(a, c);
    edgesSum += c;
  }

  dfs(tree, -1, 0);

  cout << 2 * edgesSum - diameter << endl;

  return 0;
}
