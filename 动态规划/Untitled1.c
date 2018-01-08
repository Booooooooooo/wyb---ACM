#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

int data[10010];





int main()
{
	int n, N,i = 0;
	int fangyu = 0;
	int lastheight = 0;
	while(scanf("%d", &N) && N != 0)
	{
		int negativeCount = 0;
		for( i = 0; i < N; i++)
		{
			scanf("%d", &data[i]);
			if(data[i] < 0)
				negativeCount++;
		}
		if(negativeCount == N)
		{
			printf("0 %d %d\n", data[0], data[N-1]);
			continue;
		}

		int sum = 0;
		int start = 0, end = 0;
		int maxStart = 0, maxEnd = 0;
		int max = -1;
		for( i = 0; i < N; i++)
		{

			if(sum < 0)
			{
				sum = 0;
				start = i;
			}

			sum += data[i];

			if(sum > max)
			{
				max = sum;
				maxStart = start;
				maxEnd = i;
			}
		}
		printf("%d %d %d\n", max, data[maxStart], data[maxEnd]);

	}
}
