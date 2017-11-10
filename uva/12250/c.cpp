#include <string>
#include <iostream>
#include <regex>

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

		if (entry == "#")
		{
			break;
		}

		std::string language;
		if (entry == "HELLO")
		{
			language = "ENGLISH";
		}
		else if (entry == "HOLA")
		{
			language = "SPANISH";
		}
		else if (entry == "HALLO")
		{
			language = "GERMAN";
		}
		else if (entry == "BONJOUR")
		{
			language = "FRENCH";
		}
		else if (entry == "CIAO")
		{
			language = "ITALIAN";
		}
		else if (entry == "ZDRAVSTVUJTE")
		{
			language = "RUSSIAN";
		}
		else
		{
			language = "UNKNOWN";
		}

		std::cout << "Case " << i << ": " << language << std::endl;
	}
    
	return 0;
}
