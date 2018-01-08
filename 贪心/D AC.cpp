#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
	int t,peo[1005];
	scanf("%d",&t);
	while (t--)
	{
		int n,i;
		int time1=0,time2=0,time =0;
		int flag=1,p[1005]={0},cnt=0;
		printf("\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&peo[i]);
		}
		sort(peo,peo+n);
		while(1)
		{
			if(n==1)
			{
				time+= peo[0];
				break;
			}
			else if(n==2)
			{
				time+= peo[1];
				break;
			}
			else if(n==3)
			{
				time+=peo[0]+peo[1]+peo[2];
				break;
			}
			else 
			{
				if(2*peo[1]>(peo[0]+peo[n-2]))
				{
					time +=2*peo[0]+peo[n-1]+peo[n-2];
					n-=2;
				}
				else 
				{
					time+=2*peo[1]+peo[0]+peo[n-1];
					n-=2;
				 } 
			}
			
			
		 } 
		 printf("%d\n",time);
	}
} 
