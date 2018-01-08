#include<stdio.h>
int main()
{
	int c,i,j,k;
	int luck[21][1001],dp[21][1001];
	scanf("%d",&c);
	while (c--)
	{
		int n,m,max;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			scanf("%d",&luck[i][j]);
		}
		dp[0][0]=luck[0][0];
		/*for(i=1;i<n;i++)
		dp[i][0]=-999999;
		for(i=1;i<m;i++)
		dp[0][i]=-999999;*/
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(i==0&&j==0)
				continue;
				if(i-1>=0&&j-1>=0)
				{
					if(dp[i-1][j]>dp[i][j-1]) max=dp[i-1][j];
					else max=dp[i][j-1];
				}
				//	max=dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
				else if(i-1<0&&j-1>=0)
					max=dp[i][j-1];
				else if(j-1<0&&i-1>=0)
					max=dp[i-1][j];
				else max=dp[i][j];
				for(k=2;k<=m;k++)
				{
					if((j+1)/k==(double)(j+1)/k)
					{
						if(dp[i][(j+1)/k-1]>max) max=dp[i][(j+1)/k-1];
					}
					//max=dp[i][j/k]>max?dp[i][j/k]:max; 
				}
				dp[i][j]=max+luck[i][j];
			}
		}
		printf("%d\n",dp[n-1][m-1]);
		
	}
	return 0;
 } 
