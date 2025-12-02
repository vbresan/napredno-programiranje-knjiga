/*
Djeca su se uhvatila za ruke u lanac i trče livadom. Kako je netko brži, a
netko sporiji, događa se da brža djeca vuku sporiju. U lanac se uhvatilo n
(1 <= n <= 100000) djece tako da svako dijete drži za ruke dvoje djece koji
su pored njega (osim prvog i zadnjeg djeteta u lancu, kojima je jedna ruka
slobodna). Svako dijete ima svoju maksimalnu brzinu x_i (0 <= x_i <= 1000)
kojom može trčati i dio brzine y_i, (1 <= y_i <= 1000) koju gubi za svako
dijete koje ga vuče ili koga on vuče (jer postaje nestabilno i može pasti).
Djeca se mogu međusobno vući tako što dio svoje snage utroše na povlačenje
drugog djeteta. Koliko najbrže lanac djece može trčati?

Unos se sastoji od cijelih brojeva i počinje brojem n. Nakon toga slijedi
n parova brojeva x i y koji opisuju pojedino dijete. Djeca se drže za ruke
onim redom kojim su navedeni u unosu. Ispišite najveću brzinu (na 3 decimale)
kojom djeca mogu trčati u lancu.

out 1 = 21.5
out 2 = 20
out 3 = 20
out 4 = 77.750
out 5 = 76
out 6 = 22
out 7 = 28
out 8 = 26.4
*/

#include <stdio.h>

typedef struct {
  double speed, loss;
} Child;

double get_minimum_speed(Child children[], int length) {

  double min = children[0].speed;
  for (int i = 1; i < length; i++) {
    if (children[i].speed < min) {
      min = children[i].speed;
    }
  }

  return min;
}

double get_average_speed(Child children[], int length) {

  double sum = 0;
  for (int i = 0; i < length; i++) {
    sum += children[i].speed;
  }

  return sum / length;
}

int can_run(double speed, Child children[], int length) {

  double transfer = 0;
  for (int i = 0; i < length - 1; i++) {

    transfer += children[i].speed;
    transfer -= speed;

    if (transfer >= 0 && transfer <= children[i].loss + children[i + 1].loss) {
      transfer = 0;
    } else {
      transfer -= children[i].loss + children[i + 1].loss;
    }
  }

  transfer += children[length - 1].speed;
  transfer -= speed;

  return transfer >= 0;
}

int main() {

  int n;
  scanf("%d", &n);

  Child children[n];
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &children[i].speed, &children[i].loss);
  }

  double low = get_minimum_speed(children, n);
  double high = get_average_speed(children, n);
  while (high - low > 0.0005) {
    double middle = (low + high) / 2;
    if (can_run(middle, children, n)) {
      low = middle;
    } else {
      high = middle;
    }
  }

  printf("%.3lf\n", (low + high) / 2);
  return 0;
}
