#include <stdio.h>
#include <unordered_map>

int main()
{
	std::unordered_map<char, int> imap;

	imap['A'] = 2;
	imap['B'] = 2;
	imap['C'] = 2;

	imap['D'] = 3;
	imap['E'] = 3;
	imap['F'] = 3;

	imap['G'] = 4;
	imap['H'] = 4;
	imap['I'] = 4;

	imap['J'] = 5;
	imap['K'] = 5;
	imap['L'] = 5;

	imap['M'] = 6;
	imap['N'] = 6;
	imap['O'] = 6;

	imap['P'] = 7;
	imap['Q'] = 7;
	imap['R'] = 7;
	imap['S'] = 7;

	imap['T'] = 8;
	imap['U'] = 8;
	imap['V'] = 8;

	imap['W'] = 9;
	imap['X'] = 9;
	imap['Y'] = 9;
	imap['Z'] = 9;

	const int MAX_SIZE = 100;
	char line[MAX_SIZE];

	while (scanf("%s", line) != EOF)
	{
		//printf("B%sE\n", line);
		for (int i = 0; true; ++i)
		{
			char c = line[i];

			if (!line[i])
			{
				break;
			}

			auto search = imap.find(c);
			if (search != imap.end())
			{
				printf("%d", search->second);
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
