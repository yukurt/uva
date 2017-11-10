#include <string>
#include <iostream>
#include <regex>
#include <utility>
#include <algorithm>

bool IsPrime( int number );

int main()
{
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

		if (IsPrime(N))
		{
			if (N == NR)
			{
				std::cout << N << " is prime." << std::endl;
			}
			else
			{
				if (IsPrime(NR))
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

bool IsPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

