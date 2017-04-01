#include <stdio.h>
#include <iostream>

int main() {
	int M, N;

	while (scanf("%d %d\n", &M, &N) != EOF) {
		std::cout << M * N - 1 << std::endl;
	}

	return 0;
}
