/*
Studentska kantina poslužuje pet vrsta jela studentima. Kuharica grabi
studentima porcije hrane iz velikih posuda. Postoji pet posuda, svaka s
odgovarajućom vrstom jela. Problem je što se ne mogu sva jela uvijek
poslužiti, jer na pult stanu samo dvije posude. Kad student dođe do kuharice
i kaže koje od pet jela želi jesti, ako jelo nije na pultu, kuharica mora
maknuti jedno od jela s pulta, zatim ga odnijeti u kuhinju i vratiti se s
posudom koja sadrži jelo koje student želi jesti i staviti ga na pult, kako bi
mogla poslužiti traženo jelo. Svako od pet jela je različite težine, pa svako
zahtijeva određeno vrijeme kako bi se prenijelo iz kuhinje na pult, ili s
pulta u kuhinju. Kuharica je od Milana uspjela saznati kojim redom će studenti
naručivati jelo i želi što brže poslužiti sve studente. Ulazni podaci se
sastoje od pet brojeva t (1 <= t <= 1000), koji opisuju vrijeme u sekundama
potrebno da se jelo stavi na pult ili makne s pulta. Nakon toga slijedi broj
n (1 <= n <= 100000) i zatim n brojeva x (1 <= x <= 5) koji redom opisuju jela
koje studenti žele jesti. Posluživanje jela koje je na pultu traje 10 sekundi.
Ne mora se čekati na studente jer svi stoje u redu i čekaju na svoje porcije.
Prije nego dođe prvi student, kuharica može staviti bilo koja dva jela na
pult. Ispišite najmanji broj sekundi potreban da se posluže svi studenti.

Ispis: 2000
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

const int MEALS_NUM = 5;
const int SERVING_TIME = 10;
constexpr int INF = numeric_limits<int>::max() / 2;

int recursion(vector<vector<vector<int>>> &dp, const vector<int> &orders,
              const int carryTimes[], int a, int b, int orderIndex) {

  if (orderIndex == -1) {
    return 0;
  }
  if (dp[a][b][orderIndex] != INF) {
    return dp[a][b][orderIndex];
  }
  if (a != orders[orderIndex] && b != orders[orderIndex]) {
    return (dp[a][b][orderIndex] = INF);
  }

  int result = INF;
  if (a == orders[orderIndex]) {
    for (int i = 0; i < MEALS_NUM; ++i) {
      if (i != a) {
        result = min(result,
                     recursion(dp, orders, carryTimes, i, b, orderIndex - 1) +
                         carryTimes[i] + carryTimes[a] + SERVING_TIME);
      }
    }
  }
  if (b == orders[orderIndex]) {
    for (int i = 0; i < MEALS_NUM; ++i) {
      if (i != b) {
        result = min(result,
                     recursion(dp, orders, carryTimes, a, i, orderIndex - 1) +
                         carryTimes[i] + carryTimes[b] + SERVING_TIME);
      }
    }
  }
  result = min(result, recursion(dp, orders, carryTimes, a, b, orderIndex - 1) +
                           SERVING_TIME);

  return (dp[a][b][orderIndex] = result);
}

int main() {

  int carryTimes[MEALS_NUM];
  for (int i = 0; i < MEALS_NUM; ++i) {
    cin >> carryTimes[i];
  }

  int ordersNum;
  cin >> ordersNum;

  vector<int> orders(ordersNum);
  for (int i = 0; i < ordersNum; ++i) {
    cin >> orders[i];
    --orders[i];
  }

  vector<vector<vector<int>>> dp(
      MEALS_NUM, vector<vector<int>>(MEALS_NUM, vector<int>(ordersNum, INF)));
  int result = INF;
  for (int i = 0; i < MEALS_NUM; ++i) {
    result = min(result, recursion(dp, orders, carryTimes, i,
                                   orders[ordersNum - 1], ordersNum - 1));
  }

  cout << result << endl;

  return 0;
}
