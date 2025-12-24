/*
Izlog trgovine sastoji se od jedne police dužine x. Na tu policu valja staviti
predmete tako da je izlog što primamljiviji kupcima. Ulazni podaci su broj
različitih predmeta koje trgovina ima: n (1 <= n <= 100), i dužina police u
izlogu: x (1 <= x <= 10000). Zatim slijedi n parova brojeva a i b koji opisuju
pojedini predmet iz trgovine. Pojedini predmet je dužine a (1 <= a <= x) i
primamljivost mu je b (0 <= b <= 1000000). Ispišite najveću ukupnu
primamljivost koju izlog može imati. (Napomene: Stvari ne smiju viriti van
police i moraju se staviti na policu u cjelosti. Od svake stvari, koju
trgovina posjeduje, samo jedan primjerak smije biti u izlogu.)

Ispis: 202
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n, x;
  cin >> n >> x;

  vector<int> dp(x + 1);
  for (int i = 0; i < n; ++i) {

    int a, b;
    cin >> a >> b;

    for (int j = x - a; j >= 0; --j) {
      dp[j + a] = max(dp[j + a], dp[j] + b);
    }
  }

  cout << dp[x] << endl;

  return 0;
}
