#include <stdio.h>

int main() {
  char line[100];
  int n, a, f;
 
  fgets(line, 100, stdin);
  sscanf(line, "%d", &n);

  for (int i = 0; i < n; i += 1) {
    fgets(line, 100, stdin);
    scanf("%d %d", &a, &f);

    if (i > 0) {
      printf("\n");
    }

    for (int j = 0; j < f; j += 1) {
      if (j > 0) {
        printf("\n");
      }

      for (int p = 1; p <= a; p += 1) {
        for (int q = 0; q < p; q += 1) {
          printf("%d", p);
        }
        printf("\n");
      }

      for (int p = a - 1; p >= 1; p -= 1) {
        for (int q = 0; q < p; q += 1) {
          printf("%d", p);
        }
        printf("\n");
      }
    }
  }

  return 0;
}
