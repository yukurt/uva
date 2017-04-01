#include <stdio.h>
#include <vector>

int main()
{
	for (int N = 13; N <= 100; ++N)
	{
		for (int m = 1; true; ++m)
		{
			bool arr[N+1];
			std::vector<int> vec;
			int j = 1;

			for (int i = 1; i <= N; ++i)
			{
				arr[i] = false;
			}

			for (int i = 1; i < N; ++i)
			{
				vec.push_back(j);
				arr[j] = true;

				for (int k = 1; k <= m;)
				{
					++j;

					if (j > N)
					{
						j = 1;
					}

					if (!arr[j])
					{
						++k;
					}
				}
			}

			vec.push_back(j);

			if (j == 13)
			{
				printf("\tarr[%3d] = %4d;\n", N, m);
				break;
			}
			continue;

			printf("%3d:", m);
			for (auto i : vec)
			{
				printf(" %3d", i);
			}
			printf("\n");
		}
	}

	return 0;
}
