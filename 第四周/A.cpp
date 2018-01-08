#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct domin{
	int up;
	int low;
}a[105];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i,su=0,sl=0,cnt=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].up,&a[i].low);
			su+=a[i].up;
			sl+=a[i].low;
		}
		if(su%2==0&&sl%2==0)
		{
			printf("0\n");
			continue;
		}
		if(su%2==0&&sl%2==1)
		{
			printf("-1\n");
			continue;
		}
		if(sl%2==0&&su%2==1)
		{
			printf("-1\n");
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(a[i].up%2&&a[i].low%2==0)
			{
				cnt=1;
				break;
			}
			else if(a[i].up%2==0&&a[i].low%2)
			{
				cnt=1;
				break;
			}
		}
		if(i==n&&cnt==0)
		printf("-1\n");
		else 
		printf("%d\n",cnt);
	}
	return 0;
 }
