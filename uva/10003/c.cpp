#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
	while (true)
	{
		int l;
		scanf("%d", &l);

		if (!l)
		{
			break;
		}

		int n;
		scanf("%d", &n);

		std::vector<int> orig;
		std::vector<int> cuts;
		std::vector<bool> done;

		for (int i = 0; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			orig.push_back(x);
			cuts.push_back(i);
			done.push_back(false);
		}
/*
		printf("\nStart\n");
		printf("l = %d\n", l);
		printf("orig = ");
		for (auto i: orig)
		{
			printf("%d ", i);
		}
		printf("\n");
*/
		int min_len = 1 << 30;
//		printf("min_len = %d\n", min_len);

		do
		{
/*
			printf("permutation = ");
			for (auto i: cuts)
			{
				printf("%d ", i);
			}
			printf("\n");
*/
			int sum_lens = 0;

			for (auto i: cuts)
			{
/*
				printf("done = ");
				for (int k = 0; k < done.size(); ++k)
				{
					printf("%d ", done[k] ? 1 : 0);
				}
				printf("\n");

				printf("i = %d\n", i);
*/
				int j;
				bool found;

				found = false;
				for (j = i - 1; j >= 0; --j)
				{
					if (done[j])
					{
						found = true;
						break;
					}
				}
				int ldist = found ? orig[i] - orig[j] : orig[i];
//				printf("j = %d, found = %d, ldist = %d\n", j, found, ldist);

				found = false;
				for (j = i + 1; j < orig.size(); ++j)
				{
					if (done[j])
					{
						found = true;
						break;
					}
				}
				int rdist = found ? orig[j] - orig[i] : l - orig[i];
//				printf("j = %d, found = %d, rdist = %d\n", j, found, rdist);

				sum_lens += ldist + rdist;
//				printf("sum_lens = %d\n", sum_lens);

//				printf("hello1 i = %d\n", i);
				done[i] = true;
//				printf("hello2\n");
			}

			if (sum_lens < min_len)
			{
				min_len = sum_lens;
//				printf("Updating min_len = %d\n", min_len);
			}

			for (int k = 0; k < done.size(); ++k)
			{
				done[k] = false;
			}
		} while (std::next_permutation(cuts.begin(), cuts.end()));

		printf("The minimum cutting is %d.\n", min_len);
	}

	return 0;
}
