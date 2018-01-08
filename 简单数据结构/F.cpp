#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int n,m;
struct c{
	int x;
	int y;
}com[1005];
int par[1005],rank[1005];


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
	{
		return x;
	}
	else 
	{
		return par[x]=find(par[x]);
	}
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return ;
	
	if(rank[x]<rank[y])
	{
		par[x]=y;
	}
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
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i,flag=0,p;
		int work[1005]={0};
		char op;
		for(i=1;i<n+1;i++)
		{
			scanf("%d%d",&com[i].x,&com[i].y);
		}
		init(n);
		while(scanf("\n%c",&op)!=EOF)
		{
			
			if(op=='O')
			{
				scanf("%d",&p);
				for(i=1;i<n+1;i++)
				{
					work[p]=1;
					int d=(com[i].x-com[p].x)*(com[i].x-com[p].x)+(com[i].y-com[p].y)*(com[i].y-com[p].y);
					//d=sqrt(d); 
					if(d<=m*m&&work[i]&&i!=p)
					{
						unite(i,p);
					}
				}
			}
			if(op=='S')
			{
				int j,k;
				scanf("%d%d",&j,&k);
				if(same(j,k))
				{
					printf("SUCCESS\n");
				}
				else
				printf("FAIL\n");
			}
		}
	}
	return 0;
 } 
