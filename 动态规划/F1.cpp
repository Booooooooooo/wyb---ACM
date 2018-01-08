#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,v,val[1005],vol[1005],i;
		int dp[2][1002];
		scanf("%d%d",&n,&v);
		for(i=0;i<n;i++)
		{
			scanf("%d",&val[i]);
			
		}
		for(i=0;i<n;i++)
		{
			
			scanf("%d",&vol[i]);
		}
		for(i=0;i<v+1;i++)
		{
			dp[1][i]=0;
			dp[0][i]=0;
		}
		int j;
		for(i=0;i<n;i++)
		{
			for(j=0;j<v+1;j++)
			{
				if(j<vol[i])	
				dp[1&(i+1)][j]= dp[1&i][j];
				else 
				dp[1&(i+1)][j] =max(dp[i&1][j],dp[i&1][j-vol[i]]+val[i]);
			}	
		}
		printf("%d\n",dp[1&n][v]);
	
		
	}
	return 0;
 } 
