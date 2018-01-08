#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int p,q,r,s;
long long c[10005][10005];

int main()
{
	for(int i=1;i<=10000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i/2;j++)
		{
			c[i][j]=c[i][j-1]*(i-j+1)/j;
		}
		for(int j=0;j<=i/2;j++)
		{
			c[i][i-j]=c[i][j];
		}
	}
	
	while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF)
	{
		double ans;
		ans=c[p][q]*1.0/c[r][s];
		//cout<<ans<<endl;
		printf("%.5f\n",ans);
	}
	return 0;
}
