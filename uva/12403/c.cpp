#include <iostream>
#include <string>

int main()
{
	int num_ops;
	std::cin >> num_ops;

	std::string op;
	int amount;
	int total = 0;
	for (int i = 0; i < num_ops; ++i)
	{
		std::cin >> op;

		if (op[0] == 'd')
		{
			std::cin >> amount;
			total += amount;
		}
		else
		{
			std::cout << total << "\n";
		}
	}

	return 0;
}
