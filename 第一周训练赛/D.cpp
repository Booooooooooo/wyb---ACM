#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	int n,num[105],i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
		}
		sort(num,num+n);
		printf("%d ",num[n-1]);
		for(i=1;i<n-1;i++)
		printf("%d ",num[i]);
		printf("%d ",num[0]);
		
	}
	return 0;
}
