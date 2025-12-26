/*
Dan je niz od n (1 <= n <= 1000) brojeva s kojim se igra "niz". Željko i Katica
naizmjenično uzimaju po jedan broj s početka ili kraja niza. Prvi igra Željko.
Kad se uzmu sve brojke iz niza, igra završava i pobjeđuje onaj tko je uzeo
veću sumu brojeva. Ako je izjednačeno pobjeđuje Katica. I Željko i Katica
igraju optimalno. Ulazni podaci su n, zatim n brojeva manjih od 100000 koji
opisuju niz s kojim se igra "niz". Ispišite "Zeljko" ako Željko pobjedi, a inače
"Katica".

Ispis: Zeljko
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n;
  cin >> n;

  vector<int> sequence(n);
  for (int &number : sequence) {
    cin >> number;
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; ++i) {       // interval width
    for (int j = 0; j <= n - i; ++j) { // interval start
      if (i % 2 == n % 2) {            // Zeljko
        dp[j][i] = max(dp[j][i - 1] + sequence[j + i - 1],
                       dp[j + 1][i - 1] + sequence[j]);
      } else { // Katica
        dp[j][i] = min(dp[j][i - 1] - sequence[j + i - 1],
                       dp[j + 1][i - 1] - sequence[j]);
      }
    }
  }

  cout << ((dp[0][n] > 0) ? "Zeljko" : "Katica") << endl;

  return 0;
}
