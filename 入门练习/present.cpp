#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,*pre,i,cnt;
	while (scanf("%d",&n)&&n!=0)
	{
		cnt=1;
		pre=(int*)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&pre[i]);
		}
		sort(pre,pre+n);
		for(i=0;i<n;i++)
		{
			if(i==n)
			{
				if(pre[i]!=pre[i-1])
				printf("%d\n",pre[i]);
				else cnt++;
			}
			else
			{
				if(pre[i]==pre[i+1])
			{
				cnt++;
			}
			else if(cnt%2==1)
			{
				printf("%d\n",pre[i]);
				cnt=1;
				break;
			}
			if(pre[i]!=pre[i+1]&&cnt%2==0)
				cnt=1;
			}
			
		}
	}
	return 0;
}
