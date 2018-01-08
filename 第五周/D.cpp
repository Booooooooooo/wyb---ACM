#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int n,vis[200005],ans;
vector<int> va[200005];

void dfs(int x,int xfa)
{
	int temp=1;
	for(int i=0;i<va[x].size();i++)
	{
		int xson=va[x][i];
		if(!vis[xson])
		{
			while(vis[x]==temp||vis[xfa]==temp)temp++;
			vis[xson]=temp++;
			ans=max(ans,vis[xson]);
			dfs(xson,x);
		}
			
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		ans=1;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<200005;i++)
		va[i].clear();
		for(int i=1;i<n;i++)//i要从1开始 
		{
			int a,b;
			scanf("%d%d",&a,&b);
			va[a].push_back(b);
			va[b].push_back(a);
		}//创建连接 
		vis[1]=1;
		dfs(1,0);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		printf("%d ",vis[i]);
		printf("\n");
	}
	return 0;
 } 
