#include<stdio.h>
#include<string>
#include<algorithm>
#include<set>
#include<queue>
//typedef char str[10];
using namespace std;
set <int> s;
queue<int> q;
int di[4]={-3,-1,1,3};//0可以移动的地方 
char u[4]={'u','l','r','d'};//对应的方向表示 
//string st,id;
queue<char>id;
char a[10],temp[10];

void itc(int b)//int转char【】 
{
	int i;
	for(i=8;i>=0;i--)
	{
		temp[i]=b%10;
		if(temp[i]=='0')
		temp[i]='x';
		b/=10;
		
	}
	
}
int cti(char b[])//将字符形式的数码 转换为int  
{
	int t=0,i,w=1;
	for(i=8;i>=0;i--)
	{
		switch(b[i])
		{
			case'1':t+=w*1;break;
			case'2':t+=w*2;break;
			case'3':t+=w*3;break;
			case'4':t+=w*4;break;
			case'5':t+=w*5;break;
			case'6':t+=w*6;break;
			case'7':t+=w*7;break;
			case'8':t+=w*8;break;
			case'x':t+=0;break;
		}
		w*=10;
	 } 
	return t;
 } 
void bfs()
{
	while(!q.empty()&&!s.count(123456780))
	{
		int pos;
		itc(q.front());
		for(int i=0;i<9;i++)
		{
			if(temp[i]=='x')
			{
				pos=i;
				break;
			}
		}
		for(int i=0;i<4;i++)
		{
			if(pos+di[i]<0||pos+di[i]>8)
			continue;
			swap(temp[pos],temp[pos+di[i]]);
			int k=cti(temp);
			q.push(k);
			s.insert(k);
			//id.push(u[i]);
		}
		q.pop();
	 } 
	 return ;
	/*string temp=a;
	char chr[]="12345678x";
	if(i<0||i>=9)return ;
	if(temp==chr) return;
	for(int k=0;k<4;k++)
	{
		swap(temp[i+di[k]],temp[i]);
		if(s.count(temp))continue;
		else {
			dfs(i+di[k],temp);
			q.push(u[k]);
		}
		
	}*/ 
}
int main()
{
	int i,pos;
	for(i=0;i<9;i++)
	{
		scanf("%c",&a[i]);
		//if(a[i]=='x')
		//pos=i;
	}
	//st=a;
//	dfs(pos,a);
	q.push(cti(a));
	int size=q.size();
	/*for(i=0;i<size;i++)
	{
		printf("%c",q.front());
		q.pop();
	}*/
	printf("\n");
	return 0;
}
