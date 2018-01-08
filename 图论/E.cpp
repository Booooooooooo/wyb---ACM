#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

struct edge{
	int x,y,d;
}es[50010];
int par[50005],ra[50005],x[50005],y[50005],d[50005];
int n,m,r,t;
int v,e;

bool cmp(edge a,edge b)
{
	return a.d<b.d;
}

void init()
{
	for(int i=0;i<=50005;i++)
	{
		par[i]=i;
		ra[i]=0;
	}
 } 
 
int find(int a)
{
	if(par[a]==a)
	return a;
	else
	return par[a]=find(par[a]);
}

void unite(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b) return ;
	
	if(ra[a]<ra[b])
	{
		par[a]=b;
	}
	else
	{
		par[b]=a;
		if(ra[a]==ra[b]) ra[a]++;
	}
}

bool same(int a,int b)
{
	return find(a)==find(b);
}

int kruskal()
{
	sort(es,es+e,cmp);
	//init();
	int res=0;
	for(int i=0;i<e;i++)
	{
		edge ed=es[i];
		if(!same(ed.x,ed.y))
		{
			unite(ed.x,ed.y);
			res+=ed.d;
		}
	}
	return res;
}

void solve()
{
	v=n+m;
	e=r;
	for(int i=0;i<r;i++)
	{
		es[i].x=x[i];
		es[i].y=10000+y[i];
		es[i].d=-d[i];
	//	es[i]=(edge){x[i],n+y[i],-d[i]};
	}
	printf("%lld\n",10000*(n+m)+kruskal());
	 
 } 

int main()
{
	scanf("%d",&t);
	init();
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&r);
		for(int i=0;i<r;i++)
		{
			scanf("%d%d%d",&x[i],&y[i],&d[i]);
		}
		solve();
	}
	
	return 0;
}
