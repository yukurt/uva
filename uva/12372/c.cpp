#include <string>
#include <iostream>
#include <regex>
#include <utility>

int main()
{
    int max_dimension = 20;
    
    std::string str;
    getline(std::cin, str);

    std::regex pattern("(\\d+)");
    std::smatch match;
    
    std::regex_search(str, match, pattern);
    int num_inputs = std::stoi(match[1]);

    pattern = "(\\d+)\\s+(\\d+)\\s+(\\d+)";
    for (int i = 1; i <= num_inputs; ++i)
    {
        getline(std::cin, str);
        std::regex_search(str, match, pattern);
        
        int L = std::stoi(match[1]);
        int W = std::stoi(match[2]);
        int H = std::stoi(match[3]);

        if (L > max_dimension || W > max_dimension || H > max_dimension)
        {
            std::cout << "Case " << i << ": bad" << std::endl;
        }
        else
        {
            std::cout << "Case " << i << ": good" << std::endl;
        }
    }
    
    return 0;
}
