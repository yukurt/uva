#include <stdio.h>

int main() {
  int n, i, s, d, sum, a, b;

  scanf("%d\n", &n);

  for (i = 0; i < n; ++i) {
    scanf("%d %d\n", &s, &d);

    if (s < d) {
      printf("impossible\n");
      continue;
    }

    sum = s + d;

    if (sum & 1) {
      printf("impossible\n");
      continue;
    }

    a = sum >> 1;
    b = a - d;

    printf("%d %d\n", a, b);
  }

  return 0;
}
