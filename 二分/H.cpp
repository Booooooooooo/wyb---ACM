#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,exp[100005];
/*bool find(double mid)
{
	int i,mon=0,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=exp[i];
		if(sum>mid)
		{
			mon++;
			sum=exp[i];
		}
	}
	if(mon>m)
	return true;
	else return false;
}*/
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,maxn=0,s=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&exp[i]);
			maxn=max(maxn,exp[i]);
			s+=exp[i];	
		}
		
		/*int max=exp[0];
		for(i=1;i<n;i++)
		{
			if(exp[i]>max)
			max=exp[i];
		}*/
		
		double st,ed;
		st=maxn;
		ed=s;
		while (ed-st>0)
		{
			double mid=st+(ed-st)/2;
			int i,mon=0,sum=0;
			for(i=0;i<n;i++)
			{
				sum+=exp[i];
				if(sum>mid)
				{
					mon++;
					sum=exp[i];
				}
			}	
		if(mon<m)
		ed=mid;
		else st=mid+1;
		}
		printf("%d\n",(int)st);
	}
	return 0;
}
