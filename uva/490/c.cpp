#include <stdio.h>
#include <string.h>

int main()
{
	const int CSIZE = 110;

	char lines[CSIZE][CSIZE];
	char line[CSIZE];

	for (int i = 0; i < CSIZE; ++i)
	{
		for (int j = 0; j < CSIZE; ++j)
		{
			lines[i][j] = '\t';
		}
	}

	int num_lines = 0;
	int max_line_len = 0;

	for (; fgets(line, CSIZE, stdin); ++num_lines)
	{
		int len = strlen(line);

		int end = len - 1;
		if (line[end] == '\n')
		{
			line[end] = 0;
			--len;
		}

		if (len > max_line_len)
		{
			max_line_len = len;
		}

		strcpy(lines[num_lines], line);
	}

/*
	for (int i = 0; i < num_lines; ++i)
	{
		printf("B%sE\n", lines[i]);
	}
*/
	for (int i = 0; i < max_line_len; ++i)
	{
		for (int j = num_lines - 1; j >= 0; --j)
		{
			char c = lines[j][i];

			if (c == '\t' || c == 0)
			{
				printf(" ");
			}
			else
			{
				printf("%c", c);
			}
		}
		printf("\n");
	}

	return 0;
}
