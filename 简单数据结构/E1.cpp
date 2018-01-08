#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

struct node{
	int sat;
	int mon;
}cow[100005];

int n,c,f;

bool operator <(node a,node b)
{
	return a.mon>b.mon;
}

int mid[100005];
int solve()
{
	
	int sum=0;
	for(int i=0;i<c;i++)
	mid[i]=0x3f3f3f3f;
	
	for(int i=c-1-n/2;i>=n/2;i--)
	{
		sort(cow+i+1,cow+c-1,cmp2);
		//priority_queue <node> ql;
		//priority_queue <node> qr;
		sum=0;
		
		int mid=cow[i].sat;
		node temp;
		for(int j=0;j<i;j++)
		{
			ql.push(cow[j]);
		}
		for(int j=0;j<n/2;j++)
		{
			temp=ql.top();
			sum+=temp.mon;
			ql.pop();
		}
		for(int j=i+1;j<c;j++)
		{
			qr.push(cow[j]);
		}
		for(int j=0;j<n/2;j++)
		{
			temp=qr.top();
			sum+=temp.mon;
			qr.pop();
		}
		sum+=cow[i].mon;
		if(sum<=f)
		{
			return mid;
		}

	}
	return -1;
}

bool cmp1(node a,node b)
{
	return a.sat<b.sat;
}

bool cmp2(node a,node b)
{
	
	return a.mon<b.mon;
}
int main()
{
	while(scanf("%d%d%d",&n,&c,&f)!=EOF)
	{
		for(int i=0;i<c;i++)
		scanf("%d%d",&cow[i].sat,&cow[i].mon);
		sort(cow,cow+c,cmp1);
		int ans=solve();
		printf("%d\n",ans);
	}
	return 0;
}

