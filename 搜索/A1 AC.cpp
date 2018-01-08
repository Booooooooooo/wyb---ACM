#include<stdio.h>
#include<iostream>
#include<set>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
char st[10],ed[10];
int dx[10]={-2,-1,1,2,2,1,-1,-2};//横向的变化为x 
int dy[10]={-1,-2,-2,-1,1,2,2,1};
int vis[15][15]={0};//标记数组 
typedef struct{
	int x;
	int y;
	int step;
}node;

int nx,ny;
int s,an;
int bfs()
{
	queue<node>q;
	node a;
	node temp,t;
	vis[st[0]-'a'][st[1]-'1']=1;
	a.x=st[0]-'a';
	a.y=st[1]-'1';
	a.step=0;
	q.push(a);
	while(!q.empty())
	{
		
		
		temp=q.front();
		q.pop();
		//nx=temp.x;
		//ny=temp.y;
		
		s=temp.step;
		if(temp.x==ed[0]-'a'&&temp.y==ed[1]-'1')
		return s;
		for(int i=0;i<8;i++)
		{
			nx=temp.x+dx[i];
			ny=temp.y+dy[i];
			if(nx<0||nx>=8||ny<0||ny>=8||vis[nx][ny])//超出边界 
			continue;
			if(nx==ed[0]-'a'&&ny==ed[1]-'1')
			return s+1;
			vis[nx][ny]=1;
			t.x=nx;
			t.y=ny;
			t.step=s+1;
			q.push(t);
		}
		
	}
}
int main()
{
	
	while(scanf("%s%s",st,ed)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		//while(!q.empty())
		//q.pop();
		
		an=bfs();
		//cout<<"To get from "<<st[0]<<st[1]<<" to "<<ed<<" takes "<<an<<" knights moves."<<endl;
		///cout<<st;
	
		printf("To get from %s to %s takes %d knight moves.\n",st,ed,an);
		
	}
	return 0;
 } 
