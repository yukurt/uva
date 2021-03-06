#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	const int ML = 1000;
	char line[ML];
	char code[ML];
	int count;
	char cnum[2];

	cnum[1] = 0;

	while (fgets(line, ML, stdin))
	{
		code[0] = 0;
		sscanf(line, "%s", code); 
		//printf("B%sE\n", code);

		if (code[0] == 0)
		{
			printf("\n");
			count = 0;
			continue;
		}

		int len = strlen(code);

		for (int i = 0; i < len; ++i)
		{
			char c = code[i];

			if ('0' <= c && c <= '9')
			{
				cnum[0] = c;
				count += atoi(cnum);
				continue;
			}

			if (c == '!')
			{
				printf("\n");
				continue;
			}

			if (c == 'b')
			{
				c = ' ';
			}

			for (int j = 0; j < count; ++j)
			{
				printf("%c", c);
			}

			count = 0;
		}

		printf("\n");
	}

	return 0;
}
