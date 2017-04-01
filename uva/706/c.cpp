#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXROWS = 23;
const int MAXCOLS = 13 * 9;
char disp[MAXROWS][MAXCOLS];

void write_digit(int i, int s, char one_mid, char two_left, char two_right, char three_mid, char four_left, char four_right, char five_mid)
{
	int start = i * (s + 2 + 1);

	disp[0][start] = ' ';

	for (int i = 1; i <= s; ++i)
	{
		disp[0][start + i] = one_mid;
	}

	disp[0][start + s + 1] = ' ';

	for (int i = 1; i <= s; ++i)
	{
		disp[i][start] = two_left;

		for (int j = 1; j <= s; ++j)
		{
			disp[i][start + j] = ' ';
		}

		disp[i][start + s + 1] = two_right;
	}

	disp[s + 1][start] = ' ';

	for (int i = 1; i <= s; ++i)
	{
		disp[s + 1][start + i] = three_mid;
	}

	disp[s + 1][start + s + 1] = ' ';

	for (int i = 1; i <= s; ++i)
	{
		disp[s + i + 1][start] = four_left;

		for (int j = 1; j <= s; ++j)
		{
			disp[s + i + 1][start + j] = ' ';
		}

		disp[s + i + 1][start + s + 1] = four_right;
	}

	disp[s + s + 2][start] = ' ';

	for (int i = 1; i <= s; ++i)
	{
		disp[s + s + 2][start + i] = five_mid;
	}

	disp[s + s + 2][start + s + 1] = ' ';
}

void write_space(int i, int s)
{
	int start = i * (s + 2 + 1) + (s + 2);

	for (int i = 0; i < 2 * s + 3; ++i)
	{
		disp[i][start] = ' ';
	}
}

void write_null(int i, int s)
{
	int start = i * (s + 2 + 1) + (s + 2);

	for (int i = 0; i < 2 * s + 3; ++i)
	{
		disp[i][start] = 0;
	}
}

void write(int i, int s, char c)
{
	switch (c)
	{
		case '0': write_digit(i, s, '-', '|', '|', ' ', '|', '|', '-');  break;
		case '1': write_digit(i, s, ' ', ' ', '|', ' ', ' ', '|', ' ');  break;
		case '2': write_digit(i, s, '-', ' ', '|', '-', '|', ' ', '-');  break;
		case '3': write_digit(i, s, '-', ' ', '|', '-', ' ', '|', '-');  break;
		case '4': write_digit(i, s, ' ', '|', '|', '-', ' ', '|', ' ');  break;
		case '5': write_digit(i, s, '-', '|', ' ', '-', ' ', '|', '-');  break;
		case '6': write_digit(i, s, '-', '|', ' ', '-', '|', '|', '-');  break;
		case '7': write_digit(i, s, '-', ' ', '|', ' ', ' ', '|', ' ');  break;
		case '8': write_digit(i, s, '-', '|', '|', '-', '|', '|', '-');  break;
		case '9': write_digit(i, s, '-', '|', '|', '-', ' ', '|', '-');  break;
		case ' ': write_space(i, s); break;
		case  0 : write_null(i, s);  break;
		default: throw "Unknown character for printing";
	}
}

void print_num(int s)
{
	for (int i = 0; i < 2 * s + 3; ++i)
	{
		printf("%s\n", disp[i]);
	}
}

int main()
{
	static const int MAXLINE = 100;
	char* pch;
	char line[MAXLINE];
	int s;

	fgets(line, MAXLINE, stdin);

	pch = strtok(line, " \t\n");

	do
	{
		int s = atoi(pch);

		pch = strtok(NULL, " \t\n");

		int len = strlen(pch);

		memset(disp, 0, sizeof(disp[0][0]) * MAXROWS * MAXCOLS);

		for (int i = 0; i < len - 1; ++i)
		{
			write(i, s, pch[i]);
			write(i, s, ' ');
		}

		write(len - 1, s, pch[len - 1]);
		write(len - 1, s, 0);

		print_num(s);
		printf("\n");

		fgets(line, MAXLINE, stdin);

		pch = strtok(line, " \t\n");

		if (!strcmp(pch, "0"))
		{
			break;
		}
	} while (true);

	return 0;
}
