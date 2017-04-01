#include <stdio.h>

int main()
{
	const int MAX_LINE = 100;
	char line[MAX_LINE];

	int N;
	fgets(line, MAX_LINE, stdin);
	sscanf(line, "%d", &N);

	for (int i = 0; i < N; ++i)
	{
		fgets(line, MAX_LINE, stdin);

		int X1;
		sscanf(line, "%d", &X1);
		//printf("X1 = %d\n", X1);

		int b1 = 0;
		for (int j = 0; j < 16; ++j)
		{
			if (X1 & 1)
			{
				++b1;
			}

			X1 >>= 1;
		}

		int X2;
		sscanf(line, "%x", &X2);

		int b2 = 0;
		for (int j = 0; j < 16; ++j)
		{
			if (X2 & 1)
			{
				++b2;
			}

			X2 >>= 1;
		}

		printf("%d %d\n", b1, b2);
	}

	return 0;
}
