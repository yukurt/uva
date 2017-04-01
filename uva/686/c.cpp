#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
// void runEratosthenesSieve(int upperBound) {
      const int upperBound = (1 << 15) ;
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
//                  cout << m << " ";
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
//      for (int m = upperBoundSquareRoot; m <= upperBound; m++)
//            if (!isComposite[m])
//                  cout << m << " ";
//      delete [] isComposite;
//}

	while (true)
	{
		int n;
		scanf("%d", &n);

		if (!n)
		{
			break;
		}

		if (n == 4)
		{
			printf("1\n");
			continue;
		}

		int mid = n >> 1;
		int num_pairs = 0;

		for (int i = 3; i <= mid; i += 2)
		{
			if (!isComposite[i] and !isComposite[n-i])
			{
				++num_pairs;
			}
		}

		printf("%d\n", num_pairs);
	}

	return 0;
}
