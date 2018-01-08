#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int l,n,m,rock[50005],dis[50005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	while(scanf("%d%d%d",&l,&n,&m)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		scanf("%d",&rock[i]);
		sort(rock,rock+n);
		for(i=1;i<=n-1-m;i++)
		{
			dis[mid]=rock[mid+m]-rock[mid];
		}
		sort(dis,dis+n,cmp);
		printf("%d\n",dis);
		/*int st=1,ed=n-1-m,mid;
		while(ed-st>1)
		{
			mid=st+(ed-st)/2;
			dis[mid]=rock[mid+m]-rock[mid];
		}*/
		}	
	return 0;
}
