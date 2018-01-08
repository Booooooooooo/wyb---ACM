#include<stdio.h>
int main()
{
	int c,cnt=1,i,j,re,ri;
	int num[100001],dp[2][100001],max[100001],maxi[100001];
	scanf("%d",&c);
	while (c--)
	{
		int n;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			dp[0][i]=num[i];
		}
		max[0]=dp[0][0];
		maxi[0]=0;
		for(i=0;i<n;i++)
		{
			if(dp[0][i]>max[0])
			{
				max[0]=dp[0][i];
				maxi[0]=i;
			}
			
		}
		for(i=0;i<n-1;i++)
		{
			dp[1][i]=dp[0][i]+num[i+1];
		}
		for(j=2;j<n;j++)
		{
			max[j]=dp[(j-1)&1][0];
			maxi[j]=0;
			for(i=1;i<n;i++)
			{
				if(dp[(j-1)&1][i]>max[j])
				{
					max[j]=dp[(j-1)&1][i];
					maxi[j]=i;
				}
			}
			for(i=0;i<n-j;i++)
			dp[j&1][i]=dp[(j-1)&1][i]+num[i+j];

		}
		re=max[0];
		ri=maxi[0];
		j=0;
		for(i=0;i<n;i++)
		{
			if(max[i]>re)
			{
				re=max[i];
				ri=maxi[i];
				j=i;
			}
		}
		
	
		printf("Case %d:\n",cnt++);
		printf("%d %d %d\n",re,ri+1,ri+j);
		
	}
	return 0;
 } 
