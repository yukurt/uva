#include <stdio.h>

int main()
{
	long long int A, L, B;

	for (int i = 1; true; ++i)
	{
		scanf("%lld %lld", &A, &L);

		if (A < 0)
		{
			break;
		}

		B = A;
		int num_terms = 1;

		for (; true; ++num_terms)
		{
			if (B == 1)
			{
				break;
			}

			if (B & 1)
			{
				B = 3 * B + 1;

				if (B > L)
				{
					break;
				}
			}
			else
			{
				B >>= 1;
			}
		}

		printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", i, A, L, num_terms);
	}

	return 0;
}
