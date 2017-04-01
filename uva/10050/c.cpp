#include <stdio.h>
#include <set>

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i) {
		int N;
		scanf("%d", &N);

		int P;
		scanf("%d", &P);

//		printf("N=%d P=%d\n", N, P);

		std::set<int> hs;
		for (int j = 1; j <= P; ++j) {
			int h;
			scanf("%d", &h);
			hs.insert(h);
		}

//		for (auto v: hs) {
//			printf("%d ", v);
//		}
//		printf("\n");

		int count = 0;
		for (int j = 1; j <= N; ++j) {
			if (j % 7 == 0) {
				continue;
			}

			if ((j - 6) % 7 == 0) {
				continue;
			}

			for (auto v: hs) {
				if (j % v == 0) {
					++count;
					break;
				}
			}
		}

		printf("%d\n", count);
	}

	return 0;
}
