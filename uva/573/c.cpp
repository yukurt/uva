#include <stdio.h>

int main()
{
	while (true)
	{
		int H, U, D, F;
		scanf("%d %d %d %d", &H, &U, &D, &F);
//		printf("\nH=%d U=%d D=%d F=%d\n", H, U, D, F);

		if (!H)
		{
			break;
		}

		float height = 0;
		float advance = U;
		float fatigue = (F / 100.0) * U;

//		printf("fatigue = %f\n", fatigue);

		for (int day = 1; true; ++day)
		{
//			printf("day = %d\n", day);

			height += advance;
//			printf("height after advance = %f\n", height);
			if (height > H)
			{
				printf("success on day %d\n", day);
				break;
			}

			height -= D;
//			printf("height after slide = %f\n", height);
			if (height < 0)
			{
				printf("failure on day %d\n", day);
				break;
			}

			advance -= fatigue;
//			printf("next advance = %f\n", advance);
			if (advance < 0)
			{
				advance = 0;
			}
		}
	}

	return 0;
}
