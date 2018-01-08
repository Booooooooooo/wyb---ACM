#include<stdio.h>
#include<malloc.h>
int main()
{
	int t,n,*x,q,*m,i,j,cnt=0;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		x=(int *)malloc(sizeof(int)*n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x[i]);
		}
		scanf("%d",&q);
		m=(int *)malloc(sizeof(int)*q);
		for(i=0;i<q;i++)
		{
			scanf("%d",&m[i]);
		}
		for(i=0;i<q;i++)
		{
			for(j=0;j<n;j++)
			{
				if(m[i]>=x[j])
				cnt++;
			}
			printf("%d\n",cnt);
			cnt=0;
		}
	}
	return 0;
}
