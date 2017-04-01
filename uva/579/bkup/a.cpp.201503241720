#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char line[100];
  char *pch;
  int h, m;
  float deg;

  while (fgets(line, 100, stdin)) {
    pch = strtok(line, ": \t\n");
    h = atoi(pch);

    if (0 == h) break;

    pch = strtok(NULL, ": \t\n");
    m = atoi(pch);

    deg = (11.0 * m) / 2;
    deg = (30.0 * h) - deg;

    if (deg < 0) deg *= -1;
    if (deg > 180) deg = 360 - deg;

    printf("%.3f\n", deg);
  }

  return 0;
}
