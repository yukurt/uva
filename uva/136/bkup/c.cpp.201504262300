#include <set>
#include <stdio.h>

int main() {
	std::set<unsigned int> s;

	unsigned int x = 1;

	for (int i = 1; i < 1500; ++i) {
		s.insert(x * 2);
		s.insert(x * 3);
		s.insert(x * 5);

		x = *s.begin();
		s.erase(s.begin());
	}

	printf("The 1500'th ugly number is %d.\n", x);

	return 0;
}
