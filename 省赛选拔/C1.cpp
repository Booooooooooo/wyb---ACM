#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n,t;
int book[100005],num[100005];

int main()
{
	while(scanf("%d%d",&n,&t)!=EOF)
	{
		long long time=0;
		for(int i=1;i<n+1;i++)
		{
			scanf("%d",&book[i]);
			num[i]=0;
		}
		int flag=0;
		for(int i=1;i<n+1;i++)
		{
			int j;
			flag=0;
			time =0;
			for(j=i;j<n+1;j++)//从第i本开始读 
			{
				time+=book[j];
				if(time>t)
				{
					num[i]=j-i;
					break;
				}
				else if(j==n)
				num[i]=j+1-i;
				//if(time<=t&&j==n)
				
			}
			
			/*if(j==n+1&&!flag) 
			{
				printf("%d\n",n-i+1);
				break;
			}*/
		}
		sort(num+1,num+n+1);
		printf("%d\n",num[n]);
	}
}
