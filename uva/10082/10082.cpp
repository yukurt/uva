#include <stdio.h>

int main() {
    char line[1000];
    int i, j;
    char orig[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";

    while(gets(line)) {
        for(i = 0; line[i]; i += 1) {
            if(line[i] == ' ') {
                printf(" ");
                continue;
            }
            for(j = 0; orig[j]; j += 1) {
                if(line[i] == orig[j]) {
                    printf("%c", orig[j-1]);
                    break;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
