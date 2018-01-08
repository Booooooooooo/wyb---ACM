#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

int t,s,m,d;
struct dish{
	char name[55];
	int cost;
}app[105],ma[105],dess[105];


bool cmp(dish a,dish b)
{
	return a.cost<b.cost;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int ai,mi,di;
		scanf("%d%d%d",&s,&m,&d);
		for(int i=0;i<s;i++)
		scanf("%s%d",app[i].name,&app[i].cost);
		sort(app,app+s,cmp);
		ai=s/2;
		for(int i=0;i<m;i++)
		scanf("%s%d",ma[i].name,&ma[i].cost);
		sort(ma,ma+m,cmp);
		mi=m/2;
		for(int i=0;i<d;i++)
		scanf("%s%d",dess[i].name,&dess[i].cost);
		sort(dess,dess+d,cmp);
		di=d/2;
		
		int ans=app[ai].cost+ma[mi].cost+dess[di].cost;
		printf("%d %s %s %s\n",ans,app[ai].name,ma[mi].name,dess[di].name);
		
	}
	return 0;
 } 
