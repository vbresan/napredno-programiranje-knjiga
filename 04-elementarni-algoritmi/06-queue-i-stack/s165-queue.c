/* Queue implementiran pomocu vezane liste. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *first, *last;
} Queue;

int enqueue(Queue *queue, int data) {

  Node *current = malloc(sizeof(Node));
  if (!current) {
    return 0;
  }

  current->data = data;
  current->next = 0;

  if (!queue->first) {
    queue->first = current;
  }

  if (queue->last) {
    queue->last->next = current;
  }
  queue->last = current;

  return 1;
}

int dequeue(Queue *queue, int *data) {

  if (!queue->first) {
    return 0;
  }

  Node *current = queue->first;
  *data = current->data;
  queue->first = current->next;
  free(current);

  if (!queue->first) {
    queue->last = 0;
  }

  return 1;
}

void print_queue(const Queue *queue) {

  printf("Curent queue: ");
  for (Node *current = queue->first; current; current = current->next) {
    printf("%d ", current->data);
  }
  printf("\n");
}

void free_queue(Queue *queue) {
  int dummy;
  while (dequeue(queue, &dummy)) {
    // do nothing
  }
}

Queue get_queue() {

  Queue queue;
  queue.first = 0;
  queue.last = 0;

  return queue;
}

int main() {

  Queue queue = get_queue();

  int choice;
  while (1) {

    printf("1: Enqueue\n2: Dequeue\n3: Quit\n");
    scanf("%d", &choice);

    if (choice == 1) {

      int x;
      scanf("%d", &x);
      if (enqueue(&queue, x)) {
        print_queue(&queue);
      } else {
        printf("Can't enqueue, the memory is full.\n");
      }

    } else if (choice == 2) {

      int x;
      if (dequeue(&queue, &x)) {
        printf("%d\n", x);
        print_queue(&queue);
      } else {
        printf("Can't dequeue, the queue is empty.\n");
      }

    } else {
      break;
    }
  }

  free_queue(&queue);

  return 0;
}
