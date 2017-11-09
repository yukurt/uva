
#include <string>
#include <iostream>
#include <regex>
#include <utility>

int main()
{
	std::regex pattern("(\\S+)");
    
	for (int i = 1; true; ++i)
	{
		std::string str;
		std::smatch match;

		getline(std::cin, str);
		std::regex_search(str, match, pattern);
		std::string entry = match[1];

		if (entry[0] == '*')
		{
			break;
		}

		if (entry[0] == 'H')
		{
			std::cout << "Case " << i << ": Hajj-e-Akbar" << std::endl;
		}
		else
		{
			std::cout << "Case " << i << ": Hajj-e-Asghar" << std::endl;
		}
	}
    
	return 0;
}
