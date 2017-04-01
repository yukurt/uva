#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1;  i <= T; ++i)
	{
		int N;
		scanf("%d", &N);

		int max = 1;
		for (int j = 1; j <= N; ++j)
		{
			int c;
			scanf("%d", &c);

			if (c > max)
			{
				max = c;
			}
		}

		printf("Case %d: %d\n", i, max);
	}

	return 0;
}
