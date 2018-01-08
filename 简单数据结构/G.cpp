#include<stdio.h>
#include<iostream>
#include<algorithm>
#define N 100005

int k,a,b;
char t[N];
int x[N],y[N];
int par[2*N],rank[2*N];

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
	init(a*2);
	for(int i=0;i<b;i++)
	{
		char T=t[i];
		int X=x[i]-1,Y=y[i]-1;
		/*if(X<0||n<=X||Y<0||n<=Y)
		{
			ans++;
			continue;
		}*/
		if(T=='D')
		{
			//if(same(X,Y+n)||same(X,Y+2*n)
			//ans++;
			//else 
			//{
				unite(X,Y+a);
				unite(X+a,Y);
				//unite(X+a,Y+a);
			//}
		}
		else
		{
			if(same(X,Y))
			printf("In the same gang.\n");
			else if(same(X,Y+a)||a==2)
			{
				printf("In different gangs.\n");
				//unite(X,Y+n);//A³ÔB 
				//unite(X+n,Y+2*n);//B³ÔC 
				//unite(X+2*n,Y);//C³ÔA 
			}
			else 
			printf("Not sure yet.\n");
		}
	}
}

int main()
{
	scanf("%d",&k);
	while(k--)
	{
		int i;
		scanf("%d%d",&a,&b);
		for(i=0;i<b;i++)
		{
			
			scanf("\n%c%d%d",&t[i],&x[i],&y[i]);
		}
		solve();
	}
	return 0;
 }
