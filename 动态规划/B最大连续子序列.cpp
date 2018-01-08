#include<stdio.h>
int main()
{
	int n[10001],k,dp[2][10001],max[10001],maxi[10001];
	scanf("%d",&k);
	while (k)
	{
		int i,j;
		for(i=0;i<k;i++)
		{
			scanf("%d",&n[i]); 
			dp[0][i]=n[i];
		}
		max[0]=n[0];
		maxi[0]=0;
		for(i=1;i<k;i++)
		{
			if(n[i]>max[0])
			max[0]=n[i];
			maxi[0]=i-1;
		}
		for(j=1;j<k;j++)//j行 
		{
			for(i=0;i<k-j;i++)
			{
				dp[j&1][i]=dp[!(j&1)][i]+n[i+j];
			}
			max[j]=dp[j&1][0];
			maxi[j]=0;
			for(i=1;i<k-j;i++)
			{
				if(dp[j&1][i]>max[j])
				{
					max[j]=dp[j&1][i];
					maxi[j]=i;// j行中最大的dp dp[i] 
				}
			}
		}
		int re=max[0],begin=maxi[0],end=0;//找到最大的max【】 
		for(j=0;j<k;j++)
		{
			if(max[j]>re)
			{
				re=max[j];
				begin=maxi[j];
				end=j;
			}
			if(max[j]==re)
			{
				if(maxi[j]<begin)
				begin=maxi[j];
				if(j<end)
				end=j;
			}
		}
		if(re<0)
		{
			re=0;
			begin=0;
			end=k-1;
		 } 
		printf("%d %d %d\n",re,n[begin],n[begin+end]);
		scanf("%d",&k);
	}
	return 0;
 } 
