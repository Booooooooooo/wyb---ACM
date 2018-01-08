#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int n,now,fuel;
//int dis[10005],val[10005];
struct s  
{  
    int dis;  
    int val;  
}stop[10005];  
bool cmp(s a, s b)  
{  
    return a.dis < b.dis;  
}  
void solve()
{
	priority_queue<int> que;
	int ans=0,pos=0;
	
	for(int i=0;i<n+1;i++)
	{
		stop[n].dis =now;
		stop[n].val =0;
		int d=stop[i].dis-pos;
		while(fuel-d<0)
		{
			if(que.empty())
			{
				printf("-1\n");
				return ;
			}
			fuel+=que.top();
			que.pop();
			ans++;
		}
		fuel-=d;
		pos=stop[i].dis;
		que.push(stop[i].val);
	}
	printf("%d\n",ans);
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i,flag=1,cnt=0;
		for(i=0;i<n;i++)
		scanf("%d%d",&stop[i].dis,&stop[i].val);
		//stop[n+1].dis=0;
		scanf("%d%d",&now,&fuel);
		for(i=0;i<n;i++)
		stop[i].dis=now-stop[i].dis;
		sort(stop,stop+n+1,cmp);
		//now=stop[0].dis;
		//fuel=stop[0].val;
		solve();
		/*for(i=1;i<n+1;)//最大限度可以走到哪里//照这个方法把找到的stop放入栈 当无法到达下一个点时就弹出将前一个放入栈//递归 
		{
			if(now-stop[i+1].dis>fuel&&now-stop[i+1].dis<=fuel+stop[i].val)
			{
				fuel+=stop[i].val-now+stop[i].dis;
				now=stop[i].dis;
				i++;
				cnt++;
			}
			else if(now-stop[i+1].dis>fuel+stop[i].val)
			{
				flag=0;
				break;
				
			}
			else 
			{
				i+=2;
			}
		}
		if(flag)
		printf("%d\n",cnt);
		else 
		printf("-1\n");*/
	}	
 } 
