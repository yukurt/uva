#include <string>
#include <iostream>

int main()
{
    std::string str;

    while (getline(std::cin, str))
    {
        std::cout << str << std::endl;
    }
    
    return 0;
}
