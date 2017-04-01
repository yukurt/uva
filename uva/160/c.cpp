#include <stdio.h>
#include <set>
#include <vector>
#include <map>

/*
      2      3      5      7     11     13     17     19     23     29
     31     37     41     43     47     53     59     61     67     71
     73     79     83     89     97
*/

int main()
{
	std::set<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	std::map<int, int> prime_counts;
	std::set<int> Ns_unique;
	std::vector<int> Ns_order;
	std::map<int, std::vector<int> > prime_counts_per_N;

	while (true)
	{
		int N;
		scanf("%d", &N);

		if (!N)
		{
			break;
		}

		Ns_unique.insert(N);
		Ns_order.push_back(N);
	}

	for (auto i: primes)
	{
		prime_counts[i] = 0;
	}

	for (int i = 2; i <= 100; ++i)
	{
		int n = i;
		while (true)
		{
			if (primes.find(n) != primes.end())
			{
				prime_counts[n]++;
				break;
			}

			for (auto j: primes)
			{
				if (!(n % j))
				{
					prime_counts[j]++;
					n /= j;
					break;
				}
			}
		}

		if(Ns_unique.find(i) != Ns_unique.end())
		{
			for (auto j: primes)
			{
				if (j > i)
				{
					break;
				}

				prime_counts_per_N[i].push_back(prime_counts[j]);
			}
		}
	}

	for (auto i: Ns_order)
	{
		printf("%3d! =", i);

		int vlen = prime_counts_per_N[i].size();
		for (int j = 1; j <= 15 && j <= vlen; ++j)
		{
			printf("%3d", prime_counts_per_N[i][j-1]);
		}
		printf("\n");

		if (vlen <= 15)
		{
			continue;
		}

		printf("      ");
		for (int j = 16; j <= vlen; ++j)
		{
			printf("%3d", prime_counts_per_N[i][j-1]);
		}
		printf("\n");
	}

	return 0;
}


