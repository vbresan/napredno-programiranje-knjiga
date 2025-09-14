/* Na koliko se nacina na sahovsku plocu moze staviti 8 kraljica, tako da se
 * nijedan par medjusobno ne napada. */

#include <stdio.h>

void print_array(int array[], int end) {
  for (int i = 0; i <= end; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void check_diagonals(int array[], int end) {
  for (int i = 0; i < end; i++) {
    int invalid = 0;
    for (int j = i + 1; j <= end && !invalid; j++) {
      if (array[i] + i == array[j] + j || array[i] - i == array[j] - j) {
        //        printf("Invlid\n");
        invalid = 1;
      }
    }
    if (!invalid) {
      print_array(array, end);
    }
  }
}

void swap(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

void permute(int array[], int start, int end) {

  if (start == end) {
    print_array(array, end);
    // check_diagonals(array, end);
    return;
  }

  for (int i = start; i <= end; i++) {
    swap(array, start, i);
    permute(array, start + 1, end);
    swap(array, start, i);
  }
}

int main() {

  int columns[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int n = sizeof(columns) / sizeof(columns[0]);

  permute(columns, 0, n - 1);

  return 0;
}
