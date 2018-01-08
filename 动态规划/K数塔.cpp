#include<stdio.h>
int main()
{
	int c;
	scanf("%d",&c);
	while (c--)
	{
		int n,i,j,ta[105][105],dp[105][105];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			
			for(j=0;j<=i;j++)
			{
				scanf("%d",&ta[i][j]);	
			}
		}
		dp[0][0]=ta[0][0];
		dp[1][0]=ta[0][0]+ta[1][0];
		dp[1][1]=ta[0][0]+ta[1][1];
		for(i=2;i<n;i++)
		{
			dp[i][0]=dp[i-1][0]+ta[i][0];
			dp[i][i]=dp[i-1][i-1]+ta[i][i];
			for(j=1;j<i;j++)
			{
				if(dp[i-1][j-1]>dp[i-1][j])
				dp[i][j]=dp[i-1][j-1]+ta[i][j];
				else 
				dp[i][j]=dp[i-1][j]+ta[i][j];
			}
		}
		int max=dp[n-1][0];
		for(j=0;j<n;j++)
		{
			if(dp[n-1][j]>max)
			max=dp[n-1][j];
		}
		printf("%d\n",max);
		
		
	}
		
	return 0;
 } 
