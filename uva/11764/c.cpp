#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; ++i)
	{
		int N;
		scanf("%d", &N);

		int prev;
		scanf("%d", &prev);

		int num_high = 0;
		int num_low = 0;

		for (int j = 2; j <= N; ++j)
		{
			int curr;
			scanf("%d", &curr);

			if (curr > prev)
			{
				++num_high;
			}
			else if (curr < prev)
			{
				++num_low;
			}

			prev = curr;
		}

		printf("Case %d: %d %d\n", i, num_high, num_low);
	}

	return 0;
}
