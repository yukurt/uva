#include <stdio.h>
#include <map>
#include <string.h>

int main() {
	const int MAX_SIZE = 10000;
	char line[MAX_SIZE], word[MAX_SIZE];
	std::map<char, char> rev;

	rev['A'] = 'A';
	rev['E'] = '3';
	rev['H'] = 'H';
	rev['I'] = 'I';
	rev['J'] = 'L';
	rev['L'] = 'J';
	rev['M'] = 'M';
	rev['O'] = 'O';
	rev['S'] = '2';
	rev['T'] = 'T';
	rev['U'] = 'U';
	rev['V'] = 'V';
	rev['W'] = 'W';
	rev['X'] = 'X';
	rev['Y'] = 'Y';
	rev['Z'] = '5';
	rev['1'] = '1';
	rev['2'] = 'S';
	rev['3'] = 'E';
	rev['5'] = 'Z';
	rev['8'] = '8';

	while (fgets(line, MAX_SIZE, stdin)) {
		sscanf(line, "%s\n", word);

		int len = strlen(word);
		int mid = len / 2;

		bool is_pal = true;
		bool is_mir = true;

		if (len > 1) {
			for (int i = 0, j = len - 1; i < mid; ++i, --j) {
				if (word[i] != word[j]) {
					is_pal = false;
					break;
				}
			}		
		}

		if (len % 2) {
			char r = word[mid];

			auto it = rev.find(r);

			if (it != rev.end()) {
				r = it->second;
			}
			else {
				r = 'x';
			}

			if (word[mid] != r) {
				is_mir = false;
			}			
		}

		if (is_mir) {
			for (int i = 0, j = len - 1; i < mid; ++i, --j) {
				char r = word[j];

				auto it = rev.find(r);

				if (it != rev.end()) {
					r = it->second;
				}
				else {
					r = 'x';
				}

				if (word[i] != r) {
					is_mir = false;
					break;
				}
			}
		}

		if (is_pal) {
			if (is_mir) {
				printf("%s -- is a mirrored palindrome.\n\n", word);
			}
			else {
				printf("%s -- is a regular palindrome.\n\n", word);
			}
		}
		else {
			if (is_mir) {
				printf("%s -- is a mirrored string.\n\n", word);
			}
			else {
				printf("%s -- is not a palindrome.\n\n", word);
			}
		}
	}

	return 0;
}
