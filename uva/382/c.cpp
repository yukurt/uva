#include <stdio.h>
#include <math.h>
#include <vector>
#include <numeric>

int main() {
  int x, q, i, sum;
  std::vector<int> v;

  printf("PERFECTION OUTPUT\n");

  while (1) {
    scanf("%d", &x);

    if (!x) {
      break;
    }

    if (x == 1) {
      printf("%5d  DEFICIENT\n", 1);
      continue;
    }

    v.clear();
    v.push_back(1);

    q = sqrt(x);

    if (x % 2 == 0) {
      for (i = 2; i <= q; ++i) {
        if (x % i == 0) {
          v.push_back(i);
          v.push_back(x / i);
        }
      }
    }
    else {
      for (i = 3; i <= q; i += 2) {
        if (x % i == 0) {
          v.push_back(i);
          v.push_back(x / i);
        }
      }
    }

    if (q * q == x) {
      v.pop_back();
    }

/*
    for (auto q: v) {
      printf("%d ", q);
    }
    printf("\n"); 
*/

    sum = std::accumulate(v.begin(), v.end(), 0);
    if (sum > x) {
      printf("%5d  ABUNDANT\n", x);
    }
    else if (sum < x) {
      printf("%5d  DEFICIENT\n", x);
    }
    else {
      printf("%5d  PERFECT\n", x);
    }
  }

  printf("END OF OUTPUT\n");

  return 0;
}
