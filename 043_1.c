/* Ispisi sumu znamenaka unesenog prirodnog broja x (1 <= x <= 10^9). */

#include <stdio.h>

int main() {
    
    int x, sum;
    
    scanf("%d", &x);
    for (sum = 0; x > 0; x /= 10) {
	sum += x % 10;
    }

    printf("%d\n", sum);
    return 0;
}
