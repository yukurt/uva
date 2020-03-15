#include <iostream>
#include <cstdio>
#include <vector>

bool g_debug = false;

using lock_num_t = int;
using test_case_t = std::vector<lock_num_t>;
using test_cases_t = std::vector<test_case_t>;

class DegreesComputer
{
public:
	DegreesComputer(bool db = false);
	void setTestCase(test_case_t const& tc);
	int  getDegrees() const;

private:
	void computeDegrees();
	int  computeOffset1();
	int  computeOffset2();
	int  computeOffset3();

	lock_num_t num0 = 0, num1 = 0, num2 = 0, num3 = 0;
	int degrees = 0;
	bool debug = false;
};

DegreesComputer::DegreesComputer(bool db)
	: debug(db)
{}

void DegreesComputer::setTestCase(test_case_t const& tc)
{
	num0 = tc[0];
	num1 = tc[1];
	num2 = tc[2];
	num3 = tc[3];

	computeDegrees();
}

int DegreesComputer::getDegrees()const
{
	return degrees;
}

void DegreesComputer::computeDegrees()
{
	int offset1 = computeOffset1();
	int offset2 = computeOffset2();
	int offset3 = computeOffset3();

	degrees = (120 + offset1 + offset2 + offset3) * 9;
}

int DegreesComputer::computeOffset1()
{
	int result = 0;

	if (num0 < num1)
	{
		result = 40 + num0 - num1;
	}
	else
	{
		result = num0 - num1;
	}

	if (debug)
	{
		printf("num0=%d num1=%d offset1=%d\n", num0, num1, result);
	}

	return result;
}

int DegreesComputer::computeOffset2()
{
	int result = 0;

	if (num1 <= num2)
	{
		result = num2 - num1;
	}
	else
	{
		result = 40 + num2 - num1;
	}

	if (debug)
	{
		printf("num1=%d num2=%d offset2=%d\n", num1, num2, result);
	}

	return result;
}

int DegreesComputer::computeOffset3()
{
	int result = 0;

	if (num2 < num3)
	{
		result = 40 + num2 - num3;
	}
	else
	{
		result = num2 - num3;
	}

	if (debug)
	{
		printf("num2=%d num3=%d offset3=%d\n", num2, num3, result);
	}

	return result;
}

void fill_test_cases(test_cases_t& test_cases)
{
	lock_num_t num0 = 0, num1 = 0, num2 = 0, num3 = 0;

	while (true)
	{
		std::cin >> num0;
		std::cin >> num1;
		std::cin >> num2;
		std::cin >> num3;

		if (num0 == 0 && num1 == 0 && num2 == 0 && num3 == 0)
		{
			break;
		}

		test_cases.push_back({num0, num1, num2, num3});
	}
}

int main()
{
	test_cases_t test_cases;
	fill_test_cases(test_cases);

	DegreesComputer computer {g_debug};
	for (auto const& tc: test_cases)
	{
		computer.setTestCase(tc);
		std::cout << computer.getDegrees() << std::endl;
	}

	return 0;
}
