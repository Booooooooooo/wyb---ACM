#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cmath> 
using namespace std;
int n,k;
double l[10005];
bool c(double x)
{
	int num=0;
	for(int i=0;i<n;i++)
	{
		num+=(int)(l[i]/x);
	}
	return num>=k;
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		double st=0,ed=10000000;
		for(int i=0;i<n;i++)
		cin>>l[i];
		for(int i=0;i<100;i++)
		{
			double mid =(st+ed)/2;
			if(c(mid))st=mid;
			else ed=mid;
		}
		printf("%.2f\n",floor(ed*100)/100);
	}
	return 0;
}
