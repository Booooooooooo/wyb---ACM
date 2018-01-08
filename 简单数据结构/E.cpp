
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n,c;
long long f;

typedef struct {
	long long sat;
	int mon;
	double p;
}d;

d cow[100005];
bool operator < (d a,d b)
{
	if(a.sat<b.sat)
	return 1;
	else if(a.sat==b.sat)
	return a.mon<b.mon;
	//return a.sat<b.sat;
}

void solve()
{
	priority_queue <d> que;
	for(int i=0;i<c;i++)
	que.push(cow[i]);
	d temp;
	for(int i=0;i<n/2+1;i++)
	{
		temp=que.top();
		que.pop();
		f-=temp.mon;
	}
	if(f<0)
	printf("-1\n");
	else
	printf("%lld\n",temp.sat);
	
}

int main()
{
	while(scanf("%d%d%lld",&n,&c,&f)!=EOF)
	{
		for(int i=0;i<c;i++)
		{
			scanf("%d%d",&cow[i].sat,&cow[i].mon);
		//	cow[i].p=cow[i].sat/cow[i].mon;
		}
		solve();
	}
	return 0;
 } 
 
