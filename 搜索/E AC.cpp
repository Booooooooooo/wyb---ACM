#include<stdio.h>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int hop[5][5],dis[1000000],cnt=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int r,int c,int cur,int step)
{
	if(step==6)
	{
		if(!dis[cur])
		{
			dis[cur]=1;
			cnt++;
		}
		return ;
	}
	for(int i=0;i<4;i++)
	{
		if(r+dx[i]<0||r+dx[i]>=5||c+dy[i]<0||c+dy[i]>=5)continue;//³¬³ö±ß½çµÄ 
		dfs(r+dx[i],c+dy[i],cur*10+hop[r+dx[i]][c+dy[i]],step+1);
	}
	
}
int main()
{
		int i,j;
		cnt=0;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				scanf("%d",&hop[i][j]);
		//memset(dis,0,sizeof(dis));
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				dfs(i,j,hop[i][j],1);
		printf("%d\n",cnt);
	return 0;
}
