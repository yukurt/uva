#include <stdio.h>

int main()
{
	const int max = 1500;

	int i, n;
	scanf("%d", &n);

	// array size to store prime results should be (max + 1)
	for (i = 0; i <= max; ++i)
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

	return 0;
}
