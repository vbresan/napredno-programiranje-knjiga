/*
Nalazite se u dugačkom tunelu koji ima pet traka za automobile. Na ulazu u
tunel nalazi se vaš prijatelj koji vam je dojavio kojim će trakama dolaziti
automobili tijekom sljedećih n (1 <= n <= 1000000) sekundi. U tunelu nema
mjesta kako bi se maknuli s ceste. Želite biti na onim trakama kojima ne voze
automobili kako vas ne bi pregazili. Ako npr. u sedmoj sekundi prvom, drugom,
trećom i petom trakom prolazi automobil, vi želite u sedmoj sekundi biti na
četvrtoj traci, kako vas ne bi pregazio automobil. Problem je u tome što vam
za prelaženje na susjednu traku treba jedna sekunda. Ako ste u x-toj sekundi
na drugoj traci, onda u (x+1)-oj sekundi možete biti na prvoj, drugoj ili
trećoj traci. Prije nego dođe prvi automobil, možete biti u bilo kojoj traci.
Ulazni podaci su n i zatim n puta po pet znakova koji mogu biti '-' ili 'x'.
Ako u i-tom retku unosa piše '---xx', to znači da u i-toj sekundi četvrtom i
petom trakom prolazi automobil. Na početku se nalazite na bilo kojoj traci.
Ispiši koliko minimalno puta morate biti pregaženi.

Ispis: 2
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  int n;
  string s;

  cin >> n;
  cin >> s;

  vector<int> dp(5);
  for (int i = 0; i < 5; ++i) {
    dp[i] = (s[i] == 'x');
  }

  for (int i = 1; i < n; ++i) {
    cin >> s;
    vector<int> previous = dp;
    for (int j = 0; j < 5; ++j) {
      int value = s[j] == 'x';
      dp[j] = previous[j] + value;
      if (j > 0) {
        dp[j] = min(dp[j], previous[j - 1] + value);
      }
      if (j < 4) {
        dp[j] = min(dp[j], previous[j + 1] + value);
      }
    }
  }

  cout << *min_element(dp.begin(), dp.end()) << endl;

  return 0;
}
