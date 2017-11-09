#include <string>
#include <iostream>
#include <regex>
#include <utility>
#include <cmath>

int main()
{
	std::regex pattern("(-?\\d+)");
    
	for (int i = 1; true; ++i)
	{
		std::string str;
		std::smatch match;

		getline(std::cin, str);
		std::regex_search(str, match, pattern);
		int N = std::stoi(match[1]);

		if (N < 0)
		{
			break;
		}

		double a = log2(N);
		int b = static_cast<int>(a);

		if (a - static_cast<double>(b) < 0.00001)
		{
			std::cout << "Case " << i << ": " << b << std::endl;
		}
		else
		{
			std::cout << "Case " << i << ": " << b + 1 << std::endl;
		}
	}
    
	return 0;
}
