/*
Unose se dva broja n i m (1 <= n,m <= 1000) koji predstavljaju dimenzije
tlocrta grada koji se unosi. Zatim se unosi n linija s po m znakova koji
predstavljaju izgled grada. Svaki uneseni znak može biti '.', 'X, 'o'
ili '-'. '.' predstavlja prolazan prostor tj. cestu, 'X' predstavlja
neprolazan prostor tj. zgradu. 'o' je burek, a '-'je Gladni. Postoji samo
jedan Gladni. Gladni se može kretati gore, dolje, lijevo i desno kroz grad.
Ispiši koliko najviše bureka Gladni može pojesti i koliko najmanje koraka
treba napraviti tako da može od početne lokacije doći do svakog bureka koji
može pojesti.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int x, y, steps;
} Data;

typedef struct Node {
  Data data;
  struct Node *next;
} Node;

typedef struct {
  Node *first, *last;
} Queue;

char map[1000][1001];
int n, m, bureks, min_steps;
Queue queue;

int enqueue(int x, int y, int steps) {

  Node *current = malloc(sizeof(Node));
  if (!current) {
    return 0;
  }

  current->data = (Data){.x = x, .y = y, .steps = steps};
  current->next = 0;

  if (!queue.first) {
    queue.first = current;
  }

  if (queue.last) {
    queue.last->next = current;
  }
  queue.last = current;

  return 1;
}

int dequeue(int *x, int *y, int *steps) {

  if (!queue.first) {
    return 0;
  }

  Node *current = queue.first;
  *x = current->data.x;
  *y = current->data.y;
  *steps = current->data.steps;
  queue.first = current->next;
  free(current);

  if (!queue.first) {
    queue.last = 0;
  }

  return 1;
}

void search(int start_x, int start_y) {

  enqueue(start_x, start_y, 0);
  while (queue.first) {

    int x, y, steps;
    dequeue(&x, &y, &steps);

    if (x < 0 || x >= n || y < 0 || y >= m) {
      continue;
    }
    if (map[x][y] == 'X' || map[x][y] == 'V') {
      continue;
    }

    if (map[x][y] == 'o') {
      bureks++;
      min_steps = steps;
      // printf("x = %d, y = %d, steps = %d\n", x, y, steps);
    }

    map[x][y] = 'V';
    enqueue(x + 1, y, steps + 1);
    enqueue(x - 1, y, steps + 1);
    enqueue(x, y + 1, steps + 1);
    enqueue(x, y - 1, steps + 1);
  }
}

int main() {

  scanf("%d %d", &n, &m);

  int start_x = -1, start_y = -1;
  for (int i = 0; i < n; i++) {
    scanf("%s", map[i]);
    char *found = strchr(map[i], '-');
    if (found) {
      start_x = i;
      start_y = found - map[i];
    }
  }

  if (start_x != -1 && start_y != -1) {
    search(start_x, start_y);
    printf("Gladni moze pojest %d bureka u %d koraka.\n", bureks, min_steps);
  } else {
    printf("Nije unesena pocetna lokacija gladnog.\n");
  }

  return 0;
}
