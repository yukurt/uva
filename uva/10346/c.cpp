#include <stdio.h>

int main() {
  const int MAX_SIZE = 100;
  char line[100];
  int n, k, sq, sr;

  while (fgets(line, MAX_SIZE, stdin)) {
    sscanf(line, "%d %d\n", &n, &k);

    sq = n;
    sr = n;

    do {
      n = sr;
      sr = 0;
      do {
        sr += n % k;
        n /= k;
        sq += n;
      } while (n);
    } while (sr >= k);

    printf("%d\n", sq);
  }

  return 0;
}
