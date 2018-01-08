#include<stdio.h>
#include<queue>
#include<iostream>

using namespace std;

int n,len[20005];
long long ans=0;
void solve()
{
	
	priority_queue<long long,vector<long long>,greater<long long> >que;
	for(int i=0;i<n;i++)
	{
		que.push(len[i]);
	}
	while(que.size()>1)
	{
		int l1,l2;
		l1=que.top();
		que.pop();
		l2=que.top();
		que.pop();
		ans+=l1+l2;
		que.push(l1+l2);
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&len[i]);
		}
		solve();
		printf("%lld\n",ans);
	}
	return 0;
}
