#include<stdio.h>
int main()
{
	int t,n,i,j,flag=0;
	scanf("%d",&t);
	while (t--)
	{
		flag=0;
		scanf("%d",&n);
		for(i=1;i<n/2;i++)
		{
			if(flag ==1)
			break;
			else
			{
			for(j=i;j<n/2;j++)
			{
				if(2*n==i*(i+1)+j*(j+1))
				{
					printf("Yes\n");
					flag=1;
					break;
				}
			}
			}
		}
		if(!flag)
		printf("No\n");
	}
	return 0;
}
