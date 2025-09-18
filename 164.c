/* Za uneseni niz, ispisi sljedece permutacije. */

#include <stdio.h>
#include <string.h>

void replace(char word[], int i, int j) {

  word[i] ^= word[j];
  word[j] ^= word[i];
  word[i] ^= word[j];
}

int next_permutation(char word[]) {

  int length = strlen(word);
  int to_replace = -1;

  for (int i = length - 2; i >= 0; i--) {
    if (word[i] < word[i + 1]) {
      to_replace = i;
      break;
    }
  }

  if (to_replace == -1) {
    return 0;
  }

  int next_min = to_replace + 1;
  for (int i = to_replace + 2; i < length; i++) {
    if (word[i] > word[to_replace] && word[i] < word[next_min]) {
      next_min = i;
    }
  }

  replace(word, to_replace, next_min);

  for (int i = to_replace + 1; i < length - 1; i++) {
    for (int j = i + 1; j < length; j++) {
      if (word[i] > word[j]) {
        replace(word, i, j);
      }
    }
  }

  return 1;
}

int main() {

  char word[10];
  scanf("%9s", word);
  while (next_permutation(word)) {
    printf("%s\n", word);
  }

  return 0;
}
