#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		double y;
		cin>>y;
		double st=0,ed=100,mid;
		double re,a,b;
		a=8*pow(ed,4)+7*pow(ed,3)+2*ed*ed+3*ed+6;
		b=8*pow(st,4)+7*pow(st,3)+2*st*st+3*st+6;
		if(a<y||b>y)
		printf("No solution!\n");
		else 
		{
			while ((ed-st)>0.000001)
			{
			mid = st+(ed-st)/2;
			re=8*pow(mid,4)+7*pow(mid,3)+2*mid*mid+3*mid+6;
			if(re<y)
			st=mid;
			else if(re>y)
			ed=mid;
			}
		printf("%.4f\n",mid);
		}
	}
	return 0;
 } 
