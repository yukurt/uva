#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
	unsigned int X;
	std::vector<unsigned int> v;

	while (1) {
		if (scanf("%d", &X) == EOF) {
			break;
		}

		v.push_back(X);
		sort(v.begin(), v.end());

		int mid = v.size() >> 1;
		printf("%d\n", v[mid]);

		if (scanf("%d", &X) == EOF) {
			break;
		}

		v.push_back(X);
		sort(v.begin(), v.end());

		mid = v.size() >> 1;
		unsigned int average = (v[mid-1] + v[mid]) >> 1;
		printf("%d\n", average);
	}

	return 0;
}
