/*
    N (0 < N <= 100) djece je stalo u krug i igraju se loptom. Na pocetku je
    lopta kod prvog djeteta. Svako dijete uvijek baci loptu istom djetetu
    (svom najboljem prijatelju). Napravi program koji ispisuje kod koga je
    lopta nakon svakog od prvih x (0 < x <= 1000) dodavanja.
    Ulazni podaci su N, x, a_1, a_2, ..., aN (0 < a_i <= N). a_i je broj
    djeteta kojemu ce dijete s brojem i dodati loptu.
*/

#include <stdio.h>

int main() {

    int n, x, a[100], lopta = 0; // lopta je kod 1. djeteta
    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
	scanf("%d", &a[i]);
    }

    for (int i = 0; i < x; i++) {
	lopta = a[lopta] - 1;
	printf("%d ", lopta + 1);
    }

    printf("\n");
    return 0;
}
