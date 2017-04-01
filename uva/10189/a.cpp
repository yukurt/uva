#include <stdio.h>

int main() {
  int n, m;
  int i, j;
  int p, q;
  int count, field;
  char arr[150][150];
  char line[150];

  for (i = 0; i < 150; i += 1) {
    arr[i][0] = '-';
    arr[0][i] = '-';
  }

  fgets(line, 150, stdin);
  sscanf(line, "%d %d\n", &n, &m);
  if (n == 0 && m == 0) {
    return 0;
  }

  for(field = 1; 1; field += 1) {
    for (i = n + 1, j = 1; j <= m + 1; j += 1) {
      arr[i][j] = '-';
    }

    for (i = 1, j = m + 1; i <= n + 1; i += 1) {
      arr[i][j] = '-';
    }

    for (i = 1; i <= n; i += 1) {
      fgets(line, 150, stdin);
      for (j = 0; j < m; j += 1) {
        arr[i][j+1] = line[j];
      }
    }

//    for (i = 0; i <= n + 1; i += 1) {
//      for (j = 0; j <= m + 1; j += 1) {
//        printf("%c", arr[i][j]);
//      }
//      printf("\n");
//    }
//    printf("\n");

    printf("Field #%d:\n", field);
    for (i = 1; i <= n; i += 1) {
      for (j = 1; j <= m; j += 1) {
        if (arr[i][j] == '*') {
          printf("%c", '*');
        }
        else {
          count = 0;
          for (p = i - 1; p <= i + 1; p += 1) {
            for (q = j - 1; q <= j + 1; q += 1) {
              if (arr[p][q] == '*') {
                count += 1;
              }
            }
          }
          printf("%d", count);
        }
      }
      printf("\n");
    }

    fgets(line, 150, stdin);
    sscanf(line, "%d %d\n", &n, &m);

    if (n == 0 && m == 0) {
      break;
    }

    printf("\n");
  }

  return 0;
}
