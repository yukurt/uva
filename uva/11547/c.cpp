#include <stdio.h>
#include <cmath>

int main() {
	int arr[] = {0, 2, 3, 5, 6, 8, 9, 1, 2, 4, 5, 7, 8, 0, 1, 3, 4, 6, 7, 9};
	int t, n;

	scanf("%d", &t);

	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		printf("%d\n", arr[(int)std::abs(n+117.5) % 20]);
	}

	return 0;
}
