#include <string>
#include <iostream>
#include <regex>
#include <utility>

int main()
{
    std::string str;
    getline(std::cin, str);

    std::regex pattern("(\\d+)");
    std::smatch match;
    
    std::regex_search(str, match, pattern);
    int num_inputs = std::stoi(match[1]);

    pattern = "([a-z]+)";
    for (int i = 0; i < num_inputs; ++i)
    {
        getline(std::cin, str);
        std::regex_search(str, match, pattern);
        std::string input = match[1];

        if (input.size() == 5)
        {
            std::cout << "3" << std::endl;
        }
        else
        {
            int num_match = (input[0] == 'o') + (input[1] == 'n') + (input[2] == 'e');
            
            if (num_match >= 2)
            {
                std::cout << "1" << std::endl;
            }
            else
            {
                std::cout << "2" << std::endl;
            }
        }
    }
    
    return 0;
}
