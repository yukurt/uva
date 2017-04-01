#include <cstdio>

int main()
{
	unsigned int arr[3];

	while (true)
	{
		scanf("%u %u %u", &arr[0], &arr[1], &arr[2]);
		//printf("a=%u b=%u c=%uE\n", arr[0], arr[1], arr[2]);

		if (!arr[0])
		{
			break;
		}

		unsigned int max_ind = 0;
		unsigned int max = arr[0];

		if (arr[1] > max)
		{
			max_ind = 1;
			max = arr[1];
		}

		if (arr[2] > max)
		{
			max_ind = 2;
			max = arr[2];
		}

		if (max_ind != 2)
		{
			unsigned int tmp = arr[2];
			arr[2] = max;
			arr[max_ind] = tmp;
		}

		unsigned int left = (arr[0] * arr[0]) + (arr[1] * arr[1]);
		unsigned int right = arr[2] * arr[2];

		if (left == right)
		{
			printf("right\n");
		}
		else
		{
			printf("wrong\n");
		}
	}

	return 0;
}
