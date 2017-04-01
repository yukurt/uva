#include <vector>
#include <stdio.h>

int main()
{
	std::vector<bool> arr;

	for (int i = 0; i < 5; ++i)
	{
		arr.push_back(false);
	}

	arr[0] = true;

	return 0;
}
