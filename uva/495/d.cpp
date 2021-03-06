#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

void add_backend(const std::string& shorter, const std::string& longer, std::string& result)
{
	int ssize = shorter.size();
	int lsize = longer.size();
	int carry = 0;
	result.clear();

	for (int i = 0; i < ssize; ++i)
	{
		int si = shorter.at(i) - 48;
		int li = longer.at(i) - 48;

		int sum = si + li + carry;

		int ri = sum % 10;
		result += (ri + 48);

		carry = sum > 9 ? 1 : 0;
	}

	for (int i = ssize; i < lsize; ++i)
	{
		int li = longer.at(i) - 48;

		int sum = li + carry;

		int ri = sum % 10;
		result += (ri + 48);

		carry = sum > 9 ? 1 : 0;
	}

	if (carry)
	{
		result += '1';
	}
}

void add(const std::string& a, const std::string& b, std::string& result)
{
	int asize = a.size();
	int bsize = b.size();

	if (asize < bsize)
	{
		add_backend(a, b, result);
	}
	else
	{
		add_backend(b, a, result);
	}
}

int main()
{
	const int FMAX = 5010;
	std::string F[FMAX];

	F[0] = "0";
	F[1] = "1";

	for (int i = 2; i < FMAX; ++i)
	{
		add_backend(F[i-2], F[i-1], F[i]);
	}

	for (int i = 0; i < FMAX; ++i)
	{
		std::string num(F[i].rbegin(), F[i].rend());
		printf("\tF[%d] = \"%s\";\n", i, num.c_str());
	}

/*
	int i;
	while (scanf("%d", &i) != EOF)
	{
		std::string num(F[i].rbegin(), F[i].rend());
		std::cout << "The Fibonacci number for " << i  << " is " << num << std::endl; 
	}

	std::string F[100];
	F[0] = "0";
	F[1] = "1";
	F[2] = "1";
	F[3] = "13";

	const char* F[100];
	F[0] = "Hello";
	F[1] = "Hi";
	F[2] = "There";

	printf("B%sE\n", F[1]);
*/

	return 0;
}
