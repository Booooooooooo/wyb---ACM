#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,num[205],heap[205];
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		int i,j,x,k,cnt;
		x=n*n;
		for(i=0;i<2*n;i++)
		{
			scanf("%d",&num[i]);
			heap[i]=0;
		}
		for(i=0;i<2*n;i++)
		{
			k=1;
			cnt=0;
			if(heap[i]==0)
			{
				heap[i]=1;
				for(j=i+1;j<2*n;j++)
				{
					if(num[j]==num[i])
					{
						cnt++;
						heap[j]=k%2+1;
						k++;
					}
				}
				if(cnt%2)
				{
					x-=(cnt/2)*n;
				} 
				else
				{
					x-=(cnt/2-1)*n;
				}
				if(cnt==0)
				{
					
				}
			}
		}
		printf("%d\n",x);
		for(i=0;i<2*n;i++) 
		{
			printf("%d ",heap[i]);
		}
		printf("\n");
	}
	return 0;
 } 
