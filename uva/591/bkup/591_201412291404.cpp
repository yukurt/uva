#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
    char line[100];
    char *pch;
    int n, i, fair, x, moves, k;
    int h[100];

    for (k = 1; 1; k += 1) {
        gets(line);
        sscanf(line, "%d", &n);

        if(!n)
            break;

        gets(line);
        pch = strtok(line, " \t\n");
        i = 0;
        while (pch) {
            h[i] = atoi(pch);
            pch = strtok(NULL, " \t\n");
            i += 1;
        }

        fair = 0;
        for (i = 0; i < n; i += 1) {
            fair += h[i];
        }
        fair /= n;

        moves = 0;
        for (i = 0; i < n; i += 1) {
            x = h[i];
            if (x > fair) {
                moves += (x - fair);
            }
        }

        printf("Set #%d\n", k);
        printf("The minimum number of moves is %d.\n", moves);
    }

    return 0;
}
