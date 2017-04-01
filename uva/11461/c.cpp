#include <cstdio>
#include <cmath>

int main()
{
	while (true)
	{
		unsigned int a, b;

		scanf("%d %d", &a, &b);

		if (!a)
		{
			break;
		}

//		printf("a=%u b=%u\n", a, b);

		double root_a = sqrt(a);
		unsigned int min_root = root_a;

		if (double(root_a - min_root) > 0.00001)
		{
			min_root += 1;
		}

//		printf("min_root=%u\n", min_root);

		double root_b = sqrt(b);
		unsigned int max_root = root_b;

//		printf("max_root=%u\n", max_root);

		unsigned int num_root;

		if (min_root > max_root)
		{
			num_root = 0;
		}
		else
		{
			num_root = max_root - min_root + 1;
		}

		printf("%u\n", num_root);
	}

	return 0;
}
