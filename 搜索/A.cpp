#include<stdio.h>
#include<iostream>
#include<queue>
#include<string>
using namespace std;
char x[2],y[2];
int dx[8]={-2,-1,1,2,2,1,-1,-2};//����ı仯Ϊx 
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
		while((vis+y[0]-97)[y[1]]==0)//ֱ���ߵ����λ�ý���  ���ѣ������ѵ��ľ��ǲ������ٵ� 
		{
			x=q.top();
			q.pop();
			for(i=0;i<8;i++)
			{
				if(!vis[x[0]-97+dy[i]][x[1]+dy[i]])////////����Ҫ�� ��һ�ֱ������ı�ʾ��ʽ ��Ȼ�ᳬ���߽� 
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
