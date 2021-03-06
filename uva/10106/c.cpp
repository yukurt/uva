#include <stdio.h>
#include <deque>
#include <string.h>
#include <utility>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
	const int MAX_INPUT_DIGITS = 300;

	while (true)
	{
		char X[MAX_INPUT_DIGITS];
		char Y[MAX_INPUT_DIGITS];

		if (scanf("%s", X) == EOF || scanf("%s", Y) == EOF)
		{
			break;
		}

//		printf("B%sE\n", X);
//		printf("C%sF\n", Y);

		if (strcmp(X, "0") == 0 || strcmp(Y, "0") == 0)
		{
			printf("0\n");
			continue;
		}

		int Xlen = strlen(X);
		int Ylen = strlen(Y);
		int max_addend_length = Xlen + Ylen;

		std::deque<std::deque<unsigned char> > addends;
		for (int i = Ylen - 1, k = 0; i >= 0; --i, ++k)
		{
			std::deque<unsigned char> deq;

			for (int j = 0; j < k; ++j)
			{
				deq.push_front(0);
			}

			int factor0 = Y[i] - 48;
			int carry = 0;

			for (int j = Xlen - 1; j >= 0; --j)
			{
				int factor1 = X[j] - 48;
				int product = factor0 * factor1 + carry;
				int mod = product % 10;
				carry = product / 10;
				deq.push_front(mod);
			}

			if (carry)
			{
				deq.push_front(carry);
			}

			int num_prefix_zeroes = max_addend_length - deq.size();
			for (int j = 0; j < num_prefix_zeroes; ++j)
			{
				deq.push_front(0);
			}

			addends.push_back(std::move(deq));
		}

//		for (const auto& i: addends)
//		{
//			std::ostream_iterator<int> out_it(std::cout, "");
//			std::copy(i.begin(), i.end(), out_it);
//			std::cout << std::endl;
//		}

		int num_addends = addends.size();
		std::deque<unsigned char> product;

		for (int i = max_addend_length - 1, carry = 0; i >= 0; --i)
		{
			int sum = carry;
			for (int j = 0; j < num_addends; ++j)
			{
				sum += addends[j][i];
			}

			int mod = sum % 10;
			carry = sum / 10;

			product.push_front(mod);
		}

		if (!product.front())
		{
			product.pop_front();
		}

		std::ostream_iterator<int> out_it(std::cout, "");
		std::copy(product.begin(), product.end(), out_it);
		std::cout << std::endl;
	}

	return 0;
}
