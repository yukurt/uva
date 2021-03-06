#include <stdio.h>
#include <vector>
#include <set>

int main() {
	const int MAX_SIZE = 1000;
	char line[MAX_SIZE];

	while (1) {
		unsigned int B, P, M;

		if (!fgets(line, MAX_SIZE, stdin)) {
			break;
		}
		sscanf(line, "%d", &B);

		if (!fgets(line, MAX_SIZE, stdin)) {
			break;
		}
		sscanf(line, "%d", &P);

		if (!fgets(line, MAX_SIZE, stdin)) {
			break;
		}
		sscanf(line, "%d", &M);

//		printf("B:B=%d,P=%d,M=%d:E\n", B, P, M);

		if (P == 0) {
			if (M > 1) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}

			fgets(line, MAX_SIZE, stdin);
			continue;
		}

		if (B == 0 || M == 1) {
			printf("0\n");
			fgets(line, MAX_SIZE, stdin);
			continue;
		}

		unsigned int base_mod = B % M;

		std::vector<unsigned int> mod_seq;
		mod_seq.push_back(base_mod);

		std::set<unsigned int> mod_set;
		mod_set.insert(base_mod);

		unsigned int curr_mod = base_mod;
		bool zeroed_out = false;

//		printf("base_mod=%d\n", base_mod);
//		int i = 1;
		while (1) {
			curr_mod = (curr_mod * (unsigned long long int)B) % M;
//			printf("i = %d, curr_mod = %d\n", i, curr_mod);

			if (!curr_mod) {
				zeroed_out = true;
				break;
			}

			if (mod_set.find(curr_mod) != mod_set.end()) {
				break;
			}
			
			mod_set.insert(curr_mod);
			mod_seq.push_back(curr_mod);
//			++i;
		}

		//for (auto x: mod_seq) {
		//	printf("%d ", x);
		//}
		//printf("\n");

		unsigned int seq_len = mod_seq.size();

		if (zeroed_out) {
			if (P > seq_len) {
				printf("0\n");
				fgets(line, MAX_SIZE, stdin);
				continue;
			}
		}

		unsigned int offset;
		for (offset = 0; offset < seq_len; ++offset) {
			if (mod_seq[offset] == curr_mod) {
				break;
			}
		}

		if (P - 1 < offset) {
			printf("%d\n", mod_seq[P - 1]);
			fgets(line, MAX_SIZE, stdin);
			continue;
		}

		seq_len = seq_len - offset;
		unsigned int mod_ind = (P - offset - 1) % seq_len + offset;
//		printf("mod_ind=%d\n", mod_ind);
		printf("%d\n", mod_seq[mod_ind]);

		fgets(line, MAX_SIZE, stdin);
	}

	return 0;
}
