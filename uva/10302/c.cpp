#include <stdio.h>

int main()
{
	int x;
	unsigned long long s;

	while (scanf("%d", &x) != EOF)
	{
		s = x;
		++s;
		s *= x;
		s >>= 1;
		s *= s;

/*
		if (x & 1)
		{
			s = (x + 1) >> 1;
			s *= x;
			s *= s;
		}
		else
		{
			s = x >> 1;
			s *= (x + 1);
			s *= s;
		}
*/

		printf("%llu\n", s);
	}

	return 0;
}
