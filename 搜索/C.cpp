#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>

using namespace std;
int n,sum,flag;
int c[15];
int vis[15],num[15];
int cn(int k,int ni)
{
	int i=1,an=1;
	while(i<=k)
	{
		an*=ni/i;
		ni--;
		i++;
	}
	return an;
}

void dfs(int d,int val)
{
	int i;
	if(val>sum)return ;
	if(d==n)
	{
		if(!flag&&val==sum)
		{
			flag=1;
			for(i=0;i<n;i++)
				printf("%d ",num[i]);
			printf("\n");
			return ;
		}
		
	}
	for(i=1;i<=n&&!flag;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			num[d]=i;
			dfs(d+1,val+c[d]*i);
			vis[i]=0;
		}//ÕÒµ½È«ÅÅÁÐ 
	}
	
}
int main()
{
	while(scanf("%d%d",&n,&sum)!=EOF)
	{
		int i;
		flag=0;
		for(i=0;i<n;i++)
		{
			c[i]=cn(i,n-1);
		}
		memset(vis,0,sizeof(vis));
		//sum=0Cn-1*num[0]+1Cn-1*num[1]......
		dfs(0,0);
	}
	return 0;
}
