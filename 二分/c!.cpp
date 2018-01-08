#include<iostream>
#include<algorithm>
using namespace std;
int n,c,dis[100005];
/*bool key(int d)
{
	int last=0;
	for(int i=1;i<c;i++)
	{
		int crt=last +1;
		while(crt<n&&dis[crt]-dis[last]<d)
		{
			crt++;
		}
		if(crt==n)
		return false;
		last=crt;
	}
	return true;
}*/
bool ok(int m)
{
	int last=0;
	for(int i=1;i<c;i++)
	{
		int cur=last+1;
		while(cur<n&&dis[cur]-dis[last]<m)
			cur++;
		if(cur==n)
			return false;
		last =cur;
	}
	return true;
}
int main()
{
	int n,c,dis[100005];
	while (scanf("%d%d",&n,&c)!=EOF)
	{
		int i,crt;
		for(i=0;i<n;i++)
		scanf("%d",&dis[i]);
		sort(dis,dis+n);
		int st,ed,mid;
		st=dis[0];
		ed=dis[n-1];
		//for(i=0;i<100;i++)
		while(ed-st>1)
		{
			mid=st+(ed-st)/2;
			if(ok(mid))
			st=mid;
		else ed=mid;
		}
		printf("%d\n",st);
	}
	return 0;
 } 
