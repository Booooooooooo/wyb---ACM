#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int c,l;
struct node{
	int min;
	int max;
}cow[2505];
struct po{
	int spf;
	int cov;
}loti[2505];

bool cmpc(node a,node b)
{
	return a.min<b.min;
}

bool cmpl(po a,po b)
{
	return a.spf<b.spf;
}
int main()
{
	//while(scanf("%d%d",&c,&l)!=EOF)
	//{
		scanf("%d%d",&c,&l);
		priority_queue <int> que;
		for(int i=0;i<c;i++)
		scanf("%d%d",&cow[i].min,&cow[i].max);
		sort(cow,cow+c,cmpc);
		for(int i=0;i<l;i++)
		scanf("%d%d",&loti[i].spf,&loti[i].cov);
		sort(loti,loti+l,cmpl);
		int j=0,ans=0;
		for(int i=0;i<l;i++)
		{
			//j=0;
			while(j<c&&cow[j].min<=loti[i].spf)
			{
				que.push(cow[j].max);
				j++;
			}
			while(!que.empty()&&loti[i].cov)
			{
				int temp=que.top();
				que.pop();
				if(temp<loti[i].spf)
				continue;
				ans++;
				loti[i].cov--;
			}
		}
		printf("%d\n",ans);
	//}
	return 0;
 } 
