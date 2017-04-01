#include <stdio.h>

int main() {
  int N;
  unsigned long long int x;

  while (true) {
    scanf("%d\n", &N);

    if (N < 0) {
      break;
    }

    x = (((unsigned long long int)N * (N + 1)) >> 1) + 1;
    printf("%llu\n", x);
  }

  return 0;
}
