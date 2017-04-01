#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int main() {
    char line[100];
    char *pch;
    int n, i;
    int h[100];

    while (1) {
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

        printf("B");
        for (i = 0; i < n; i += 1) {
            printf("%d ", h[i]);
        }
        printf("E\n");
    }

    return 0;
}
