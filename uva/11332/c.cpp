#include <stdio.h>
#include <string.h>

int main() {
	int N;
	char str[100];

	while (scanf("%d", &N)) {
		if (!N) {
			break;
		}

		sprintf(str, "%d", N);
		int len = strlen(str);

		while (len > 1) {
			N = 0;
			for (int i = 0; i < len; ++i) {
				N += (str[i] - 48);
			}

			sprintf(str, "%d", N);
			len = strlen(str); 
		}

		printf("%d\n", N);
	}

	return 0;
}
