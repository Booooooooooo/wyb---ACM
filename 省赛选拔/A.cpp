#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int n,m;
int par[50005],rank[50005];
bool yes[50005];

void init(int n)
{
	for(int i=1;i<n+1;i++)
	{
		par[i]=i;
		rank[i]=0;
	}
}

int find(int x)
{
	if(par[x]==x)
	return x;
	else 
	return par[x]=find(par[x]);
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return ;
	
	if(rank[x]<rank[y])
	par[x]=y;
	else 
	{
		par[y]=x;
		if(rank[x]==rank[y])rank[x]++;
	}
}

bool same(int x,int y)
{
	return find(x)==find(y);
}

int main()
{
	scanf("%d%d",&n,&m);
	int num=1;
	while(n!=0||m!=0)
	{
		int cnt=0;
		for(int i=1;i<n+1;i++)
		{
			yes[i]=0;
		}
		init(n);
		for(int i=0;i<m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			unite(a,b);
		}
		for(int i=1;i<n+1;i++)
		{
			int temp;
			temp=find(i);
			if(!yes[temp])
			{
				cnt++;
				yes[temp]=1;
			}
			else
			continue;
		}
		printf("Case %d: %d\n",num++,cnt);
		scanf("%d%d",&n,&m);
	}
	return 0;
}
