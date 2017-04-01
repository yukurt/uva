#include <stdio.h>
#include <cstring>

int main()
{
	int vals[5] = {1, 5, 10, 25, 50};
	int dp[10000];
	memset(dp, 0, sizeof(dp));

	dp[0] = 1;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = vals[i]; j <= 7490; ++j)
		{
			dp[j] += dp[j - vals[i]];
		}
	}

	int n;
	while (scanf("%d", &n) != EOF)
	{
		printf("%d\n", dp[n]);
	}

	return 0;
}
