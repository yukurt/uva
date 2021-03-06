#include <map>
#include <stdio.h>

int main()
{
	const int MAXLINE = 1000;
	char line[MAXLINE];

	std::map<char, char> m;

	m['`'] = ' ';
	m['1'] = ' ';
	m['q'] = ' ';
	m['w'] = ' ';
	m['a'] = ' ';
	m['s'] = ' ';
	m['z'] = ' ';
	m['x'] = ' ';

	m['2'] = '`';
	m['3'] = '1';
	m['4'] = '2';
	m['5'] = '3';
	m['6'] = '4';
	m['7'] = '5';
	m['8'] = '6';
	m['9'] = '7';
	m['0'] = '8';
	m['-'] = '9';
	m['='] = '0';

	m['@'] = '`';
	m['#'] = '1';
	m['$'] = '2';
	m['%'] = '3';
	m['^'] = '4';
	m['&'] = '5';
	m['*'] = '6';
	m['('] = '7';
	m[')'] = '8';
	m['_'] = '9';
	m['+'] = '0';

	m['e'] = 'q';
	m['r'] = 'w';
	m['t'] = 'e';
	m['y'] = 'r';
	m['u'] = 't';
	m['i'] = 'y';
	m['o'] = 'u';
	m['p'] = 'i';
	m['['] = 'o';
	m[']'] = 'p';
	m['\\'] = '[';
	m['{'] = 'o';
	m['}'] = 'p';
	m['|'] = '[';

	m['d'] = 'a';
	m['f'] = 's';
	m['g'] = 'd';
	m['h'] = 'f';
	m['j'] = 'g';
	m['k'] = 'h';
	m['l'] = 'j';
	m[';'] = 'k';
	m['\''] = 'l';
	m[':'] = 'k';
	m['"'] = 'l';

	m['c'] = 'z';
	m['v'] = 'x';
	m['b'] = 'c';
	m['n'] = 'v';
	m['m'] = 'b';
	m[','] = 'n';
	m['.'] = 'm';
	m['/'] = ',';
	m['<'] = 'n';
	m['>'] = 'm';
	m['?'] = ',';

	while (gets(line))
	{
		for (int i = 0; true; ++i)
		{
			char c = line[i];

			if (!c)
			{
				break;
			}

			if (c == ' ' || c == '\t' || c == '\n')
			{
				continue;
			}

			if ('A' <= c && c <= 'Z')
			{
				c += 32;
			}

			line[i] = m[c];
		}

		printf("%s\n", line);

		break;
	}

	return 0;
}
