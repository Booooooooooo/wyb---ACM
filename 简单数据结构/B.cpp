#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n,len[20005];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		long long temp,ans=0;
		priority_queue<int>que;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&len[i]);
			que.push(len[i]);
			ans+=len[i];
		}
		temp=ans;
		long long l;
		while(que.size()>2)
		{
			l=que.top();
			que.pop();
			temp-=l;
			ans+=temp;
		}
		printf("%d\n",ans);
	}
	return 0;
}
