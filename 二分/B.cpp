#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n,k;
	double ca[10005];
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		int i;
		long long cnt=0;
		for(i=0;i<n;i++)
		{
			cin>>ca[i];
			ca[i]+=0.000001;
		}
		sort(ca,ca+n);
		double ed,st,mid;
		st=0.00;
		ed=ca[n-1];
		while((ed-st)>1e-8)
		{
			cnt=0;
			mid=st+(ed-st)/2;
			for(i=0;i<n;i++)
			{
				cnt+=(int)(ca[i]/mid);
			}
			if(cnt>=k)
			st=mid;
			else if(cnt<k)
			ed=mid;
		}
		if(mid<0.01)
		printf("0.00\n");
		else
		printf("%.2f\n",floor(mid*100)/100);
	}
	return 0;
}
