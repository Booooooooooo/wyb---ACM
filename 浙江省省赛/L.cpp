#include<stdio.h>

int t,n;
int team[15];
int cnt;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		cnt=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&team[i]);
			if(team[i]>6000)
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
 } 
