#include <stdio.h>

int main() {
	int x = 30000000;

	for (int i = 1; i <= x; ++i) {
		int j = i % i;
		j -= i;
	}

	return 0;
}
