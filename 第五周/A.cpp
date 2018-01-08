#include<stdio.h>
#include<iostream>

using namespace std;
int k,d;
int main()
{
	while(scanf("%d%d",&k,&d)!=EOF)
	{
		int i;
		if(k!=1&&d==0)
		printf("No solution\n");
		else
		{
			printf("%d",d);
			for(i=0;i<k-1;i++)
			{
				printf("0");
			}
			printf("\n");
		}
		
	}
	return 0;
}
