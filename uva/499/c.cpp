#include <stdio.h>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

int main()
{
	const int MAX_LINE = 1000;
	char line[MAX_LINE];

	while (fgets(line, MAX_LINE, stdin))
	{
		std::map<char, int> c2i;

		for (int i = 0; line[i]; ++i)
		{
			char c = line[i];

			if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
			{
				++c2i[c];
			}
		}

		if (!c2i.size())
		{
			continue;
		}

/*
		for (auto i: c2i)
		{
			printf("KurtDebug: %c: %d\n", i.first, i.second);
		}
*/
		std::map<int, std::vector<char> > i2v;
		for (auto i: c2i)
		{
			i2v[i.second].push_back(i.first);
		}

		auto i = i2v.rbegin();
		std::ostream_iterator<char> out_it(std::cout, "");
		std::copy(i->second.begin(), i->second.end(), out_it);
		printf(" %d\n", i->first);
	}

	return 0;
}
