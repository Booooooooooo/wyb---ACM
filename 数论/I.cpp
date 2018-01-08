#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

long long t,n;
bool vis[30000005];
 
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		memset(vis,0,sizeof(vis));
		long long a,b,c,cnt=0;
		scanf("%lld",&n);
		for(c=1;c<=n;c++)
		{
			for(int j=1;c*j<=n;j++)
			{
				a=c*j;
				b=c^a;
				//if(vis[b])
				//break;
				//else 
				{
					if(__gcd(a,b)==c&&b>=1&&b<=a)
					{
					 cnt++;
					//vis[b]=true;
					}
					//vis[b]=true;
				}
			}
		}
		
		printf("Case %lld:%lld\n",i,cnt);
	}
	return 0;
}
