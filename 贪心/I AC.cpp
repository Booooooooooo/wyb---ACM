#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct hw{
	int dead;
	int score;
};
bool cmp(hw a,hw b)
{
	if (a.score != b.score)  
        return a.score > b.score;  
    else return a.dead < b.dead;
}
int main()
{
	int t;
	struct hw a[1005];
	scanf("%d",&t);
	while (t--)
	{
		int i,n,v[1005];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			v[i]=0;
			scanf("%d",&a[i].dead);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i].score);
		}
		sort(a,a+n,cmp);
		int ans=0;
		for(i=0;i<n;i++)
		{
			int j=a[i].dead-1;
			for(;j>=0;j--)
			{
				if(!v[j])
				{
					v[j]=1;
					break;
				}
			}
			if(j==-1)
			{
				ans+=a[i].score;
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}
