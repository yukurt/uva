#include <stdio.h>
#include <algorithm>

int main() {
  int n, r;
  int s[1000];
  int i, j, median, sum, diff;

  scanf("%d\n", &n);

  for (i = 0; i < n; ++i) {
    scanf("%d", &r);

    for (j = 0; j < r; ++j) {
      scanf("%d", &s[j]);
    }

    std::sort(s, s+r);

    if (r%2) {
      median = s[r/2];
    }
    else {
      j = r / 2;
      median = (s[j-1] + s[j]) >> 1;
    }

    sum = 0;
    for (j = 0; j < r; ++j) {
      diff = s[j] - median;

      if (diff < 0) {
        diff *= -1;
      }

      sum += diff;
    }

    printf("%d\n", sum);
  }

  return 0;
}
