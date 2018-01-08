#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

const int INF=1000000009;
using namespace std;

int n,m;
int dis[605][605],cow[605];

void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<606;i++) 
		{
			for(int j=0;j<606;j++)
			dis[i][j]=999999999;
		}
		//memset(dis,INF,sizeof(dis));
		for(int i=0;i<m;i++)
		{
			int c;
			scanf("%d",&c);
			for(int j=0;j<c;j++)
			scanf("%d",&cow[j]);
			
			for(int j=0;j<c;j++)
			{
				for(int k=0;k<j;k++)
				{
					int a=cow[j];
					int b=cow[k];
					dis[a][b]=1;
					dis[b][a]=1;
				}
				
				
			}
		}
		floyd();
		int ans=999999999;
		for(int i=1;i<=n;i++)
		{
 		 		int sum=0;
				for(int j=1;j<=n;j++)
		   {		
				if(i!=j)
				sum+=dis[i][j];
		   }
		   ans=min(sum,ans);
	    }
		printf("%d\n",(int)(ans*100/(n-1)));
	}
	
	
	return 0;
}
