#include <stdio.h>
#include <deque>
#include <string.h>

int main() {
	const int MAX_LINE = 1010;
	int LLCS[MAX_LINE][MAX_LINE];
	char line[MAX_LINE];
	int n;
	int fhist[MAX_LINE];
	int shist[MAX_LINE];

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		fhist[x] = i;
	}

	while (true)
	{
		for (int i = 1; i <= n; ++i)
		{
			int x;

			if (scanf("%d", &x) == EOF)
			{
				return 0;
			}

			shist[x] = i;
		}

		for (int i = 0; i <= n; ++i)
		{
			LLCS[i][0] = 0;
		}

		for (int j = 0; j <= n; ++j)
		{
			LLCS[0][j] = 0;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (fhist[i] == shist[j])
				{
					LLCS[i][j] = LLCS[i - 1][j - 1] + 1;
				}
				else
				{
					int v = LLCS[i - 1][j];
					int h = LLCS[i][j - 1];

					LLCS[i][j] = v > h ? v : h;
				}
			}
		}

		printf("%d\n", LLCS[n][n]);
	}

	return 0;
}
