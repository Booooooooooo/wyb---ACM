#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<set>
using namespace std;
set<int>s;
int di[4]={-3,-1,1,3};//0可以移动的地方 
char u[4]={'u','l','r','d'};//对应的方向表示
char a[10],temp[10];
stack<char> m;
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

void dfs()
{
	while	
}

int main()
{
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		
	}
	return 0;
 } 
