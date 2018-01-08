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
		if(n==1)
		time =peo[0];
		else if(n==2)
		time =peo[1];
		else if(n==3)
		time =peo[0]+peo[1]+peo[2];
		else 
		{
			for(i=1;i<n;i++)
			{
				time1 += peo[i];//time1表示由最小的那个人 来回接送所有人 
				time1 += peo[0];
			}
			time1 -= peo[0];
			
			//time2表示 最小的两个先到对岸 每次对岸中最小的回来 这边最大的两个过去
			time2 +=peo[1]+peo[0];
			p[1]=1;
			cnt=1;
			while(cnt!=n-1)//cnt为对岸的人的个数 
			{
				for(i=n-1;i>=0;i--)
				{
					if(p[i]==0&&cnt!=n-1)
					{
						time2+=peo[i];
						p[i]=1;
						p[i-1]=1;
						break;
					}
					else if(p[i]==0)
					{
						time +=peo[i];
						p[i]=1;
						break;
					}
				}
				cnt++;
				for(i=1;i<n;i++)
				{
					if(p[i]==1&&cnt!=n-1)
					{
					time2 +=peo[i];
					p[i]=0;
					break;
					}
					else if(cnt==n-1)
					break;
				}
			}
			time =min(time1,time2);
		}
		/*for(i=1;i<n;i++)
		{
			time+=peo[i];
		}
		/*if(n%2)
		{
			for(i=1;i<n-1;i+2)
			time +=peo[i];
			time +=peo[n-1];
		}
		else 
		{
			for(i=1;i<n;i+=2)
			time +=peo[i];
		}
		*/
		
		printf("%d\n",time);
	
		
	}
	return 0;
 } 
