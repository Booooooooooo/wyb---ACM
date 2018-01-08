#include<stdio.h>
#include<iostream> 
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

int n,m,tot;
map <string,int> mp;//������תΪ���� 
vector <string> vs;
int vis[30];
int dp[30][30];  //��������ͨ��� ǰһ������һ����ͨ 

void init()
{
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));
	mp.clear();
	vs.clear();
	tot=0;
}

void input()
{
	while(m--)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(!mp.count(s1))
		{
			mp[s1]=tot++;
			vs.push_back(s1);
		}
		if(!mp.count(s2))
		{
			mp[s2]=tot++;
			vs.push_back(s2);
		}
		dp[mp[s1]][mp[s2]]=1;
	}
}

void floyd()
{
	for(int k=0;k<n;++k)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			dp[i][j]=(dp[i][j]||(dp[i][k]&&dp[k][j]));//����һ��k��һ��Ҳ������k 
		}
	}
}

void dfs(int u)//�����u��ͨ��ÿһ���� 
{
	vis[u]=1;
	for(int v=0;v<n;++v)
	{
		if(!vis[v]&&(dp[u][v]&&dp[v][u]))//�γ���һ��Ȧ 
		{
			cout<<", "<<vs[v];
			dfs(v);
		}
	}
}

int main()
{
	int cas=1;//��¼case 
	while(scanf("%d%d",&n,&m)&&(n&&m))
	{
		init();
		input();
		floyd();
		if(cas>1) cout<<endl;
		printf("Calling circles for data set %d:\n",cas++);
		for(int i=0;i<n;++i) 
		{
			if(!vis[i])
			{
				cout<<vs[i];
				dfs(i);
				cout<<endl;
			}
		}
	}
	return 0;
 } 
