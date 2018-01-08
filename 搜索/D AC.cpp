#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int n,m,idx[25][25],cnt=0;
char room[25][25];
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
void dfs(int r,int c)//r––c¡– 
{
	if(r<0||r>=m||c<0||c>=n) return ;
	if(idx[r][c]==1||(room[r][c]!='.'&&room[r][c]!='@')) return ;
	idx[r][c]=1;
	cnt++;
	for(int k=0;k<4;k++)
			dfs(r+dr[k],c+dc[k]);
}
int main()
{
	scanf("%d%d",&n,&m);
	while(n!=0||m!=0)
	{
		int i,j,ik,jk;
		cnt=0;
		memset(idx,0,sizeof(idx));
		for(i=0;i<m;i++)
		scanf("%s",room[i]);
		for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					if(room[i][j]=='@')
					{
						ik=i;
						jk=j;
					}
				}
			}
		//for(i=0;i<m;i++)
			//for(j=0;j<n;j++)
				//if(idx[i][j]==0&&room[i][j]=='#')
		dfs(ik,jk);
		printf("%d\n",cnt);
		scanf("%d%d",&n,&m);	
	}
	return 0;
}
