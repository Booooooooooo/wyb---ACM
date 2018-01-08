#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct cow{
	int start;
	int end;
	int length;
};
bool cmp(cow a,cow b)
{
	if(a.start<b.start)
	return true;
	else return false;
}
bool cmp2(cow a,cow b)
{
	if(a.end<b.end)
	return true;
	else return false;
}
int main()
{
	int n,t;
	struct cow a[25005];
	while (scanf("%d%d",&n,&t)!=EOF)
	{
		int i,flag=1;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].start,&a[i].end);
		}
		sort(a,a+n,cmp);
		int j=0,cnt=1;
		int end=a[0].end;
		if(a[0].start!=1)
		flag =0;
		else 
		while (j!=(n-1))
		{
		
			
			for(i=j+1;i<n;i++)
			{
				if(a[i].start<=end+1)
				continue;
				else
				{
					i--;
					break;
				}
			}
			if(i=j)
			flag=0;
			else 
			{
				sort(a+j+1,a+i,cmp2);
				end = a[i].end;
				j=i;
				cnt++;
			}
			
		}
		if(end!=t)
		flag =0;
		if(flag)
		printf("%d\n",cnt);
		else 
		printf("-1\n");
		
	}
	return 0;
 }
