#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct cow{
	int start;
	int end;
	int length;
};
bool cmp(cow a,cow b)
{
	if(a.start<a.start)
	return true;
	else return false;
}
/*
int solve(int &i,int n,struct cow a[])
{
	int j,k=i;
	for(;k<n;k++)
	{
		if(a[k].start<a[i].end)
		{
			int max=a[k].length;
			int maxj=i;
			for(j=i+1;j<n;j++)
			{
				if(a[j].length>max)
				max=a[j].length;
				maxj =j;
			}
		}
	}
	if(a[i+1].start>a[i].end)
	return -1;
	
	i=j;
	return 1;
}
*/
int solve(int i,int end,)
 {
 	int max = 
	 /*int min=i;
	for(j=i+1;j<n;j++)
 	{
 		if((a[i].end-a[j].start)<(a[i].end-a[min].start)&&(a[j].start-a[i].end)<=0)
 		min=j;
	 }*/
	 
 	
 }
int main()
{
	int n,t;
	struct cow a[25005];
	while (scanf("%d%d",&n,&t)!=EOF)
	{
		int flag =0,cnt=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].start,&a[i].end);
			a[i].length=a[i].end-a[i].start;
		}
		sort(a,a+n,cmp);
		if(a[0].start!=1)
		flag =0;
		else 
		{
			for(i=0;a[i].end==t;)
			{
				a[i]
			}
			/*
			int b=1;
			for(int i=0;;)
			{
				if(a[i].end==t)
				{
					flag =1;
					break;
				}
				else 
				{
					b=solve(i,n,a);
					cnt+=b;
				}
			}*/
			
		}
		if(flag)
		printf("%d\n",cnt);
		else 
		printf("-1\n");
		
	 } 
	return 0;
}
