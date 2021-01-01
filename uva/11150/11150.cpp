//============================================================================
// Name        : 11150.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int N;
	while (cin >> N)
	{
		std::cout << ((N >> 1) * 3) + (N & 1) << "\n";
	}
	return 0;
}
