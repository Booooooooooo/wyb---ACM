#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,cnt=0,i,j,flag=1;
	scanf("%d",&t);
	while(t--)
	{
		if(n==1)
		cnt=0;
		else if(n==2)
		cnt=1;
		else if(n==3)
		cnt=2;
		else
		{
			cnt=2;
		scanf("%d",&n);
		for(i=5;i<=n;i+2)
		{	
			flag=1;
			for(j=3;j<=pow(i,0.5);j++)
			{
				if(i%j==0)
				{
				flag=0;
				break;
				}
			}
			if(flag)
			cnt++;
		}
		}

		printf("%d\n",cnt);
	}
	return 0;
}
