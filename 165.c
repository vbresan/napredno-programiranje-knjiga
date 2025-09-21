/* Queue implementiran pomocu vezane liste. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *head, *last;

int push(int data) {

  Node *current = malloc(sizeof(Node));
  if (!current) {
    return 0;
  }

  current->data = data;
  current->next = 0;

  if (!head) {
    head = current;
  }

  if (last) {
    last->next = current;
  }
  last = current;

  return 1;
}

int pop(int *data) {

  if (!head) {
    return 0;
  }

  Node *current = head;
  *data = current->data;
  head = current->next;
  free(current);

  if (!head) {
    last = 0;
  }

  return 1;
}

void print_queue() {

  printf("Curent queue: ");
  for (Node *current = head; current; current = current->next) {
    printf("%d ", current->data);
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
