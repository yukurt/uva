#include <algorithm>
#include <stdio.h>
#include <string.h>

int main()
{
	char code[50];

	while (scanf("%s", code) != EOF)
	{
		if (code[0] == '#')
		{
			break;
		}


		int len = strlen(code);

		if (std::next_permutation(code, code+len))
		{
			printf("%s\n", code);
		}
		else
		{
			printf("No Successor\n");
		}
	}

	return 0;
}
