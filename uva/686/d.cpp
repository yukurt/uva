#include <stdio.h>

int main()
{
//	bool primes[10] = { 1,0,0,0,1,1,0,0,0,1,1 };

	int i, n;
	scanf("%d", &n);

	for (i = 0; true; ++i)
	{
		if (i == n)
		{
			printf("1,");

			if (scanf("%d", &n) == EOF)
			{
				break;
			}
		}
		else
		{
			printf("0,");
		}
	}

	for (++i; i < 49999; ++i)
	{
		printf("0,");
	}
	printf("0\n");

	return 0;
}
