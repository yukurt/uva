#include <stdio.h>

int main() {
    int i, x, r, is_ugly, count;

    count = 0;
    for(i = 1; 1; i += 1) {
        x = i;
        is_ugly = 1;
        while (x > 1) {
            r = x % 2;
            if (r) {
                r = x % 3;
                if (r) {
                    r = x % 5;
                    if (r) {
                        is_ugly = 0;
                        break;
                    }
                    else {
                        x /= 5;
                    }
                }
                else {
                    x /= 3;
                }
            }
            else {
                x /= 2;
            }
        }
        if (is_ugly) {
            count += 1;
            //printf("%d ", i);
            if (count >= 1500) {
                break;
            }
        }
    }
    printf("The 1500'th ugly number is %d.\n", i);

    return 0;
}
