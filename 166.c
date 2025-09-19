/* Cirkularni queue. */

#include <stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE] = {0};
int start = 0, end = 0;

int is_empty() { return start == end; }

int is_full() { return (end + 1) % MAX_SIZE == start; }

int push(int x) {
  if (is_full()) {
    return 0;
  }

  queue[end] = x;
  end = (end + 1) % MAX_SIZE;
  return 1;
}

int pop(int *x) {
  if (is_empty()) {
    return 0;
  }

  *x = queue[start];
  start = (start + 1) % MAX_SIZE;
  return 1;
}

void print_queue() {

  printf("Curent queue: ");
  for (int i = start; i != end; i = (i + 1) % MAX_SIZE) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {

  int choice;
  while (1) {

    printf("1: Push\n2: Pop\n3: Quit\n");
    scanf("%d", &choice);

    if (choice == 1) {

      int x;
      scanf("%d", &x);
      if (push(x)) {
        print_queue();
      } else {
        printf("Can't push, the queue is full.\n");
      }

    } else if (choice == 2) {

      int x;
      if (pop(&x)) {
        printf("%d\n", x);
        print_queue();
      } else {
        printf("Can't pop, the queue is empty.\n");
      }

    } else {
      break;
    }
  }

  return 0;
}
