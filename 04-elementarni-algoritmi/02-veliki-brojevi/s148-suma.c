/* Unesi dva broja (svaki ima manje od 1000 znamenaka) i ispisi njihovu sumu. */

#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {

  for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {

    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main() {

  char a[1001] = {0}, b[1001] = {0}, c[1002] = {0};
  scanf("%s %s", a, b);

  reverse_string(a);
  reverse_string(b);

  int len_a = strlen(a), len_b = strlen(b);
  for (int i = 0; i < len_a; i++) {
    a[i] -= '0';
  }
  for (int i = 0; i < len_b; i++) {
    b[i] -= '0';
  }

  int len_c = (len_a > len_b) ? len_a : len_b;
  int prijenos = 0;
  for (int i = 0; i < len_c; i++) {
    c[i] = a[i] + b[i] + prijenos;
    if (c[i] > 9) {
      c[i] -= 10;
      prijenos = 1;
    } else {
      prijenos = 0;
    }
  }

  if (prijenos) {
    c[len_c++] = 1;
  }

  for (int i = 0; i < len_c; i++) {
    c[i] += '0';
  }

  reverse_string(c);
  printf("%s\n", c);

  return 0;
}
