#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int t,n;
int f[30000005];
 
void solve()
{
	for(int c=1;c<=30000005/2;++c)
	{
		for(int a=2*c;a<=30000005;a+=c)
		{
			int b=a-c;
			if((a^b)==c)
			f[a]++;
		}
	}
	for(int i=3;i<=30000005;i++)
	f[i]+=f[i-1];
}

int main()
{
	solve(); 
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
	//	memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		
		printf("Case %d: %d\n",i,f[n]);
	}
	return 0;
}
