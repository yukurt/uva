#include <stdio.h>

int main()
{
	for (int n; scanf("%d", &n) != EOF;)
	{
		for (int i = 1, dividend = 1; true; ++i)
		{
			dividend = dividend % n;

			if (!dividend)
			{
				printf("%d\n", i);
				break;
			}

			dividend *= 10;
			++dividend;
		}
	}

	return 0;
}
