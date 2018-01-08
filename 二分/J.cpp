#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,an[50005];
struct cow{
	int w;
	int s;
	long long sum;
}a[50005];
bool cmp(cow a,cow b)
{
	return a.sum<b.sum;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].w,&a[i].s);
			a[i].sum=a[i].w+a[i].s;
		}
		sort(a,a+n,cmp);
		long long ans=0;
		an[0]=ans-a[0].s;
		for(i=1;i<n;i++)
		{
			ans+=a[i-1].w;
			an[i]=ans-a[i].s;
		}
		sort(an,an+n);
		printf("%I64d\n",an[n-1]);
		/*long long an=wei-sum[n-1];
		printf("%I64d\n",an);
		int st,ed,mid;
		st=0;
		ed=n-1;
		long long min;
		while(ed-st>1)
		{
			mid=st+(ed-st)/2;
			min=min(min,wei-w[i]-v[i]);
		}*/
	}
	return 0;
 } 
