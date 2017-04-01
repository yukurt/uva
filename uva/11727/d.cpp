#include <stdio.h>
#include <cstdlib>

int main() {
  int min = 1000;
  int max = 10000;
  int T = 19;

  int a, b, c;

  srand(0);

  printf("%d\n", T);
  for (int i = 0; i < T; ++i) {
    a = rand() % (max - min + 1) + min;
    b = rand() % (max - min + 1) + min;
    c = rand() % (max - min + 1) + min;
    printf("%d %d %d\n", a, b, c);
  }

  return 0;
}
