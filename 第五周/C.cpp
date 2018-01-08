#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;
int n,l,r,ql,qr;
int w[100005];
int main()
{
	while(scanf("%d%d%d%d%d",&n,&l,&r,&ql,&qr)!=EOF)
	{
		int i,aa,bb;
		for(i=0;i<n;i++)
		{
			scanf("%d",&w[i]);
		}
		int flag=1;
		
		//左手开始
		aa=l*w[0];
		for(i=1;i<n;i++)
		{
			if(flag==1)
			{
				if(l*w[i]+ql<r*w[i])
				{
					aa+=l*w[i]+ql;
				}
				else 
				{
					aa+=r*w[i];
					flag=0;
				}
			}
			else 
			{
				if(r*w[i]+qr<l*w[i])
				{
					aa+=r*w[i]+qr;
				}
				else 
				{
					aa+=l*w[i];
					flag=1;
				}
			}
		 } 
		 
		//右手开始 
		flag=0;
		bb=r*w[0];
		for(i=1;i<n;i++)
		{
			if(flag==1)
			{
				if(l*w[i]+ql<r*w[i])
				{
					bb+=l*w[i]+ql;
				}
				else 
				{
					bb+=r*w[i];
					flag=0;
				}
			}
			else 
			{
				if(r*w[i]+qr<l*w[i])
				{
					bb+=r*w[i]+qr;
				}
				else 
				{
					bb+=l*w[i];
					flag=1;
				}
			}
		}
		
		int an=min(aa,bb);
		printf("%d\n",an);
	}
	return 0;
}
