#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

int main()
{
	const int MAX_SIZE = 1000;
	char line[MAX_SIZE];

	while (fgets(line, MAX_SIZE, stdin))
	{
		char* pch = strtok(line, " \t\n");

		// o = original; s = sorted, d = destructive
		std::vector<int> ovec, svec, dvec;

    		while (pch)
		{
			int x = atoi(pch);

			ovec.push_back(x);
			svec.push_back(x);
			dvec.push_back(x);

			pch = strtok(NULL, " \t\n");
		}

		std::sort(svec.begin(), svec.end());

		size_t vlen = svec.size();
		std::vector<int> flips;

		for (int i = vlen - 1; i >= 0; --i)
		{
			int scurr = svec[i];

			if (dvec[i] == scurr)
			{
				continue;
			}

			int j = i;
			for (; j >= 0; --j)
			{
				if (dvec[j] == scurr)
				{
					break;
				}
			}

			if (j)
			{
				std::reverse(dvec.begin(), dvec.begin() + j + 1);
				flips.push_back(vlen - j);
			}

			std::reverse(dvec.begin(), dvec.begin() + i + 1);
			flips.push_back(vlen - i);
		}

		std::ostream_iterator<int> out_it(std::cout, " ");
		std::copy(ovec.begin(), ovec.end() - 1, out_it);
		std::cout << *(ovec.end() - 1) << std::endl;

		std::copy(flips.begin(), flips.end(), out_it);
		std::cout << "0" << std::endl;
	}

	return 0;
}
