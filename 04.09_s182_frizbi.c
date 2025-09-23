/*
Brojevi su posloženi u krug i dodaju se frizbijem. Unosi se n (1 <= n <= 1000)
i zatim n prirodnih brojeva manjih od 10^9. Drugi uneseni broj je desno od
prvoga, treći uneseni broj je desno od drugog, itd. Prvi uneseni broj je desno
od zadnjega. Na početku prvi broj ima frizbi. Ako je prvi broj pet, onda će on
izići iz kruga i dodati frizbi petom zdesna. Onaj tko dobije frizbi će izići
iz kruga i dodati ga x-tom zdesna, ako mu je vrijednost x. Brojevi izlaze iz
kruga i bacaju frizbi. Ispiši brojeve onim redom kojim su izlazili iz kruga.
*/

#include <stdio.h>
typedef struct {
  int passes, previous, next;
} Item;

int main() {

  int n;
  scanf("%d", &n);

  Item circle[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &circle[i].passes);
    circle[i].previous = i - 1;
    circle[i].next = i + 1;
  }
  circle[n - 1].next = 0;
  circle[0].previous = n - 1;

  int frizbi = 0;
  for (int i = n - 1; i; i--) {

    printf("%d ", circle[frizbi].passes);

    int previous = circle[frizbi].previous;
    int next = circle[frizbi].next;
    circle[previous].next = next;
    circle[next].previous = previous;

    int passes = circle[frizbi].passes % i;
    if (!passes) {
      passes = i;
    }
    for (int j = 0; j < passes; j++) {
      frizbi = circle[frizbi].next;
    }
  }

  printf("%d\n", circle[frizbi].passes);

  return 0;
}
