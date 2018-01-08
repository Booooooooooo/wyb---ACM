#include<stdio.h>
int main()
{
	int n[10005],k,dp[10005][10005];
	scanf("%d",&k);
	while (k)
	{
		int i,j;
		for(i=0;i<k;i++)
		{
			scanf("%d",&n[i]);
			dp[0][i]=n[i];
		}

		for(j=1;j<k;j++)
		{
			for(i=0;i<k-j;i++)
			{
				dp[j][i]=dp[j-1][i]+n[i+1];
			}
		}
		int max=dp[0][0],maxj=0,maxi=0;
		for(j=0;j<k;j++)
		{
			for(i=0;i<k-j;i++)
			{
				if(dp[j][i]>dp[0][0])
				{
			 	max=dp[j][i];
				maxj=j;
				maxi=i;
				}
			}
		}
		printf("%d %d %d",max,n[maxi],n[maxi+maxj]);
		scanf("%d",&k);
	}
	return 0;
 }
