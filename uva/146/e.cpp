#include <algorithm>
#include <vector>
#include <stdio.h>
#include <iterator>
#include <iostream>
#include <string.h>

int main() {
	char code[50] = "cbbaa";
	int len = strlen(code);

	int i = 1;
	do {
		printf("%d: %s\n", i, code);
		++i;
	} while (std::next_permutation(code, code+len));

	return 0;
}
