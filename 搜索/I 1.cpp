#include<iostream>
#include<queue>
#include<stdio.h>
#include<cstring>

using namespace std;

int flag=1,id;

void bfs()
{
	int vis[65536]={0},step[65536]={0},temp;
	queue<int> q;
	if(id==0||id==65535)
	{
		printf("0\n");
		flag=0;
		return ;
	}
	vis[id]=1;
	step[id]=0;
	q.push(id);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		id=temp;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				temp=id;
				//将第ij个上下的进行翻转 
				if(i==0)
					temp^=1<<(11-j);//翻的是第一行的 
				else if(i==3)
					temp^=1<<(7-j);//翻的是最后一行的
				else //在中间 
				{
					temp^=1<<(11-4*i-j);//翻它下面一行的
					temp^=1<<(19-4*i-j);//翻他上面一行的 
				 } 
				//将第ij个左右的以及自己进行翻转 
				if(j==0)
					temp^=3<<(14-4*i);//在最左边，只能翻他右边的
				else if(j==3) //在最右边，只能翻他左边的
					temp^=3<<(12-4*i);
				else 
					temp^=7<<(14-4*i-j);//可以翻三个
				
				if(temp==0||temp==65535)
				{
					printf("%d\n",step[id]+1);
					flag=0;
					return ;
				 } 
				if(!vis[temp])
				{
					step[temp]=step[id]+1;
					vis[temp]=1;
					q.push(temp);
				}
			}
	}
}

int main()
{
	char ch;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			cin>>ch;
			//scanf("%c",&ch);
			id<<=1;
			if(ch=='b')
				id+=1;
		 } 
	bfs();
	if(flag)
		printf("Impossible\n");
		return 0;
}
