#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct cow{
	int start;
	int end;
	int length;
}a[25005];

bool cmp(cow a,cow b)
{
	if(a.start<b.start)
	return true;
	else return false;
}

int main()
{
	int n,t;
	while (scanf("%d%d",&n,&t)!=EOF)
	{
		int i,time,cnt1,cnt2,j,maxi,max,flag=1;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].start,&a[i].end);
		}
		sort(a,a+n,cmp);
		if(a[0].start!=1)
		{
			printf("-1\n");
		}
		else
		{
			time = a[0].end;
			cnt1=1;
			for(j=1;j<n/2-1;)
			{
				maxi = j;
				max =0;
				for(i=j;i<n/2;i++)
				{
				
					if(a[i].start<=time&&a[i].end>time)
					{
						if((a[i].end-time)>max)
						max=a[i].end-time;
						maxi =i;
					}	
			 	} 
			 	if(max==0)
			 	{
			 		printf("-1\n");
			 		flag =0;
			 		break;
				 }
				j=maxi;
				cnt1++;
			}
			if(flag)
			{
				time = a[n/2].end;
			cnt2=1;
			for(j=n/2;j<n-1;)
			{
				maxi = j;
				max =0;
				for(i=j;i<n;i++)
				{
				
					if(a[i].start<=time&&a[i].end>time)
					{
						if((a[i].end-time)>max)
						max=a[i].end-time;
						maxi =i;
					}	
			 	} 
			 	if(max==0)
			 	{
			 		printf("-1\n");
			 		flag =0;
			 		break;
				 }
				j=maxi;
				cnt2++;
			}
			if(a[maxi].end!=t)
			{
				printf("-1\n");
				flag =0;
				}	
			}
			int cnt=cnt1+cnt2;
			if(flag)
			{
				printf("%d\n",cnt);
			}
		}
		
	}
	return 0;
}
