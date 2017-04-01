#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iterator>
#include <iostream>

int main() {
	std::vector<char> v = {'c', 'b', 'b', 'a', 'a'};
	//std::sort(v.begin(), v.end());

	int i = 1;
	do {
		printf("%d: ", i);
		std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, " "));
		std::cout << std::endl;
		++i;
	} while (std::next_permutation(v.begin(), v.end()));

	return 0;
}
