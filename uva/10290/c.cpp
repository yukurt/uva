#include <stdio.h>
#include <math.h>

int main() {
	unsigned long long int N;

	while (scanf("%llu", &N) != EOF) {
//		printf("\nN=%llu\n", N);

		unsigned long long int n = (unsigned long long int)sqrt(N * 2);
//		printf("n=%llu\n", n);

		unsigned long long int sum;		
		if (n & 1) {
			sum = n * ((n + 1) >> 1);
		}
		else {
			sum = (n >> 1) * (n + 1);
		}

//		printf("sum=%llu\n", sum);

		long long int diff = N - sum;
		if (diff < 0) {
//			printf("Entered\n");
			sum -= n;
			--n;
		}

		unsigned long long int count = 0;
		while (n) {
//			printf("N=%llu, n=%llu, sum=%llu, count=%d\n", N, n, sum, count);
			if (!((N - sum) % n)) {
				++count;
//				printf("N=%llu, n=%llu, sum=%llu, count=%llu\n", N, n, sum, count);
			}

			sum -= n;
			--n;
		}

		printf("N=%llu, count=%llu\n", N, count);
	}

	return 0;
}
