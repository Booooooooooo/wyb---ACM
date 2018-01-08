#include<stdio.h>
#include<iostream>
#include<algorithm>
#define INF 1000001
using namespace std;
int n,v[100005],w[100005],t;
struct an{
	double r;
	int k;
}m[100005];
bool cmp(an a,an b)
{
	return a.r>b.r;
}

bool find(double x)
{
	int i;
	for(i=0;i<n;i++)
	{
		m[i].r=v[i]-x*w[i];
		m[i].k=i+1;
	}
	sort(m,m+n,cmp);
	double sum=0;
	for(i=0;i<t;i++)
	{
		sum+=m[i].r;
	}
	return sum>=0;
}
int main()
{
	while (scanf("%d%d",&n,&t)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&v[i],&w[i]);
		}
		double st=0,ed=INF,mid;
		//while(ed-st>1e-8)
		for(i=0;i<50;i++)
		{
			mid=st+(ed-st)/2;
			if(find(mid))
			st=mid;
			else 
			ed=mid;
		}
		
		printf("%d",m[0].k);
		for(i=1;i<t;i++)
		{
			printf(" %d",m[i].k);
		}
		printf("\n");
	}
	return 0;
}
