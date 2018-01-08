#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n,q;
int a[100005];

void init()
{
	for(int i=1;i<n+1;i++)
	a[i]=0;
	return ;
}

long long sol()
{
	long long mul,sum=0;
	for(int c=1;c<=n;c++)
	{
		mul=a[c];
		for(int d=c;d<=n;d++)
		{
			mul*=a[d];
			sum+=mul;
			sum%=10007;
		}

	}
	return sum%10007;
}

int main()
{
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		init();
		for(int i=0;i<q;i++)
		{
			int j,k;
			scanf("%d%d",&j,&k);
			a[j]=k;
			printf("%lld\n",sol());
		}
	}
	return 0;
}
