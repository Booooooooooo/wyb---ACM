#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<set>
using namespace std;
char p[5][5];
int q[5][5],l[5][5];//p为输入的数组，q为操作的数组，idx为标记数组 
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int cnt=0;
set <long long> s;


void dfsr(int r,int c)
{
	if(r<0||r>=4||c<0||c>=4) return ;
	if(s.count(q)) return ;
	if(q==p) return ;
	cnt++;
	for(int dr=0;dr<4;dr++)
		{
			for(int dc=0;dc<4;dc++)
			{
				dfs(r+dx[dr],c+dy[dc]);
			}
		}
	q[r][c]='b';
	s.insert(q);
}

void dfsb(int r,int c)
{
	if(r<0||r>=4||c<0||c>=4) return ;
	if(s.count(q)) return ;
	if(q==l) return ;
	cnt++;
	for(int dr=0;dr<4;dr++)
		{
			for(int dc=0;dc<4;dc++)
			{
				dfs(r+dx[dr],c+dy[dc]);
			}
		}
	q[r][c]='r';
	s.insert(q);
}

int main()
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			{
				scanf("%c",&p[i][j]);
				if(p[i][j]=='r')
				l[i][j]=0;
				else 
				l[i][j]=1;
			}
	memset(q,0,sizeof(q));
	dfsr(0,0);
	int c1=cnt;
	memset(q,1,sizeof(q));
	dfsb(0,0);
	int c2=cnt;
	int ans=min(c1,c2);
	printf("%d\n",an);
	return 0;
}
