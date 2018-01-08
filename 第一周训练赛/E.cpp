#include<stdio.h>
int main()
{
	int n,a[100005];
	while (scanf("%d",&n)!=EOF)
	{
		int i,cnt=0,flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(i==a[i])
			cnt++;
			else if(a[a[i]]==i&&flag!=1)
			{
				cnt+=2;
				flag =1;
			}
		}
		if(flag!=1&&cnt!=n)
		{
			cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
