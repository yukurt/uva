//============================================================================
// Name        : 10474.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <iterator>

void processTestCase(int testCaseNum, int N, int Q) {
	std::multiset<int> mset;
	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;
		mset.insert(x);
	}
	std::cout << "CASE# " << testCaseNum << ":\n";
	for (int i = 0; i < Q; ++i) {
		int x;
		std::cin >> x;
		auto it = mset.find(x);
		if (it != mset.end()) {
			auto y = std::distance(mset.begin(), it) + 1;
			std::cout << x << " found at " << y << std::endl;
		} else {
			std::cout << x << " not found" << std::endl;
		}
	}
}

int main()
{
	for (int testCaseNum = 1; true; ++testCaseNum)
	{
		int N, Q;
		std::cin >> N >> Q;
		//std::cout << "N=" << N << " Q=" << Q << std::endl;

		if (!N && !Q)
		{
			//std::cout << "ending" << std::endl;
			break;
		}

		processTestCase(testCaseNum, N, Q);
	}

	return 0;
}
