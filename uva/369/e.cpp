#include <list>
#include <stdio.h>

int main() {
	std::list<int> l = {1, 2, 3, 4, 5, 6};

	for (auto i = l.begin(); i != l.end(); ++i) {
		if (*i == 3) {
			i = l.erase(i);
			continue;
		}
		printf("%d ", *i);
	}
	printf("\n");

	for (auto i: l) {
		printf("%d ", i);
	}
	printf("\n");

	return 0;
}

