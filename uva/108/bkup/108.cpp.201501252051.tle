#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
  const int lsize = 100000;
  char line[lsize];
  int n, x, y, r, c, i, j;
  int p, q, s, t, u, v;
  int max, sum;
  char *pch;
  int arr[150][150];

  fgets(line, lsize, stdin);
  sscanf(line, "%d", &n);

  r = c = 1;
  while (fgets(line, lsize, stdin)) {
    pch = strtok(line, " \t\n");
    while (pch) {
      x = atoi(pch);
      arr[r][c] = x;

      c += 1;
      if (c > n) {
        r += 1;
        c = 1;
      }

      pch = strtok(NULL, " \t\n");
    }
  }

//  for (r = 1; r <= n; r += 1) {
//    for (c = 1; c <= n; c += 1) {
//      printf("%d ", arr[r][c]);
//    }
//    printf("\n");
//  }

  max = arr[1][1];
  for (i = 1; i <= n; i += 1) {
    x = n - i + 1;
    for (j = 1; j <= n; j += 1) {
//      printf("%d %d\n", i, j);
      y = n - j + 1;
      for (p = 1; p <= x; p += 1) {
        u = p + i - 1;
        for (q = 1; q <= y; q += 1) {
          sum = 0;
          v = q + j - 1;
          for (r = p; r <= u; r += 1) {
            for (c = q; c <= v; c += 1) {
              sum += arr[r][c];
            }
          }
//          printf("%d %d %d %d = %d\n", i, j, p, q, sum);
          if (sum > max) {
            max = sum;
          }
        }
      }
    }
  }

  printf("%d\n", max);

  return 0;
}
