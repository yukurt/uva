#include <string>
#include <iostream>
#include <regex>
#include <utility>
#include <algorithm>

// Don't know why this does not compile in UVA
int main()
{
      const int upperBound = 1000000;
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }

	std::regex pattern("(\\d+)");
    
	std::string str;
	while (getline(std::cin, str))
	{		
		std::smatch match;
		std::regex_search(str, match, pattern);

		std::string num_string = match[1];
		int N = std::stoi(num_string);

		std::string reverse_num_string = num_string;
		std::reverse(reverse_num_string.begin(), reverse_num_string.end());
		int NR = std::stoi(reverse_num_string);		

		if (!isComposite[N])
		{
			if (N == NR)
			{
				std::cout << N << " is prime." << std::endl;
			}
			else
			{
				if (!isComposite[NR])
				{
					std::cout << N << " is emirp." << std::endl;
				}
				else
				{
					std::cout << N << " is prime." << std::endl;
				}
			}
		}
		else
		{
			std::cout << N << " is not prime." << std::endl;
		}
	}

	return 0;
}

