#include <stdio.h>
#include <math.h>

int main() {
  unsigned int n, k;
  double x;

  while (1) {
    scanf("%d", &n);

    if (n == 0) break;

    x = sqrt(n);
    k = int(x);

    if ((x - double(k)) < 0.00000001) {
      printf("yes\n");
    }
    else {
      printf("no\n");
    }
  }

  return 0;
}
