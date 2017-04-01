#include <stdio.h>
#include <list>

int main() {
	const int MAX_SIZE = 100;
	char line[100];

	while (fgets(line, MAX_SIZE, stdin)) {
		unsigned int N, M;
		sscanf(line, "%d %d", &N, &M);

		if (N == 0) {
			break;
		}

		if (N == M) {
			printf("%d things taken %d at a time is 1 exactly.\n", N, M);
			continue;
		}

		unsigned int D = N - M;

		unsigned int smaller, bigger;
		if (D < M) {
			smaller = D;
			bigger = M;
		}
		else {
			smaller = M;
			bigger = D;
		}

		std::list<unsigned int> nl;
		for (int i = N; i > bigger; --i) {
			nl.push_back(i);
		}

		std::list<unsigned int> dl;
		for (int i = smaller; i > 1; --i) {
			dl.push_back(i);
		}

		for (auto i = dl.begin(); i != dl.end();) {
			bool found = false;

			for (auto j = nl.begin(); j != nl.end(); ++j) {
				if (*j % *i == 0) {
					found = true;
					*j = *j / *i;

					if (*j == 1) {
						j = nl.erase(j);
					}

					i = dl.erase(i);
					break;
				}
			}

			if (!found) {
				++i;
			}
		}

		unsigned long long int np = 1;
		for (auto i: nl) {
			np *= i;
		}

		unsigned long long int dp = 1;
		for (auto i: dl) {
			dp *= i;
		}

		unsigned long long int q = np / dp;
		printf("%d things taken %d at a time is %llu exactly.\n", N, M, q);
	}

	return 0;
}
