#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m,ans=999999999;
struct graph{
	int u,v,wei;
}g[5005];
int par[5005];//,rank[5005];
void init(int n)
{
	for(int i=0;i<n+1;i++)
	{
		par[i]=i;
		//rank[i]=0;
	}
 } 

int find(int x)
{
	if(par[x]==x)
	return x;
	else
	return par[x]=find(par[x]);
}

/*void unite(int x,int y)
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
		if(rank[x]==rank[y]) rank[x]++;
	}
}
*/
bool same(int x,int y)
{
	return find(x)==find(y);
}

bool comp(graph a,graph b)
{
	return a.wei<b.wei;
}

void Kruskal(){
    sort(g,g+m,comp);
    for(int i=0;i<m;i++){
        init(n);
        int cnt=0,tmp=999999999;
        for(int j=i;j<m;j++){
            int fx=find(g[j].u);
            int fy=find(g[j].v);
            if(fx!=fy){
                par[fy]=fx;
                cnt++;
                if(cnt==n-1){
                    tmp=g[j].wei-g[i].wei;
                    break;
                }
            }
        }
        if(tmp<ans)
            ans=tmp;
    }
}

/*void kruskal()
{
	int temp=0;
	while(m-temp>=n-1)
	{
		sort(g+temp,g+m,comp);
		init(n);
		int mi=g[0].wei;
		int ma=0;
		for(int i=0;i<m;i++)
		{
			graph e=g[i];
			if(!same(e.u,e.v))
			{
				unite(e.u,e.v);
				ma=max(ma,e.wei);
			}
		}
		re=min(re,ma-mi);
		temp++;
	}
	
}
*/

int main()
{
	while(scanf("%d%d",&n,&m)&&(n!=0||m!=0))
	{
		ans=999999999;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].wei);
		}
		Kruskal();
		if(ans!=999999999)
		{
			printf("%d\n",ans);
		}
		else
		printf("-1\n");
	}
	return 0;
}
