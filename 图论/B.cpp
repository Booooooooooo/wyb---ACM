//http://www.cnblogs.com/jackge/archive/2013/05/13/3075769.html 
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

//按边权值从小到达排序   并查集
// 
int n,m;
struct point{
	int a;
	int b;
	int w;
}p[5005];
//int mi,ma,re;//min记录某一种情况时最小的边，max记录最大的，re记录这时的结果
int re=999999999; 
int par[5005],rank[5005];

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
	if(x==y)return ;
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

bool cmp(point a,point b)
{
	return a.w<b.w;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int i;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].w);
		}
		sort(p,p+m,cmp);
		int flag=1;
		re=999999999;
		int f=0;
		for(i=0;i<m;i++)
		{
			if(flag==0)
			break;
			init(m);
			//mi=p[i].w;
			//ma=p[i].w;
			int cnt=0;
			int temp=999999999;
			for(int j=i;j<m;j++)
			{
				if(m-j<n-1) {
					flag=0;
					break;
				}//边太少无法生成树 
				point e=p[j];
				if(!same(e.a,e.b))
				{
					unite(e.a,e.b);
					cnt++;
					//if(e.w<mi)
					//mi=e.w;
					//if(e.w>ma)
					//ma=e.w;
				}
				if(cnt==n-1) temp=p[j].w-p[i].w;
			}
			
			re=min(re,temp);
		}
		if(re!=999999999)
		printf("%d\n",re);
		else 
		printf("-1\n");
	}
	return 0;
} 
