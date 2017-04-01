#include <stdio.h>

class Prime
{
	int func()
	{
		int y = 0;

		for (int i = 0; i < 5; ++i)
		{
			++y;
		}

		return y;
	}
public:
	static const int x = func(); 
};

int main()
{
	Prime MyPrime;
	return 0;
}
