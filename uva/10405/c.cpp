#include <stdio.h>
#include <deque>
#include <string.h>

int main() {
	const int MAX_LINE = 1010;
	int LLCS[MAX_LINE][MAX_LINE];

	char fword[MAX_LINE];
	char sword[MAX_LINE];
	char line[MAX_LINE];

	while (true)
	{
/*
		if (!fgets(line, MAX_LINE, stdin))
		{
			break;
		}
		sscanf(line, "%s", fword);
//		printf("1st: %sEEE: %d\n", fword, strlen(fword));

		if (!fgets(line, MAX_LINE, stdin))
		{
			break;
		}
		sscanf(line, "%s", sword);
//		printf("2nd: %sEEE: %d\n", sword, strlen(sword));
*/

		if (!gets(fword))
		{
			break;
		}

		if (!gets(sword))
		{
			break;
		}

		std::deque<char> fword_deq;
		for (int i = 0; true; ++i)
		{
			char c = fword[i];

			if (!c)
			{
				break;
			}

			fword_deq.push_back(c);
		}

		std::deque<char> sword_deq;
		for (int i = 0; true; ++i)
		{
			char c = sword[i];

			if (!c)
			{
				break;
			}

			sword_deq.push_back(c);
		}

		int fword_size = fword_deq.size();
		int sword_size = sword_deq.size();

/*
		if (fword_size == 0 || sword_size == 0)
		{
			printf("0\n");
			continue;
		}
*/
		for (int i = 0; i <= fword_size; ++i)
		{
			LLCS[i][0] = 0;
		}

		for (int j = 0; j <= sword_size; ++j)
		{
			LLCS[0][j] = 0;
		}

		fword_deq.push_front('0');
		sword_deq.push_front('0');

		for (int i = 1; i <= fword_size; ++i)
		{
			for (int j = 1; j <= sword_size; ++j)
			{
				if (fword_deq[i] == sword_deq[j])
				{
					LLCS[i][j] = LLCS[i - 1][j - 1] + 1;
				}
				else
				{
					int v = LLCS[i - 1][j];
					int h = LLCS[i][j - 1];

					LLCS[i][j] = v > h ? v : h;
				}
			}
		}

		printf("%d\n", LLCS[fword_size][sword_size]);
	}

	return 0;
}
