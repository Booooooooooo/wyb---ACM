#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct node{
	int x;
	int v;
};
struct node fri[60005];
bool cmp(node a,node b)
{
	if(a.x<b.x)
	return true;
	else return false;
}
bool find(double mid)
{
	int i;
	double x1=fri[0].x-mid*fri[0].v;
	double x2=fri[0].x+mid*fri[0].v;
	for(i=1;i<n;i++)
	{
		double temp1=fri[i].x-fri[i].v*mid;
		double temp2=fri[i].x+fri[i].v*mid;
		if(temp1>x1)
		x1=temp1;
		if(temp2<x2)
		x2=temp2;
		if(x1>x2)
		return false;
	}
	return true;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&fri[i].x);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&fri[i].v);
		}
		sort(fri,fri+n,cmp);
		double st,ed;
		st=0;
		ed=10000000000;
		while((ed-st)>0.000001)
		{
			double mid=st+(ed-st)/2;
			if(find(mid))
			ed=mid;
			else 
			st=mid;
		}
		printf("%.10f\n",ed);
		
	}
	return 0;
}
