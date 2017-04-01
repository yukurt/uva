#include <stdio.h>

int main() {
  int T, a, b, c, x;

  scanf("%d", &T);

  for (int i = 1; i <= T; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    //printf("a=%d b=%d c=%d\n", a, b, c);

    if (a < b) {
      if (b < c) {
        x = b;
      }
      else {
        if (a < c) {
          x = c;
        }
        else {
          x = a;
        }
      }
    }
    else {
      if (a < c) {
        x = a;
      }
      else {
        if (b < c) {
          x = c;
        }
        else {
          x = b;
        }
      }
    }

    printf("Case %d: %d\n", i, x);
  }

  return 0;
}
