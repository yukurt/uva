#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
  const int lsize = 100000;
  char line[lsize];
  int n, x, y, r, c, i, j, k;
  int p, q, s, t, u, v;
  int max, sum;
  char *pch;
  int arr[150][150];
  int sumsA[150][150];
  int sumsB[150][150];

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

//  printf("1x1\n");
  for (i = 1; i <= n; i += 1) {
    for (j = 1; j <= n; j += 1) {
      sum = arr[i][j];
      sumsA[i][j] = sum;
      sumsB[i][j] = sum;

      if (sum > max) {
        max = sum;
      }
    }
  }

//  printf("1x2, 1x3, 1x4, ...\n");
  for (i = 2; i <= n; i += 1) {
    x = n - i + 1;
    for (j = 1; j <= n; j += 1) {
      for (k = 1; k <= x; k += 1) {
        sum = sumsA[j][k] + arr[j][k+i-1];
        sumsA[j][k] = sum;
        if (sum > max) {
          max = sum;
        }
//        printf("%d %d %d = %d\n", i, j, k, sum);
      }
    }
  }

//  printf("2x1, 3x1, 4x1, ...\n");
  for (i = 2; i <= n; i += 1) {
    x = n - i + 1;
    for (j = 1; j <= x; j += 1) {
      for (k = 1; k <= n; k += 1) {
        sum = sumsB[j][k] + arr[j+i-1][k];
        sumsB[j][k] = sum;
        sumsA[j][k] = sum;
        if (sum > max) {
          max = sum;
        }
//        printf("%d %d %d = %d\n", i, j, k, sum);
      }
    }

//    printf("\t%dx2,3,4,...\n", i);
    for (s = 2; s <= n; s += 1) {
      y = n - s + 1;
      for (j = 1; j <= x; j += 1) {
        for (k = 1; k <= y; k += 1) {
          sum = sumsA[j][k] + sumsB[j][k+s-1];
          sumsA[j][k] = sum;
          if (sum > max) {
            max = sum;
          }
//          printf("\t%d %d %d %d = %d\n", i, s, j, k, sum);
        }
      }
    }
  }

  printf("%d\n", max);

  return 0;
}
