/* Stack. */

#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE] = {0};
int start = 0, top = 0;

int is_empty() { return top == 0; }

int is_full() { return top == MAX_SIZE; }

int push(int x) {
  if (is_full()) {
    return 0;
  }

  stack[top++] = x;
  return 1;
}

int pop(int *x) {
  if (is_empty()) {
    return 0;
  }

  *x = stack[--top];
  return 1;
}

void print_stack() {

  printf("Curent stack: ");
  for (int i = start; i < top; i++) {
    printf("%d ", stack[i]);
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
        print_stack();
      } else {
        printf("Can't push, the stack is full.\n");
      }

    } else if (choice == 2) {

      int x;
      if (pop(&x)) {
        printf("%d\n", x);
        print_stack();
      } else {
        printf("Can't pop, the stack is empty.\n");
      }

    } else {
      break;
    }
  }

  return 0;
}
