/* Faktorizacija sa Eratostenovim sitom. */

#include <stdio.h>

int prosti[1000000]; // vec inicijalizirani na 0

void rastavi(int x) {

  while (prosti[x]) {

    printf("%d ", prosti[x]);
    x /= prosti[x];
  }

  printf("%d \n", x);
}

int main() {

  prosti[0] = prosti[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    if (prosti[i] == 0) {
      for (int j = i * i; j < 1000000; j += i) {
        prosti[j] = i;
      }
    }
  }

  rastavi(123321);
  rastavi(351333);
  rastavi(1560);
  rastavi(68335);
  rastavi(48);
  rastavi(600);

  rastavi(407);

  return 0;
}
