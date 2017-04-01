#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <list>
#include <iterator>

int main() {
	const int lsize = 10000;
	char line[lsize];
	char *pch;
	int x, N, count;
	std::list<int> ll;

	bool collecting = false;
	while (fgets(line, lsize, stdin)) {
		pch = strtok(line, " \t\n");
	    while (pch) {
			x = atoi(pch);

			if (!collecting) {
				if (!x) {
					printf("Minimum exchange operations : 0\n");
					pch = strtok(NULL, " \t\n");
					continue;
				}

				N = x;
				collecting = true;
				count = 0;
				ll.clear();
			}
			else {
				ll.push_back(x);
				++count;

				if (count == N) {
					collecting = false;

/*
					for (auto i: ll) {
						printf("%d ", i);
					}
					printf("\n");
*/

					int total_num_flip = 0;

					for (auto i = ++(ll.begin()); i != ll.end();) {
						int local_num_flip = 0;
						auto j = i;

						while (1) {
							auto k = std::prev(j);

							if (*i < *k) {
								++local_num_flip;
								j = k;
							}
							else {
								break;
							}

							if (j == ll.begin()) {
								break;
							}
						}

						if (local_num_flip) {
							total_num_flip += local_num_flip;
							ll.insert(j, *i);
							i = ll.erase(i);

/*
							for (auto i: ll) {
								printf("%d ", i);
							}
							printf("\n");
*/
						}
						else {
							++i;
						}
					}

					printf("Minimum exchange operations : %d\n", total_num_flip);
				}
			}

			pch = strtok(NULL, " \t\n");
		}
	}

	return 0;
}
