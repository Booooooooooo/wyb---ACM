#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int n,k;
int par[50005],rank[50005];

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
	{
		return x;
	}
	else
	{
		return par[x]=find(par[x]);
	}
}

int pare(int x,int y)
{
	if(par[y]==x)
	{
		return x;
	}
	else 
	{
		return par[y]=pare(x,par[y]);
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
		if(rank[x]==rank[y])
		rank[x]++;
	}
}

bool same(int x,int y)
{
	return find(x)==find(y);
}
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		int fal=0;
		init(n);
		while(k--)
		{
			int d,x,y;
			scanf("%d%d%d",&d,&x,&y);
			if(d==1)//ÊÇÍ¬Àà 
			{
				if(x>n||y>n)
				fal++;
				else if(same(x,y))
				{
					fal++;
				}
				else
				{
					unite(x,y);
				}
			}
			if(d==2)//x³Ôy 
			{
				if(x>n||y>n)
				fal++;
				else if(x==y)
				fal++;
				else if(!same(x,y))
				fal++;
				else
				{
					if(pare(y,x)==y)
					fal++;
					else
				}
			}
		}
		printf("%d\n",fal);
	}
	return 0;
}
