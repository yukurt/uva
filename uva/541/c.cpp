#include <stdio.h>

int main()
{
	int arr[100][100];

	while (true)
	{
		int n;
		scanf("%d", &n);

		if (!n)
		{
			break;
		}

		int num_odd_rows = 0;
		int odd_row = 0;
		bool is_corrupt = false;

		for (int i = 1; i <= n; ++i)
		{
			int sum = 0;
			for (int j = 1; j <= n; ++j)
			{
				int x;
				scanf("%d", &x);
				arr[i][j] = x;
				sum += x;
			}

			if (sum & 1)
			{
				++num_odd_rows;
				odd_row = i;
			}

			if (num_odd_rows > 1)
			{
				is_corrupt = true;
			}
		}

		if (is_corrupt)
		{
			printf("Corrupt\n");
			continue;
		}

		int num_odd_cols = 0;
		int odd_col = 0;

		for (int i = 1; i <= n; ++i)
		{
			int sum = 0;
			for (int j = 1; j <= n; ++j)
			{
				sum += arr[j][i];
			}

			if (sum & 1)
			{
				++num_odd_cols;
				odd_col = i;
			}

			if (num_odd_cols > 1)
			{
				is_corrupt = true;	
				break;			
			}
		}

		if (is_corrupt)
		{
			printf("Corrupt\n");
			continue;
		}

		if (num_odd_rows || num_odd_cols)
		{
			printf("Change bit (%d,%d)\n", odd_row, odd_col);
			continue;
		}

		printf("OK\n");
/*
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("\n");
*/
	}

	return 0;
}
