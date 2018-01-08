#include<stdio.h>
#include<algorithm>
#include<stdio.h>
#include<cstring>
#include<map>
#include<iostream>
#include<set>

using namespace std;

int g,t;
string wor;
char sch[7][25][20];

int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int ans=9999999,cnt=0;
		scanf("%d",&g);
		cin>>wor;
		for(int j=0;j<6;j++)
		{
			for(int k=0;k<20;k++)
			cin>>sch[j][k];
		}
		int x,y;
		set<string> v;

		for(y=0;y<=g;y++)
		{
			int flag=1;
			x=g-y;
			for(int j=0;j<20;j++)
			{
				if(x==0)
				break;
				for(int k=0;k<5;k++)
				{
					if(x==0)
					break;
				//	string temp=sch[j][k];
					if(v.count(sch[k][j]))
					continue;
					else
					{
						if(sch[k][j]==wor)
						{
							cnt++;
							flag=0;
						}
						x--;
						v.insert(sch[k][j]);
					}
				}
			}
			int temp=y;
			for(int j=0;j<20;j++)
			{

				if(y==0)
				break;
				if(v.count(sch[5][j]))
				continue;
				else
				{
					if(sch[5][j]==wor)
					{
						flag=0;
						cnt++;
					}
					y--;
					v.insert(sch[5][j]);
				}

			}
			if(flag)
			ans=min(ans,temp);

		}


		if(cnt==g)
		printf("Case #%d: ADVANCED!\n",i);
		else
		printf("Case #%d: %d\n",i,ans);


	}
	return 0;
 }
