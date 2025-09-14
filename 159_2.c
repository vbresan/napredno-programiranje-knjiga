/* Na koliko se nacina na sahovsku plocu moze staviti 8 kraljica, tako da se
 * nijedan par medjusobno ne napada. */

#include <stdio.h>

int solutions;

void print_array(int array[], int end) {
  for (int i = 0; i <= end; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void swap(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int is_safe(int array[], int start) {

  for (int i = 0; i < start; i++) {
    if (array[i] + i == array[start] + start ||
        array[i] - i == array[start] - start) {
      return 0;
    }
  }

  return 1;
}

void permute(int array[], int start, int end) {

  if (start == end) {
    if (is_safe(array, start)) {
      // print_array(array, end);
      solutions++;
    }
    return;
  }

  for (int i = start; i <= end; i++) {
    swap(array, start, i);

    if (is_safe(array, start)) {
      permute(array, start + 1, end);
    }

    swap(array, start, i);
  }
}

int main() {

  int columns[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(columns) / sizeof(columns[0]);

  permute(columns, 0, n - 1);
  printf("%d\n", solutions);

  return 0;
}
