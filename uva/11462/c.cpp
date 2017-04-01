#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

int main()
{
	while (true)
	{
		int n;
		scanf("%d", &n);

		if (!n)
		{
			break;
		}

		std::vector<int> vec;

		for (int i = 0, j; i < n; ++i)
		{
			scanf("%d", &j);
			vec.push_back(j);
		}

		sort(vec.begin(), vec.end());

		std::ostream_iterator<int> out(std::cout, " ");
		std::copy(vec.begin(), vec.end() - 1, out);
		std::cout << *(vec.end() - 1) << std::endl;
	}

	return 0;
}