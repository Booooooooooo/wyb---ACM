#include<stdio.h>
#include<iostream>
#include<algorithm>
#define N 100005
using namespace std;

int n,k,ans;
int t[N],x[N],y[N];
int par[3*N],rank[3*N];

void init(int n)
{
	for(int i=0;i<n;i++)
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

void solve()
{
	init(n*3);
	ans=0;
	for(int i=0;i<k;i++)
	{
		int T=t[i];
		int X=x[i]-1,Y=y[i]-1;
		if(X<0||n<=X||Y<0||n<=Y)
		{
			ans++;
			continue;
		}
		if(T==1)
		{
			if(same(X,Y+n)||same(X,Y+2*n))
			ans++;
			else 
			{
				unite(X,Y);
				unite(X+n,Y+n);
				unite(X+2*n,Y+2*n);
			}
		}
		else
		{
			if(same(X,Y)||same(X,Y+2*n))
			ans++;
			else
			{
				unite(X,Y+n);//A³ÔB 
				unite(X+n,Y+2*n);//B³ÔC 
				unite(X+2*n,Y);//C³ÔA 
			}
		}
	}
}

int main()
{
	//while(scanf("%d%d",&n,&k)!=EOF)
	//{
		scanf("%d%d",&n,&k);
		for(int i=0;i<k;i++)
		scanf("%d%d%d",&t[i],&x[i],&y[i]);
		solve();
		printf("%d\n",ans);
//	}
	return 0;
 } 
