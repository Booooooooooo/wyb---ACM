#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct rat{
	int i;
	long long val;
}pre[300005];
int n;

bool cmp1(rat a,rat b)
{
	return a.val<b.val;
}

bool cmp2(rat a,rat b)
{
	return a.i<b.i;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&pre[j].val);
			pre[j].i=j;
		}
		sort(pre,pre+n,cmp1);
		long long r;
		r=pre[0].val;
		for(int j=1;j<n;j++)
		{
			if(r<pre[j].val)
			r=pre[j].val;
			else if(r>=pre[j].val)
			{
				pre[j].val=++r;
			}
		}
		sort(pre,pre+n,cmp2);
		printf("%lld",pre[0].val);
		for(int j=1;j<n;j++)
		printf(" %lld",pre[j].val);
		printf("\n");
	}
	return 0;
}
