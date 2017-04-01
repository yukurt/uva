#include <cstdio>

int main()
{
	const int MAX_N = 15;
	const int MAX_LINE = 100;

	char line[MAX_LINE];
	int num_bs[MAX_N];

	while (true)
	{
		int N;
		scanf("%d", &N);

		if (!N)
		{
			break;
		}

		int min_num_bs = 100;
		for (int i = 0; i < N; ++i)
		{
			scanf("%s", line);

			num_bs[i] = 0;
			for (int j = 0; line[j]; ++j)
			{
				if (line[j] == 'B')
				{
					++num_bs[i];
				}
			}

			if (num_bs[i] < min_num_bs)
			{
				min_num_bs = num_bs[i];
			}

			printf("S%sE - %d\n", line, num_bs[i]);
		}

		printf("min_num_bs = %d\n", min_num_bs);

		int total_remaining_bs = 0;
		for (int i = 0; i < N; ++i)
		{
			total_remaining_bs += num_bs[i] - min_num_bs;
		}
		printf("total_remaining_bs = %d\n", total_remaining_bs);
	}

	return 0;
}
