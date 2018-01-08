#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n,t;
int book[100005];

int main()
{
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		for(int i=1;i<n+1;i++)
		{
			scanf("%d",&book[i]);
		}
		int st,ed,mid;
		long long time=0;
		st=1;
		ed=n;
		while(ed-st>1)
		{
			mid=st+(ed-st)/2;
			int i=mid;
			while(time<t&&i<=n)
			{
				time+=book[i];
				i++;
			}
			if(time>=t)
			{
				st=mid;
			}
			else 
			ed=mid;
		}
		printf("%d\n",n-st);
	}
	return 0;
}
