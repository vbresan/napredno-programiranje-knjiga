/*
Na koliko načina zadane brojeve možemo podijeliti u dvije grupe tako da je
zbroj brojeva u pojedinoj grupi jednak? Ulazni podaci su n (2 <= n <= 100) i
zatim n cijelih, međusobno različitih, brojeva a (1 <= a <= 100). Ispišite
ostatak pri dijeljenju broja načina s 999907.

Ispis: 9
*/

#include <iostream>
#include <vector>
using namespace std;

const int MOD = 999907;

long long mod_pow(long long base, int exp, int mod) { // (base ^ exp) % mod
  long long result = 1;
  while (exp) {
    if (exp & 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    exp >>= 1;
  }
  return result;
}

int main() {

  int n;
  cin >> n;

  int sum = 0;
  vector<int> numbers(n);
  for (int &number : numbers) {
    cin >> number;
    sum += number;
  }

  if (sum & 1) {
    cout << 0 << endl;
    return 0;
  }

  sum /= 2;
  vector<int> dp(sum + 1);
  dp[0] = 1;

  for (const int number : numbers) {
    for (int i = sum - number; i >= 0; --i) {
      dp[i + number] = (dp[i + number] + dp[i]) % MOD;
    }
  }

  cout << (dp[sum] * mod_pow(2, MOD - 2, MOD)) % MOD << endl;

  return 0;
}
