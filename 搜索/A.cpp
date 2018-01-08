#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
char x[2],y[2];
int dx[8]={-2,-1,1,2,2,1,-1,-2};//横向的变化为x 
int dy[8]={-1,-2,-2,-1,1,2,2,1};
int vis[10][10]={0};

int main()
{
	while(scanf("%s%s",x,y)!=EOF)
	{
		int i,cnt=0;
		queue<int>q;
		for(i=0;i<10;i++)
		{
			
			for(int j=0;j<10;j++)
			vis[i][j]=0;
		}
		while((vis+y[0]-97)[y[1]]==0)//直到走到这个位置结束  宽搜，最先搜到的就是步数最少的 
		{
			x=q.top();
			q.pop();
			for(i=0;i<8;i++)
			{
				if(!vis[x[0]-97+dy[i]][x[1]+dy[i]])////////这里要改 换一种标记数组的表示方式 不然会超出边界 
				vis[x[0]-97+dy[i]][x[1]+dy[i]]=1;
				q.push(x[0]+dy[i])
			}
			q.pop();
			cnt++;
		}
		printf("To get from %s to %s takes %d knight moves\n",x,y,cnt);
	}
	return 0;
 } 
