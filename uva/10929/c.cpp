#include <stdio.h>
#include <string.h>

int main()
{
	char word[1500];

	while (true)
	{
		scanf("%s", word);
//		printf("B%sE\n", word);

		if (!strcmp(word, "0"))
		{
			break;
		}

		int sum = 0;

		for (int i = 0; true; ++i)
		{
			char c = word[i];

			if (!c)
			{
				break;
			}

			if (i & 1)
			{
				sum -= (c - 48);
			}
			else
			{
				sum += (c - 48);
			}
		}

//		printf("sum = %d\n", sum);

		if (sum % 11)
		{
			printf("%s is not a multiple of 11.\n", word);
		}
		else
		{
			printf("%s is a multiple of 11.\n", word);
		}
	}

	return 0;
}
