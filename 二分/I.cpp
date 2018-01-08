#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int water[100005],n,k;
int main()
{
	while (scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		scanf("%d",&water[i]);
		scanf("%d",&k);
		sort(water,water+n);
		int st=0;
		int ed=water[n-1]+1;
		int mid;
		while(ed>st+1)
		{
			int cnt=0;
			mid=st+(ed-st)/2;//mid表示所需要的时间 
			for(i=n-1;i>=0;i--)
			{
				if(water[i]>mid)
				{
					cnt+=water[i]/k;
					if(water[i]%k>=mid-cnt)
					{
						cnt++;
					}
					/*if(mid>cnt)
					{
						if(water[i]%k>=mid-cnt)
						{
							cnt++;
						}	
					}
					else 
					{
						break;
					}*/	
				}
				else if(water[i]==cnt)
				{
					break;
				}
				
			}
			if(mid>=cnt)
			ed=mid+1;
			else 
			st=mid-1;
		}
		printf("%d\n",mid);
	}
	return 0;
}
