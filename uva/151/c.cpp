#include <stdio.h>

int main()
{
	int arr[150];

	arr[ 13] =    1;
	arr[ 14] =   18;
	arr[ 15] =   10;
	arr[ 16] =   11;
	arr[ 17] =    7;
	arr[ 18] =   17;
	arr[ 19] =   11;
	arr[ 20] =   15;
	arr[ 21] =   29;
	arr[ 22] =    5;
	arr[ 23] =   21;
	arr[ 24] =   13;
	arr[ 25] =   26;
	arr[ 26] =   14;
	arr[ 27] =   11;
	arr[ 28] =   23;
	arr[ 29] =   22;
	arr[ 30] =    9;
	arr[ 31] =   73;
	arr[ 32] =   17;
	arr[ 33] =   42;
	arr[ 34] =    7;
	arr[ 35] =   98;
	arr[ 36] =   15;
	arr[ 37] =   61;
	arr[ 38] =   22;
	arr[ 39] =   84;
	arr[ 40] =   24;
	arr[ 41] =   30;
	arr[ 42] =    9;
	arr[ 43] =   38;
	arr[ 44] =   15;
	arr[ 45] =   54;
	arr[ 46] =   27;
	arr[ 47] =    9;
	arr[ 48] =   61;
	arr[ 49] =   38;
	arr[ 50] =   22;
	arr[ 51] =   19;
	arr[ 52] =  178;
	arr[ 53] =   38;
	arr[ 54] =   53;
	arr[ 55] =   79;
	arr[ 56] =   68;
	arr[ 57] =  166;
	arr[ 58] =   20;
	arr[ 59] =    9;
	arr[ 60] =   22;
	arr[ 61] =    7;
	arr[ 62] =   21;
	arr[ 63] =   72;
	arr[ 64] =  133;
	arr[ 65] =   41;
	arr[ 66] =   10;
	arr[ 67] =   82;
	arr[ 68] =   92;
	arr[ 69] =   64;
	arr[ 70] =  129;
	arr[ 71] =   86;
	arr[ 72] =   73;
	arr[ 73] =   67;
	arr[ 74] =   19;
	arr[ 75] =   66;
	arr[ 76] =  115;
	arr[ 77] =   52;
	arr[ 78] =   24;
	arr[ 79] =   22;
	arr[ 80] =  176;
	arr[ 81] =   10;
	arr[ 82] =   57;
	arr[ 83] =  137;
	arr[ 84] =  239;
	arr[ 85] =   41;
	arr[ 86] =   70;
	arr[ 87] =   60;
	arr[ 88] =  116;
	arr[ 89] =   81;
	arr[ 90] =   79;
	arr[ 91] =   55;
	arr[ 92] =  102;
	arr[ 93] =   49;
	arr[ 94] =    5;
	arr[ 95] =   22;
	arr[ 96] =   54;
	arr[ 97] =   52;
	arr[ 98] =  113;
	arr[ 99] =   15;
	arr[100] =   66;

	while (true)
	{
		int N;

		scanf("%d", &N);

		if (!N)
		{
			break;
		}

		printf("%d\n", arr[N]);
	}

	return 0;
}
